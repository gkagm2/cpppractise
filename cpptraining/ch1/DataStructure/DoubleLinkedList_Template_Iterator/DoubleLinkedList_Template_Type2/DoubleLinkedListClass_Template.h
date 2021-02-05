#pragma once
#include<cassert>
template<typename T>
struct Node {
	T data;
	Node* prevLink;
	Node* nextLink;
};

template<typename T>
class CDoubleLinkedList {
private:
	int m_Count;

protected:
	Node<T>* m_pNodeHead;
	Node<T>* m_pNodeTail;
	Node<T>* CreateNode(const T& _data);

private:
	inline bool IsLeftToRightSearch(int _idx) { return m_Count / 2 < _idx; } 

public:
	CDoubleLinkedList();
	virtual ~CDoubleLinkedList();

	void DeleteAll();
	[[deprecated]] void DeleteAt(int _idx);
	void PushBack(const T& _data);
	void PushFront(const T& _data);
	bool Search(const T& _data);
	bool IsEmpty();
	const int Size();
	void Print();
	const T& At(int _idx);
	T& operator[] (int _idx);

public:
	class iterator {
	private:
		CDoubleLinkedList* mOwner;
		Node<T>* mTargetNode;

	public:
		iterator(const iterator& _iter);
		iterator(CDoubleLinkedList* _pOwner, Node<T>* _targetNode);
		virtual ~iterator();

		int& operator*();

		iterator& operator++(); //  pre order
		iterator operator++(int); // post order
		iterator& operator--();
		iterator operator--(int);
		bool operator!=(const iterator& _iter);
		bool operator==(const iterator& _iter);
	public:
		friend class CDoubleLinkedList;
	};

public:
	iterator begin() { return iterator(this, m_pNodeHead); }
	iterator end() { return iterator(this, m_pNodeTail->nextLink); }
	iterator Erase(iterator& _iter);
};

template<typename T>
void CDoubleLinkedList<T>::DeleteAll()
{
	Node<T>* pIterNode = m_pNodeHead;
	while (pIterNode != nullptr) {
		Node<T>* pTempNode = pIterNode;
		pIterNode = pIterNode->nextLink;
		delete pTempNode;
	}
	m_pNodeHead = nullptr;
	m_pNodeTail = nullptr;
	m_Count = 0;
}

template<typename T>
void CDoubleLinkedList<T>::DeleteAt(int _idx)
{
	if (_idx < 0 || _idx >= m_Count || m_Count == 0)
		throw::std::out_of_range("");

	Node<T>* pDelNode = nullptr;
	int moveCnt;
	if (IsLeftToRightSearch(_idx)) {
		pDelNode = m_pNodeHead;
		moveCnt = _idx;
	}
	else {
		pDelNode = m_pNodeTail;
		moveCnt = m_Count - 1 - _idx;
	}
	for (int i = 0; i < moveCnt; ++i)
		pDelNode = IsLeftToRightSearch(_idx) ? pDelNode->nextLink : pDelNode->prevLink;

	if (pDelNode->prevLink == nullptr)
		m_pNodeHead = pDelNode->nextLink;
	if (pDelNode->nextLink == nullptr)
		m_pNodeTail = pDelNode->prevLink;

	pDelNode->prevLink->nextLink = pDelNode->nextLink;
	pDelNode->nextLink->prevLink = pDelNode->prevLink;
	delete pDelNode;

	--m_Count;
}

template<typename T>
Node<T>* CDoubleLinkedList<T>::CreateNode(const T & _data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = _data;
	newNode->nextLink = nullptr;
	newNode->prevLink = nullptr;
	return newNode;
}

template<typename T>
CDoubleLinkedList<T>::CDoubleLinkedList() :
	m_Count(0),
	m_pNodeHead(nullptr),
	m_pNodeTail(nullptr)
{
}

template<typename T>
CDoubleLinkedList<T>::~CDoubleLinkedList()
{
	DeleteAll();
}

template<typename T>
void CDoubleLinkedList<T>::PushBack(const T& _data)
{
	Node<T>* pNewNode = CreateNode(_data);
	if (m_pNodeHead == nullptr)
		m_pNodeTail = m_pNodeHead = pNewNode;
	else {
		m_pNodeTail->nextLink = pNewNode;
		pNewNode->prevLink = m_pNodeTail;
		m_pNodeTail = pNewNode;
	}
	++m_Count;
}

template<typename T>
void CDoubleLinkedList<T>::PushFront(const T& _data)
{
	Node<T> *pNewNode = CreateNode(_data);
	if (m_pNodeHead == nullptr)
		m_pNodeTail = m_pNodeHead = pNewNode;
	else {
		m_pNodeHead->prevLink = pNewNode;
		pNewNode->nextLink = m_pNodeHead;
		m_pNodeHead = pNewNode;
	}
	++m_Count;
}

template<typename T>
bool CDoubleLinkedList<T>::Search(const T & _data)
{
	Node<T>* pIterNode = m_pNodeHead;
	while (pIterNode != nullptr) {
		if (pIterNode->data == _data)
			return true;
		pIterNode = pIterNode->nextLink;
	}
	return false;
}

