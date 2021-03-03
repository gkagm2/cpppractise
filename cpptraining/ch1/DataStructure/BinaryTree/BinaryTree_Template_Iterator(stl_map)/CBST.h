#pragma once
#include <iostream>
#include <cassert>
#include <memory>
using std::cout;

template<typename T1, typename T2>
struct tBSTPair {
	T1 first;
	T2 second;

public:
	tBSTPair() :
		first(),
		second()
	{}
	tBSTPair(const T1& _first, const T2& _second) :
		first(_first),
		second(_second)
	{}
	
	tBSTPair& operator=(const tBSTPair<T1, T2>& _pair) {
		first = _pair.first;
		second = _pair.second;
		return *this;
	}
};

// Pair Function
template<typename T1, typename T2>
tBSTPair<T1, T2> Make_pair(const T1& _first, const T2& _second) {
	return tBSTPair<T1, T2>(_first, _second);
}

//////////////////////// CBST class ///////////////////////
// BST Node
template<typename T_Key, typename T_Value>
struct tBSTNode {
	tBSTPair<T_Key, T_Value> data;
	tBSTNode* pParent;
	tBSTNode* pLeftChild;
	tBSTNode* pRightChild;

	tBSTNode() :
		data(),
		pParent(nullptr),
		pLeftChild(nullptr),
		pRightChild(nullptr)
	{}
	tBSTNode(const tBSTNode& _node) :
		data(_node.data),
		pParent(_node.pParent),
		pLeftChild(_node.pLeftChild),
		pRightChild(_node.pRigthChild)
	{}
	tBSTNode(const tBSTPair<T_Key, T_Value>& _data) :
		data(_data),
		pParent(nullptr),
		pLeftChild(nullptr),
		pRightChild(nullptr)
	{}

public:
	bool IsRoot() { return nullptr == pParent; }
	bool IsLeaf() { return nullptr == pLeftChild && nullptr == pRightChild; }
	bool HasParent() { return nullptr != pParent; }
	bool HasLeftChild() { return nullptr != pLeftChild; }
	bool HasRightChild() { return nullptr != pRightChild; }
	bool IsLeftChildFromParent() { if (!HasParent()) return false; return pParent->pLeftChild == this; }
	bool IsRightChildFromParent() { if (!HasParent()) return false; return pParent->pRightChild == this; }

public:
	tBSTNode& operator=(const tBSTNode& _node) {
		data = _node.data;
		pParent = _node.pParent;
		pLeftChild = _node.pLeftChild;
		pRightChild = _node.pRightChild;
		return *this;
	}
};

// BST Class
template<typename T_Key, typename T_Value>
class CBST {
private:
	tBSTNode<T_Key, T_Value>* m_pRoot;
	int m_iCount;
public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0)
	{}
	~CBST();
	void Insert(const tBSTPair<T_Key, T_Value>& _pair);
	
private:
	tBSTNode<T_Key, T_Value>* inorderSuccessor(tBSTNode<T_Key, T_Value>* _pNode); // 노드보다 크며 가장 가까운 값 (중위 후속자)
	tBSTNode<T_Key, T_Value>* inorderPredecessor(tBSTNode<T_Key, T_Value>* _pNode); // 노드보다 작으면 가장 가까운 값 (중위 선행자)
	tBSTNode<T_Key, T_Value>* deleteNode(tBSTNode<T_Key, T_Value>* _pNode);

	tBSTNode<T_Key, T_Value>* GetLeftmostNode(tBSTNode<T_Key, T_Value>* _pNode);
	tBSTNode<T_Key, T_Value>* GetRightmostNode(tBSTNode<T_Key, T_Value>* _pNode);
public:
	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T_Key& _key);
	iterator erase(const iterator& _where);
	void clear();

	class iterator {
	public:
		CBST<T_Key, T_Value>* m_pBST;
		tBSTNode<T_Key, T_Value>* m_pTargetNode;
	public:
		iterator();
		iterator(CBST<T_Key, T_Value>* _pBst, tBSTNode<T_Key, T_Value>* _pTargetNode);
		~iterator();
		
	public:
		tBSTPair<T_Key, T_Value>& operator*();
		tBSTPair<T_Key, T_Value>* operator->();
		bool operator==(const iterator& _iter);
		bool operator!=(const iterator& _iter);
		iterator& operator++(); // 전입
		iterator operator++(int); // 후입
		iterator& operator--();
		iterator operator--(int);

	public:
		friend class CBST;
	};
};

template<typename T_Key, typename T_Value>
inline CBST<T_Key, T_Value>::~CBST()
{
	clear();
}

