#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string>
template<typename TYPE>
class BinaryTree {
protected:
	struct Node {
		TYPE data;
		Node* pLeft;
		Node* pRight;
		Node() : pLeft(nullptr), pRight(nullptr) {}
	};

	Node *m_pNodeHead;
	Node *m_pNodeTail;

public:
	BinaryTree();
	~BinaryTree();

	void RemoveSubTree(Node *pNode);
	void RemoveAll();

protected:
	void PreOrderTraversal(Node* pNode);
	void PreOrderTraversal_stack(Node* pNode);
	void InOrderTraversal(Node* pNode);
	void InOrderTraversal_stack(Node* pNode);
	void PostOrderTraversal(Node* pNode);
	void PostOrderTraversal_stack(Node* pNode);
	void LevelOrderTraversal(Node* pNode); // 위에서 아래로, 좌에서 우로 진행
public:
	void PreOrderTraversal();
	void PreOrderTraversal_stack();
	void InOrderTraversal();
	void InOrderTraversal_stack();
	void PostOrderTraversal();
	void PostOrderTraversal_stack();
	void LevelOrderTraversal(); // 위에서 아래로, 좌에서 우로 진행
};

using namespace std;

template<typename TYPE>
BinaryTree<TYPE>::BinaryTree()
{
	m_pNodeHead = new Node;
	m_pNodeTail = new Node;
	m_pNodeHead->pLeft = m_pNodeTail;
	m_pNodeHead->pRight = m_pNodeTail;
	m_pNodeTail->pLeft = m_pNodeTail;
	m_pNodeTail->pRight = m_pNodeTail;
}

template<typename TYPE>
BinaryTree<TYPE>::~BinaryTree()
{
	RemoveAll();
	if (m_pNodeHead)
		delete m_pNodeHead;
	if (m_pNodeTail)
		delete m_pNodeTail;
}

template<typename TYPE>
void BinaryTree<TYPE>::RemoveAll()
{

}

template<typename TYPE>
void BinaryTree<TYPE>::RemoveSubTree(Node * pNode)
{
}

template<typename TYPE>
void BinaryTree<TYPE>::PreOrderTraversal(Node* pNode) {
	if (pNode == m_pNodeTail)
		return;

	cout << pNode->data << "->"; // visit
	PreOrderTraversal(pNode->pLeft);
	PreOrderTraversal(pNode->pRight);
}

template<typename TYPE>
void BinaryTree<TYPE>::PreOrderTraversal_stack(Node* pNode) {
	stack<Node*> stk;
	stk.push(pNode);
	while (!stk.empty()) {
		pNode = stk.top();
		stk.pop();
		if (pNode != m_pNodeTail) {
			cout << pNode->data << "->";
			stk.push(pNode->pLeft);
			stk.push(pNode->pRight);
		}
	}
}

template<typename TYPE>
void BinaryTree<TYPE>::InOrderTraversal(Node* pNode) {
	if (pNode == m_pNodeTail)
		return;

	InOrderTraversal(pNode->pLeft);
	cout << pNode->data << "->"; // visit
	InOrderTraversal(pNode->pRight);
}

template<typename TYPE>
void BinaryTree<TYPE>::InOrderTraversal_stack(Node* pNode) {
	stack<Node*> stk;
	stk.push(pNode);
	while (!stk.empty()) {
		pNode = stk.top();
		stk.pop();
		if (pNode != m_pNodeTail) {
			stk.push(pNode->pLeft);
			cout << pNode->data << "->";
			stk.push(pNode->pRight);
		}
	}
}

template<typename TYPE>
void BinaryTree<TYPE>::PostOrderTraversal(Node* pNode) {
	if (pNode == m_pNodeTail)
		return;

	PostOrderTraversal(pNode->pLeft);
	PostOrderTraversal(pNode->pRight);
	cout << pNode->data << "->"; // visit
}

template<typename TYPE>
void BinaryTree<TYPE>::PostOrderTraversal_stack(Node* pNode) {
	stack<Node*> stk;
	stk.push(pNode);
	while (!stk.empty()) {
		pNode = stk.top();
		stk.pop();
		if (pNode != m_pNodeTail) {
			stk.push(pNode->pLeft);
			stk.push(pNode->pRight);
			cout << pNode->data << "->"; // visit
		}
	}
}

template<typename TYPE>
void BinaryTree<TYPE>::LevelOrderTraversal(Node* pNode) {
	queue<Node*> que;
	que.push(pNode);

	while (!que.empty()) {
		pNode = que.front();
		que.pop();
		if (pNode != m_pNodeTail) {
			cout << pNode->data << "->"; // visit
			que.push(pNode->pLeft);
			que.push(pNode->pRight);
		}
	}
}

template<typename TYPE>
void BinaryTree<TYPE>::PreOrderTraversal()
{
	PreOrderTraversal(m_pNodeHead);
}

template<typename TYPE>
void BinaryTree<TYPE>::PreOrderTraversal_stack()
{
	PreOrderTraversal_stack(m_pNodeHead);
}

template<typename TYPE>
void BinaryTree<TYPE>::InOrderTraversal()
{
	InOrderTraversal(m_pNodeHead);
}

template<typename TYPE>
void BinaryTree<TYPE>::InOrderTraversal_stack()
{
	InOrderTraversal_stack(m_pNodeHead);
}

template<typename TYPE>
void BinaryTree<TYPE>::PostOrderTraversal()
{
	PostOrderTraversal(m_pNodeHead);
}

template<typename TYPE>
void BinaryTree<TYPE>::PostOrderTraversal_stack()
{
	PostOrderTraversal_stack(m_pNodeHead);
}

template<typename TYPE>
void BinaryTree<TYPE>::LevelOrderTraversal()
{
	LevelOrderTraversal(m_pNodeHead);
}