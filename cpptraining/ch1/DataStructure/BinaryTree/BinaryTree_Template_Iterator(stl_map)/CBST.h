#pragma once
#include <iostream>
#include <cassert>
#include <memory>

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
	inline bool IsRoot() { return nullptr == pParent; }
	inline bool IsLeaf() { return nullptr == pLeftChild && nullptr == pRightChild; }
	inline bool HasParent() { return nullptr != pParent; }
	inline bool HasLeftChild() { return nullptr != pLeftChild; }
	inline bool HasRightChild() { return nullptr != pRightChild; }
	inline bool IsLeftChildFromParent() { if (!HasParent()) return false; return pParent->pLeftChild == this; }
	inline bool IsRightChildFromParent() { if (!HasParent()) return false; return pParent->pRightChild == this; }

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
	
public:
	tBSTNode<T_Key, T_Value>* inorderSuccessor(tBSTNode<T_Key, T_Value>* _pNode); // 노드보다 크며 가장 가까운 값 (중위 후속자)
	tBSTNode<T_Key, T_Value>* inorderPredecessor(tBSTNode<T_Key, T_Value>* _pNode); // 노드보다 작으면 가장 가까운 값 (중위 선행자)

	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T_Key& _key);
	//iterator erase() {} // todo

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
		
		
	public:
		friend class CBST;
	};
};

template<typename T_Key, typename T_Value>
inline CBST<T_Key, T_Value>::~CBST()
{
	// TODO : Search and delete all
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
			else
				pCurNode = pCurNode->pParent;
		}
	}
	return pSuccessor;
}

template<typename T_Key, typename T_Value>
inline tBSTNode<T_Key, T_Value>* CBST<T_Key, T_Value>::inorderPredecessor(tBSTNode<T_Key, T_Value>* _pNode)
{
	// TODO
	return NULL;
}


/////////////////// Iterator /////////////////

template<typename T_Key, typename T_Value>
typename CBST<T_Key, T_Value>::iterator CBST<T_Key, T_Value>::begin()
{
	if (nullptr == m_pRoot)
		return end();

	tBSTNode<T_Key, T_Value>* pBeginNode = m_pRoot;
	while (pBeginNode->HasLeftChild())
		pBeginNode = pBeginNode->pLeftChild;

	return iterator(this, pBeginNode);
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
	assert(m_pTargetNode); // end node일 경우.
	iterator iter(m_pBST, m_pTargetNode);
	++(*this);
	
	// 맨 마지막 노드일 경우.
	return iter;
}
