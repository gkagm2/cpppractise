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