template<typename T_Key, typename T_Value>
inline void CBST<T_Key, T_Value>::Insert(const tBSTPair<T_Key, T_Value>& _pair)
{
	tBSTNode<T_Key, T_Value>* pNewNode = new tBSTNode<T_Key, T_Value>(_pair);

	if (nullptr == m_pRoot) {
		m_pRoot = pNewNode;
		++m_iCount;
		return;
	}
		
	// Access to insertable node position
	const int iLEFT= 0, iRIGHT = 1;
	int iCurState = iLEFT;

	tBSTNode<T_Key, T_Value>* pCurNode = m_pRoot;
	while (true) {
		const T_Key& curKey = pCurNode->data.first;
		const T_Key& insertKey = _pair.first;

		if (curKey == insertKey) {
			if (pNewNode) delete pNewNode;
			return;
		}
		
		if (curKey > insertKey) {
			if (nullptr != pCurNode->pLeftChild) // exist node
				pCurNode = pCurNode->pLeftChild;
			else {
				iCurState = iLEFT; 
				break;
			}
		} 
		else if (curKey < insertKey) {
			if (nullptr != pCurNode->pRightChild)
				pCurNode = pCurNode->pRightChild;
			else {
				iCurState = iRIGHT;
				break;
			}
		}
	}
		
	// Node create and Insert
	if (iCurState == iLEFT) {
		pCurNode->pLeftChild = pNewNode;
		pNewNode->pParent = pCurNode;
	}
	else {
		pCurNode->pRightChild = pNewNode;
		pNewNode->pParent = pCurNode;
	}
	++m_iCount;
}

template<typename T_Key, typename T_Value>
inline tBSTNode<T_Key, T_Value>* CBST<T_Key, T_Value>::inorderSuccessor(tBSTNode<T_Key, T_Value>* _pNode)
{
	tBSTNode<T_Key, T_Value>* pSuccessor = nullptr;
	
	if (_pNode->HasRightChild()) { // 1. 자식 노드가 있으면
		pSuccessor = _pNode->pRightChild; 
		while (nullptr != pSuccessor->pLeftChild)
			pSuccessor = pSuccessor->pLeftChild;
	}
	else { // 2. 자식 노드가 없으면 
		tBSTNode<T_Key, T_Value>* pCurNode = _pNode;

		while (pCurNode->HasParent()) { // 부모가 있으면
			// 현재 노드의 오른쪽에 있는 부모 노드인지 확인한다.
			if (pCurNode->IsLeftChildFromParent()) {
				pSuccessor = pCurNode->pParent;
				break;
			}
			pCurNode = pCurNode->pParent;
		}
	}
	return pSuccessor;
}

template<typename T_Key, typename T_Value>
inline tBSTNode<T_Key, T_Value>* CBST<T_Key, T_Value>::inorderPredecessor(tBSTNode<T_Key, T_Value>* _pNode)
{
	tBSTNode<T_Key, T_Value>* pPredecessor = nullptr;

	if (_pNode->HasLeftChild()) {
		pPredecessor = _pNode->pLeftChild;
		while (nullptr != pPredecessor->pRightChild)
			pPredecessor = pPredecessor->pRightChild;
	}
	else {
		tBSTNode<T_Key, T_Value>* pCurNode = _pNode;
		
		while (pCurNode->HasParent()) {
			if (pCurNode->IsRightChildFromParent()) {
				pPredecessor = pCurNode->pParent;
				break;
			}
			pCurNode = pCurNode->pParent;
		}
	}
	return pPredecessor;
}

template<typename T_Key, typename T_Value>
inline tBSTNode<T_Key, T_Value>* CBST<T_Key, T_Value>::deleteNode(tBSTNode<T_Key, T_Value>* _pNode)
{
	assert(_pNode);

	tBSTNode<T_Key, T_Value>* pSuccessor = inorderSuccessor(_pNode);

	if (_pNode->IsLeaf()) { // Leap Node일 경우
		if (_pNode->IsRoot())
			m_pRoot = nullptr;
		else { // 부모 노드가 존재하는 경우
			if (_pNode->IsLeftChildFromParent())
				_pNode->pParent->pLeftChild = nullptr;
			else
				_pNode->pParent->pRightChild = nullptr;
		}
		--m_iCount;
		delete _pNode;
	}
	else if (_pNode->HasLeftChild() && _pNode->HasRightChild()) { // 왼쪽자식과 오른쪽 자식 둘다 가지고 있는 경우
		_pNode->data = pSuccessor->data;
		deleteNode(pSuccessor);
		pSuccessor = _pNode;
	}
	else { // 자식이 1개인 경우
		if (_pNode->HasLeftChild()) { // 왼쪽 자식만 있는 노드일 경우
			if (_pNode->IsRoot()) {
				m_pRoot = _pNode->pLeftChild;
				m_pRoot->pParent = nullptr;
			}
			else { // root가 아니면
				if (_pNode->IsLeftChildFromParent())
					_pNode->pParent->pLeftChild = _pNode->pLeftChild;
				else
					_pNode->pParent->pRightChild = _pNode->pLeftChild;
				_pNode->pLeftChild->pParent = _pNode->pParent;
			}
		}
		else // 오른쪽 자식만 있는 노드일 경우
			if (_pNode->IsRoot()) {
				m_pRoot = _pNode->pRightChild;
				m_pRoot->pParent = nullptr;
			}
			else {
				if (_pNode->IsLeftChildFromParent())
					_pNode->pParent->pLeftChild = _pNode->pRightChild;
				else
					_pNode->pParent->pRightChild = _pNode->pRightChild;
				_pNode->pRightChild->pParent = _pNode->pParent;
			}
		--m_iCount;
		delete _pNode;
	}

	return pSuccessor;
}

