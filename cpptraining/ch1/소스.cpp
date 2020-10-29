// ���ø��� �̿��Ͽ� ����ũ�� ����Ʈ �����ϱ�

#include<iostream>
using namespace std;

template<typename T>
class CListNode {
	// �����ڿ� �Ҹ��ڸ� private���� �ϰ� �Ǹ� �ܺο��� ��ü�� �����ϰ� ��ü�� ������ �� ����.
	// �����ڴ� ��ü�� ������ �� �ڵ����� ȣ���� �Ǵ� �Լ��ε� private���� �Ǹ�ˤ� ��ü�� �����ϸ鼭 ȣ�� �� ������ �Ұ����ϴ�.
private:
	CListNode() :
		m_pNext(NULL),
		m_pPrev(NULL) {
	}
	~CListNode() {
	}

private:
	// friend�� �������� Ŭ�������� �� Ŭ������ private�̳� protected�� ������ ����������.
	// �Ϲ� Ŭ������ friend ���θ� ������ ������ template Ŭ������ ��� �Ʒ�ó�� template�� ������ �־�� �Ѵ�.
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

	// ������
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
	// ���۷����� �����ϴ� ����� ���� ������ �� �ִ�. const�� �ٿ��ָ� �����ϴ� ����� ���� ������ �� ����.
	void push_back(const T& data) {
		PNODE pNode = new NODE;

		pNode->m_Data = data;
		// End�� ���� ��尡 ���� ������ ���.
		PNODE pPrev = m_pEnd->m_pPrev;

		// ����
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

		// ����
		pFirst->m_pPrev = pNode;
		pNode->m_pNext = pFirst;

		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_iSize;
	}

	// ����Լ� �ڿ� const�� �ٿ��ָ� �� �Լ� ������ ��������� ���� ������ �� ����.
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