template<typename T>
bool CDoubleLinkedList<T>::IsEmpty()
{
	return m_Count > 0;
}

template<typename T>
const int CDoubleLinkedList<T>::Size()
{
	return m_Count;
}

template<typename T>
void CDoubleLinkedList<T>::Print()
{
	Node<T>* pIterNode = m_pNodeHead;
	while (pIterNode != nullptr) {
		std::cout << pIterNode->data << "->";
		pIterNode = pIterNode->nextLink;
	}
}

template<typename T>
const T & CDoubleLinkedList<T>::At(int _idx) {
	if (_idx < 0 || _idx >= m_Count || m_Count == 0)
		throw::std::out_of_range("");

	int moveCnt = IsLeftToRightSearch(_idx) ? _idx : m_Count - 1 - _idx;
	Node<T>* pIterNode = IsLeftToRightSearch(_idx) ? m_pNodeHead : m_pNodeTail;
	for (int i = 0; i < moveCnt; ++i)
		pIterNode = IsLeftToRightSearch(_idx) ? pIterNode->nextLink : pIterNode->prevLink;

	return pIterNode->data;
}

template<typename T>
T & CDoubleLinkedList<T>::operator[](int _idx) {
	if (_idx < 0 || _idx >= m_Count || m_Count == 0)
		throw::std::out_of_range("");

	int moveCnt = IsLeftToRightSearch(_idx) ? _idx : m_Count - 1 - _idx;
	Node<T>* pIterNode = IsLeftToRightSearch(_idx) ? m_pNodeHead : m_pNodeTail;
	for (int i = 0; i < moveCnt; ++i)
		pIterNode = IsLeftToRightSearch(_idx) ? pIterNode->nextLink : pIterNode->prevLink;
	return pIterNode->data;
}

template<typename T>
typename CDoubleLinkedList<T>::iterator CDoubleLinkedList<T>::Erase(iterator& _iter)
{
	assert(this == _iter.mOwner);
	assert(_iter.mTargetNode);

	Node<T>* pDelNode = _iter.mTargetNode;
	Node<T>* pPrevNode = _iter.mTargetNode->prevLink;
	Node<T>* pNextNode = _iter.mTargetNode->nextLink;

	if (pDelNode->prevLink == nullptr)
		m_pNodeHead = pNextNode;
	if (pDelNode->nextLink == nullptr)
		m_pNodeTail = pPrevNode;

	if(pPrevNode != nullptr)
		pPrevNode->nextLink = pNextNode;
	if(pNextNode != nullptr)
		pNextNode->prevLink = pPrevNode;

	delete pDelNode;
	--m_Count;
	
	_iter.mTargetNode = pNextNode;
	return iterator(_iter.mOwner, pPrevNode);
}

////////// Iterator //////////
template<typename T>
inline CDoubleLinkedList<T>::iterator::iterator(const iterator& _iter) :
	mOwner(_iter.mOwner),
	mTargetNode(_iter.mTargetNode)
{
}

template<typename T>
inline CDoubleLinkedList<T>::iterator::iterator(CDoubleLinkedList* _pOwner, Node<T>* _targetNode) :
	mOwner(_pOwner),
	mTargetNode(_targetNode)
{
}

template<typename T>
inline CDoubleLinkedList<T>::iterator::~iterator()
{
	mOwner = nullptr;
	mTargetNode = nullptr;
}

template<typename T>
typename int& CDoubleLinkedList<T>::iterator::operator*() {
	assert(mTargetNode);
	return mTargetNode->data;
}

template<typename T>
typename CDoubleLinkedList<T>::iterator& CDoubleLinkedList<T>::iterator::operator++() {
	if ( mTargetNode == nullptr || mOwner->m_Count == 0 )
		throw::std::out_of_range("");
	mTargetNode = mTargetNode->nextLink;
	return *this;
}

template<typename T>
typename CDoubleLinkedList<T>::iterator CDoubleLinkedList<T>::iterator::operator++(int) {
	iterator copyIter(mOwner, mTargetNode);
	++(*this);
	return nullptr;
}

template<typename T>
typename CDoubleLinkedList<T>::iterator & CDoubleLinkedList<T>::iterator::operator--()
{
	if ( mTargetNode == mOwner->m_pNodeHead || mOwner->m_Count == 0)
		throw::std::out_of_range("");
	mTargetNode = mTargetNode == nullptr ? mOwner->m_pNodeTail : mTargetNode->prevLink;

	return *this;
}

template<typename T>
typename CDoubleLinkedList<T>::iterator CDoubleLinkedList<T>::iterator::operator--(int)
{
	iterator copyIter(mOwner, mTargetNode);
	--(*this);
	return iterator();
}

template<typename T>
typename bool CDoubleLinkedList<T>::iterator::operator!=(const iterator& _iter)
{
	return mTargetNode != _iter.mTargetNode;
}

template<typename T>
typename bool CDoubleLinkedList<T>::iterator::operator==(const iterator& _iter)
{
	return mTargetNode == _iter.mTargetNode;
}
