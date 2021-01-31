// Date : 2021.01.03
// Dev  : Hyeon Myeong Jang
/*
설계

Define
- 단순한 단방향 연결리스트
- Data와 Next Pointer로 구성
Operation
- Initialization
- Destruction
- InsertNext
- DeleteNext
- Iteration & Retrieval
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

typedef void* POS;

template<class TYPE>
class LinkedList {
public:
	enum Exception {
		INVALID_POS, EMPTY_LIST
	};
protected:
	struct Node {
		TYPE data;
		Node* pNext;
	};
	Node* m_pNodeHead;
	Node* m_pNodeTail;
	int m_count;

private:
	TYPE data;	
	Node *pNext;

private:
	void RemoveAll();
public:
	LinkedList();
	virtual ~LinkedList();
	
	TYPE RemoveHead();

	POS InsertNext(POS pos, const TYPE& newElem);
	TYPE DeleteNext(POS pos);

	POS GetHead();
	POS GetTail();

	int GetCount();
};

template<class TYPE>
LinkedList<TYPE>::LinkedList() {
}

template<class TYPE>
LinkedList<TYPE>::~LinkedList() {
	RemoveAll();
	if (m_pNodeHead)
		delete m_pNodeHead;
	if (m_pNodeTail)
		delete m_pNodeTail;
	m_pNodeHead = m_pNodeTail = NULL;
	m_count = 0;
}

template<class TYPE>
void LinkedList<TYPE>::RemoveAll()
{
	int count = GetCount();
	for (int i = 0; i < count; ++i)
		RemoveHead();
}

template<class TYPE>
TYPE LinkedList<TYPE>::RemoveHead()
{

	return DeleteNext(m_pNodeHead);
}

template<class TYPE>
POS LinkedList<TYPE>::GetHead()
{
	if(m_pNodeHead == nullptr)
		return NULL:
	else 
	return NULL;
}

template<class TYPE>
POS LinkedList<TYPE>::GetTail()
{
	return NULL;
}

template<class TYPE>
int LinkedList<TYPE>::GetCount() {
	return m_count;
}


template<class TYPE>
POS LinkedList<TYPE>::InsertNext(POS pos, const TYPE& newElem) {
	Node *pNode = (Node*)pos;
	if (pNode == nullptr) return 0; // 끝에 다다랐을 경우
	if (pNode == m_pNodeTail) return 0;

	Node *pNewNode = new Node;
	pNewNode->data = newElem;
	pNewNode->pNext = pNewNode;
	++m_count;

	return pNewNode;
}

template<class TYPE>
TYPE LinkedList<TYPE>::DeleteNext(POS pos) {
	Node *pNode = (Node*)pos;
	if (pNode == nullptr)
		throw INVALID_POS;
	if (pNode->pNext == m_pNodeTail)
		throw INVALID_POS;

	Node *pNodeDel = pNode->pNext;

	TYPE data = pNodeDel->data;

	pNode->pNext = pNode->pNext->pNext;
	delete pNodeDel;
	--m_count;
	return data;
}

int main() {
	LinkedList<int> l;
	try {
		l.GetHead();
	}
	catch (LinkedList<int>::Exception e) {
		if(e == LinkedList<int>::INVALID_POS)
			cout << "catched, invalid pointer %d\n" << e;
		else if(e == LinkedList<int>::EMPTY_LIST)
			cout << "catched, empty list %d\b" << e;
	}

	return 0;
}