template<typename T_Key, typename T_Value>
inline tBSTNode<T_Key, T_Value>* CBST<T_Key, T_Value>::GetLeftmostNode(tBSTNode<T_Key, T_Value>* _pNode)
{
	tBSTNode<T_Key, T_Value>* pLeftmostNode = _pNode;
	while (pLeftmostNode->HasLeftChild())
		pLeftmostNode = pLeftmostNode->pLeftChild;
	return pLeftmostNode;
}

template<typename T_Key, typename T_Value>
inline tBSTNode<T_Key, T_Value>* CBST<T_Key, T_Value>::GetRightmostNode(tBSTNode<T_Key, T_Value>* _pNode)
{
	tBSTNode<T_Key, T_Value>* pRightmostNode = _pNode;
	while (pRightmostNode->HasRightChild())
		pRightmostNode = pRightmostNode->pRightChild;
	return pRightmostNode;
}


/////////////////// Iterator /////////////////

template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator CBST<T_Key, T_Value>::begin()
{
	if (nullptr == m_pRoot)
		return end();

	tBSTNode<T_Key, T_Value>* pLeftmostNode = GetLeftmostNode(m_pRoot);
	
	return iterator(this, pLeftmostNode);
}

template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator CBST<T_Key, T_Value>::end()
{
	return iterator(this, nullptr);
}


template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator CBST<T_Key, T_Value>::find(const T_Key& _key)
{
	assert(_key);

	tBSTNode<T_Key, T_Value>* pFindNode = m_pRoot;

	while (nullptr != pFindNode) {
		if (pFindNode->data.first > _key)
			pFindNode = pFindNode->pRightChild;
		else if (pFindNode->data.first < _key)
			pFindNode = pFindNode->pLeftChild;
		else { // found key 
			break;
		}
	}

	return iterator(this, pFindNode);
}

template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator CBST<T_Key, T_Value>::erase(const iterator & _where)
{
	tBSTNode<T_Key, T_Value>* pSuccessor = deleteNode(_where.m_pTargetNode);
	return iterator(this, pSuccessor);
}

template<typename T_Key, typename T_Value>
inline void CBST<T_Key, T_Value>::clear()
{
	while (m_iCount) {
		std::cout << "삭제되는 노드 : " << m_pRoot->data.first << "\n";
		deleteNode(m_pRoot);
	}
}


template<typename T_Key, typename T_Value>
inline CBST<T_Key, T_Value>::iterator::iterator()
	: m_pBST(nullptr)
	, m_pTargetNode(nullptr)
{
}

template<typename T_Key, typename T_Value>
inline CBST<T_Key, T_Value>::iterator::iterator(CBST<T_Key, T_Value>* _pBst, tBSTNode<T_Key, T_Value>* _pTargetNode)
	: m_pBST(_pBst)
	, m_pTargetNode(_pTargetNode)
{
}
template<typename T_Key, typename T_Value>
inline CBST<T_Key, T_Value>::iterator::~iterator()
{
	m_pBST = nullptr;
	m_pTargetNode = nullptr;
}

// iterator operator
template<typename T_Key, typename T_Value>
inline tBSTPair<T_Key, T_Value>& CBST<T_Key, T_Value>::iterator::operator*()
{
	assert(m_pTargetNode);
	return m_pTargetNode->data;
}

template<typename T_Key, typename T_Value>
inline tBSTPair<T_Key, T_Value>* CBST<T_Key, T_Value>::iterator::operator->()
{
	assert(m_pTargetNode);
	return &m_pTargetNode->data;
}

template<typename T_Key, typename T_Value>
inline bool CBST<T_Key, T_Value>::iterator::operator==(const iterator& _iter)
{
	return m_pBST == _iter.m_pBST && m_pTargetNode == _iter.m_pTargetNode;
}

template<typename T_Key, typename T_Value>
inline bool CBST<T_Key, T_Value>::iterator::operator!=(const iterator& _iter)
{
	return !(*this == _iter);
}

template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator & CBST<T_Key, T_Value>::iterator::operator++()
{
	assert(m_pTargetNode); // end iterator
	m_pTargetNode = m_pBST->inorderSuccessor(m_pTargetNode);

	return *this;
}

template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator CBST<T_Key, T_Value>::iterator::operator++(int)
{
	iterator iter(m_pBST, m_pTargetNode);
	++(*this);
	
	return iter;
}

template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator & CBST<T_Key, T_Value>::iterator::operator--()
{
	if (m_pBST->m_iCount == 0 || m_pTargetNode == m_pBST->GetLeftmostNode(m_pBST->m_pRoot))
		throw::out_of_range("");

	if (m_pTargetNode == nullptr) // end일 경우
		m_pTargetNode = m_pBST->GetRightmostNode(m_pBST->m_pRoot);
	else
		m_pTargetNode = m_pBST->inorderPredecessor(m_pTargetNode);

	return *this;
}

template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator CBST<T_Key, T_Value>::iterator::operator--(int)
{
	iterator iter(m_pBST, m_pTargetNode);
	--(*this);
	return iter;
}
