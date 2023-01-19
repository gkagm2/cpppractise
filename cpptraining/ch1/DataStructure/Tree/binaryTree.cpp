#include <iostream>
#include <queue>
using namespace std;
typedef int Data;

struct Node {
	Node* pLeft;
	Node* pRight;
	Data data;
	Node() : pLeft(nullptr), pRight(nullptr), data() {}
	Node(Data _data) : pLeft(nullptr), pRight(nullptr), data(_data) {}
};


class BinaryTree {
private:
	Node* m_pRoot;
public:
	BinaryTree() {
		m_pRoot = nullptr;
	}
	~BinaryTree() {
		Node* pFocusNode = m_pRoot;
		queue<Node*> q;
		q.push(pFocusNode);
		while (!q.empty()) {
			Node* pCurNode = q.front();
			q.pop();

			if (nullptr == pCurNode)
				continue;

			q.push(pCurNode->pLeft);
			q.push(pCurNode->pRight);

			delete pCurNode;
		}
	}
	void AddNode(Data _data) {
		Node* pNewNode = new Node(_data);

		if (nullptr == m_pRoot) {
			m_pRoot = pNewNode;
		} 
		else{
			Node* pFocusNode = m_pRoot;
			while (true) {
				if (pNewNode->data < pFocusNode->data) {
					if (nullptr == pFocusNode->pLeft) {
						pFocusNode->pLeft = pNewNode;
						break;
					}
					pFocusNode = pFocusNode->pLeft;
				}
				else {
					if (nullptr == pFocusNode->pRight) {
						pFocusNode->pRight = pNewNode;
						break;
					}
					pFocusNode = pFocusNode->pRight;
				}
			}
		}
	}
	void Delete(Data _data) {

	}
	Node* Search(Data _data) {
		return nullptr;
	}
public:
	// current-left-right
	void PreorderTraversal() {
		_Preorder(m_pRoot);
	}
private:
	void _Preorder(Node* _pNode) {
		if (nullptr == _pNode)
			return;
		cout << _pNode->data << "->";
		_Preorder(_pNode->pLeft);
		_Preorder(_pNode->pRight);
	}

public:
	// left-current-right
	void InorderTraversal() {
		_Inorder(m_pRoot);
	}
private:
	void _Inorder(Node* _pNode) {
		if (nullptr == _pNode)
			return;
		_Inorder(_pNode->pLeft);
		cout << _pNode->data << "->";
		_Inorder(_pNode->pRight);
	}

public:
	// left-right-current
	void PostorderTraversal() {
		_Postorder(m_pRoot);
	}
private:
	void _Postorder(Node* _pNode) {
		if (nullptr == _pNode)
			return;
		_Postorder(_pNode->pLeft);
		_Postorder(_pNode->pRight);
		cout << _pNode->data << "->";
	}
public:
	int GetTreeHeight() {
		return 0;
	}
	int GetTreeLevel() {
		return 0;
	}
	int GetTreeSize() {
		return 0;
	}
};

int main() {
	BinaryTree tree;
	tree.AddNode(50);
	tree.AddNode(25);
	tree.AddNode(75);
	tree.AddNode(12);
	tree.AddNode(37);
	tree.AddNode(43);
	tree.AddNode(30);

	tree.PreorderTraversal();

	return 0;
}