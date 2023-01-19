#include <iostream>
#include <queue>
using namespace std;
typedef int Data;

template<typename T> T max(T _a, T _b);

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
	int m_iSize;
public:
	BinaryTree() : m_iSize(0) {
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
		else {
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
		++m_iSize;
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
	int GetHeight() {
		return _GetHeight(m_pRoot);
	}
private:
	int _GetHeight(Node* _pNode) {
		if (nullptr == _pNode)
			return 0;

		return 1 + ::max(_GetHeight(_pNode->pLeft), _GetHeight(_pNode->pRight));
	}
public:
	int GetDiameter() {
		return _GetDiameter(m_pRoot);
	}
private:
	int _GetDiameter(Node* _pNode) {
		if (nullptr == _pNode)
			return 0;

		int leftHeight = _GetHeight(_pNode->pLeft);
		int rightHeight = _GetHeight(_pNode->pRight);
		
		int leftDiameter = _GetDiameter(_pNode->pLeft);
		int rightDiameter = _GetDiameter(_pNode->pRight);

		return ::max(leftHeight + rightHeight + 1, ::max(leftDiameter, rightDiameter));
	}
public:

	int GetLevel() {
		return 0;
	}
	int GetSize() {
		return m_iSize;
	}
};

int main() {
	BinaryTree tree;
	tree.AddNode(5);
	tree.AddNode(0);
	tree.AddNode(8);
	tree.AddNode(2);
	tree.AddNode(7);
	tree.AddNode(3);
	tree.AddNode(1);

	tree.PreorderTraversal();

	cout << "\n Tree Height : " << tree.GetHeight() << "\n";

	cout << "\n Tree Diameter : " << tree.GetDiameter() << "\n";
	return 0;
}

template<typename T>
T max(T _a, T _b) {
	return _a > _b ? _a : _b;
}