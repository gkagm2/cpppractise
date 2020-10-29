// 템플릿을 이용하여 더블링크드 리스트 구현하기

#include<iostream>
using namespace std;

template<typename T>
class CListNode {
	// 생성자와 소멸자를 private으로 하게 되면 외부에서 객체를 생성하고 객체를 해제할 수 없다.
	// 생성자는 객체를 생성할 때 자동으로 호출이 되는 함수인데 private으로 되며ㅛㄴ 객체를 생성하면서 호출 시 접근이 불가능하다.
private:
	CListNode() :
		m_pNext(NULL),
		m_pPrev(NULL) {
	}
	~CListNode() {
	}

private:
	// friend로 지정해준 클래스에서 이 클래스의 private이나 protected에 접근이 가능해진다.
	// 일반 클래스는 friend 라인만 적으면 되지만 template 클래스의 경우 아래처럼 template을 지정해 주어야 한다.
	template<typename T>
	friend class CLinkedList;
	template<typename T>
	friend class CListIterator;

private:
	T m_Data;
	CListNode<T>* m_pNext;
	CListNode<T>* m_pPrev;
};


template <typename T>
class CListIterator {
public:
	CListIterator() {

	}
	~CListIterator() {

	}

private:
	template <typename T>
	friend class CLinkedList;
private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE m_pNode;

public:


	bool operator ==(const CListIterator<T>& iter) {
		return m_pNode == iter.m_pNode;
	}

	bool operator !=(const CListIterator<T>& iter) {
		return m_pNode != iter.m_pNode;
	}

	void operator ++() {
		m_pNode = m_pNode->m_pNext;
	}

	void operator --() {
		m_pNode = m_pNode->m_pPrev;
	}

	// 역참조
	T operator *() {
		return m_pNode->m_Data;
	}
};


template <typename T>
class CLinkedList {
public:
	CLinkedList() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}
	~CLinkedList() {
		clear();
		delete m_pBegin;
		delete m_pEnd;
	}

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

public:
	typedef CListIterator<T> iterator;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	// 레퍼런스는 참조하는 대상의 값을 변경할 수 있다. const를 붙여주면 참조하는 대상의 값을 변경할 수 없다.
	void push_back(const T& data) {
		PNODE pNode = new NODE;

		pNode->m_Data = data;
		// End의 이전 노드가 가장 마지막 노드.
		PNODE pPrev = m_pEnd->m_pPrev;

		// 연결
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		m_pEnd->m_pPrev = pNode;
		pNode->m_pNext = m_pEnd;

		++m_iSize;
	}

	void push_front(const T& data) {
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		PNODE pFirst = m_pBegin->m_pNext;

		// 연결
		pFirst->m_pPrev = pNode;
		pNode->m_pNext = pFirst;

		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_iSize;
	}

	// 멤버함수 뒤에 const를 붙여주면 이 함수 내에서 멤버변수의 값을 변경할 수 없다.
	unsigned int size() const {
		return m_iSize;
	}

	bool is_empty() const {
		return m_iSize == 0;
	}

	void clear() {
		PNODE pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd) {
			PNODE nextNode = pNode->m_pNext;
			delete pNode;
			pNode = nextNode;
		}

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_iSize = 0;
	}

	iterator begin() {
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}

	iterator end() {
		iterator iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}
};


int main() {
	CLinkedList<int> listInt;
	CLinkedList<float> listFloat;

	for (int i = 0; i < 100; ++i) {
		listInt.push_back(i + 1);
	}

	cout << listInt.size() << endl;

	CLinkedList<int>::iterator iter;

	for (iter = listInt.begin(); iter != listInt.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}