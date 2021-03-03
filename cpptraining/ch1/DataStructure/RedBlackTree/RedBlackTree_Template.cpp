#include <iostream>
#include <assert.h>
using namespace std;

// 2-3-4 Ʈ���� Red-Black Ʈ��
//�� �� balanced tree��

// ����Ʈ�θ� 2-3-4 Ʈ���� Balanced Ư���� ������ ��
// ���� ���� ������� �ΰ����� ����
// ���� ���� �������� ���յǴ� �ǹ�
// Red-Edge, Black-Edge�� ǥ���ϱ⵵ ��

/*
Red-Black Tree�� ����
- �θ���� ���� ����Ʈ������ ũ�� ������ ����Ʈ������ �۴�.
  - ���� �˻�Ʈ���� ������ ����
- Root���� Leaf�� ���� ����� ��������� ���� ��� ����.
- ���� ���ԵǴ� ���� Leaf�� ��ġ�ϸ� ��������̴�.
- ��λ� ���̾� �ΰ��� ������尡 ���� �� ����. (ȸ�� �ʿ�)
- �θ��� �� �ڽĳ�尡 ��� ��������̸�, �θ� ���������ϰ� �ڽ��� �������� �ٲ� �� �ִ�.(���� ��ȯ)
- Root���� ��������� �� ����.(�������� ��ȯ)
- �������� �ڽ��� ������, �ִٸ� �ΰ��� ������忩�� �Ѵ�.
- �������� �ڽ��� ������, �ִٸ� �ϳ��� ������峪  �ΰ��� ���� ��峪 �ΰ��� ������带 ������.
  - �� �� �ϳ��� ������带 �ڽ����� ���� �� ����.
*/

enum Link {
	parent,
	leftchild,
	rightchild
};

enum Color {
	red,
	black
};

template<typename T>
struct Node{
	T data;
	Color color;
	Node<T>* link[3]; // 0 :parent, 1 left, 2:right;
	Node() :
		color{ red },
		link{ nullptr, }
	{}
};

template<typename T>
class RedBlackTree {
private:
	Node<T>* m_pRoot;

private:
	void _InorderPrint(Node<T>* _pNode);
	void _PostorderDeleteAllNode(Node<T>* _pNode);

	Node<T>* _InorderSuccessor(Node<T>* _pNode); // node���� ũ�� ���� ����� ��.
	Node<T>* _InorderPredecessor(Node<T>* _pNode); // node���� ������ ���� ����� ��.

public:
	void Insert(T _data);
	void Delete(T _data);
	bool Search(const T& _data, Node<T>& _retNode);
	void ShowAllNode();


	void RotateLeft(Node<T>* _pNode);
	void RotateRight(Node<T>* _pNode);

	

public:
	RedBlackTree();
	RedBlackTree(const RedBlackTree& _other); // ���� ����
	~RedBlackTree();
};

template<typename T>
RedBlackTree<T>::RedBlackTree() :
	m_pRoot(nullptr)
{
	cout << "�⺻������\n";
}

template<typename T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree & _other)
{
	cout << "���������\n";
}

template<typename T>
RedBlackTree<T>::~RedBlackTree()
{
	cout << "�Ҹ���\n";
	// �Ҹ��Ұ�� ����ؾߵɱ�.
	_PostorderDeleteAllNode(m_pRoot);
	m_pRoot = nullptr;
}

template<typename T>
void RedBlackTree<T>::_InorderPrint(Node<T>* _pNode)
{
	if (nullptr == _pNode)
		return;
	_InorderPrint(_pNode->link[leftchild]);
	cout << _pNode->data << " ";// Print
	_InorderPrint(_pNode->link[rightchild]);
}

template<typename T>
void RedBlackTree<T>::_PostorderDeleteAllNode(Node<T>* _pNode)
{
	if (nullptr == _pNode)
		return;
	_PostorderDeleteAllNode(_pNode->link[leftchild]);
	_PostorderDeleteAllNode(_pNode->link[rightchild]);
	delete _pNode;
}

template<typename T>
Node<T>* RedBlackTree<T>::_InorderSuccessor(Node<T>* _pNode)
{
	Node<T>* pSuccessor = nullptr;

	return nullptr;
}

template<typename T>
Node<T>* RedBlackTree<T>::_InorderPredecessor(Node<T>* _pNode)
{
	Node<T>* pPredecessor = nullptr;

	return nullptr;
}

template<typename T>
void RedBlackTree<T>::Insert(T _data){
	Node<T>* pNewNode = new Node<T>;
	pNewNode->data = _data;
	if (m_pRoot == nullptr)
		m_pRoot = pNewNode;
	else {
		Node<T>* pCurNode = m_pRoot;
		Link state = parent;
		while (nullptr != pCurNode) {
			if (_data > pCurNode->data)
				state = rightchild;
			else
				state = leftchild;

			if (nullptr == pCurNode->link[state]) {
				pCurNode->link[state] = pNewNode;
				pNewNode->link[parent] = pCurNode;
				break;
			}
				
			pCurNode = pCurNode->link[state];
		}
	}
}

template<typename T>
void RedBlackTree<T>::Delete(T _data)
{
}

template<typename T>
bool RedBlackTree<T>::Search(const T& _data, Node<T>& _retNode)
{
	Node<T>* pCurNode = m_pRoot;
	while (nullptr == pCurNode ) {
		if (_data == pCurNode->data)
			break;
		if (_data > pCurNode->data)
			pCurNode = pCurNode->link[rightchild];
		else
			pCurNode = pCurNode->link[leftchild];
	}
	if (pCurNode) {
		_retNode = pCurNode;
		return true;
	}
	_retNode = nullptr;
	return false;
}

template<typename T>
void RedBlackTree<T>::ShowAllNode()
{
	_InorderPrint(m_pRoot);
}

template<typename T>
void RedBlackTree<T>::RotateLeft(Node<T>* _pNode)
{
	/*			��Ȳ
			  _pNode
			  ��		��
		    alpha	rightChild
					��		��
				beta		gamma
	*/
	// root����� �θ�� null�̿��� ��.
	// ����� ������ �ڽ��� �����ؾ� �Ѵ�.
	if (nullptr == _pNode->link[rightchild])
		return;
	 
	Node<T>* pRightChild = _pNode->link[rightchild];
	Node<T>* pBeta = pRightChild->link[leftchild];
	_pNode->link[rightchild] = pBeta; // rightchild�� �����ڽ��� beta��  _pNode�� ������ �ڽ����� �־���.
	pBeta->link[parent] = _pNode; // beta�� �θ� _pNode�� ���ش�.

	pRightChild->link[parent] = _pNode->link[parent];// _pNode�� �θ� rightChild�� ���ش�.
	if (nullptr == _pNode->link[parent]) { // �θ� ������ root��
		m_pRoot = pRightChild;
	}
	else if (_pNode == _pNode->link[parent]->link[leftchild]) // pNode�� ������ �θ��� ���� �ڽ��̸�
		_pNode->link[parent]->link[leftchild] = pRightChild;
	else // pNode�� ������ �θ��� ���� �ڽ��̸� 
		_pNode->link[parent]->link[rightchild] = pRightChild;
	
	pRightChild->link[leftchild] = _pNode;
	_pNode->link[parent] = pRightChild;
}

template<typename T>
void RedBlackTree<T>::RotateRight(Node<T>* _pNode)
{
	/*			��Ȳ
			  _pNode
			  ��		��
		leftChild	alpha
		��		��
	beta		gamma
	*/
	if (nullptr == _pNode->lnk[leftchild])
		return;

	Node<T>* pLeftChild = _pNode->link[leftchild];
	Node<T>* pGamma = pLeftChild->link[rightchild];
	_pNode->link[leftchild] = pGamma;
	pGamma->link[parent] = _pNode;

	pLeftChild->link[parent] = _pNode->link[parent];
	if (nullptr == _pNode->link[parent]) {
		m_pRoot = pLeftChild;
	}
	else if (_pNode == _pNode->link[parent]->link[leftchild])
		_pNode->link[parent]->link[leftchild] = pLeftChild;
	else
		_pNode->link[parent]->link[rightchild] = pLeftChild;

	pLeftChild->link[rightchild] = _pNode;
	_pNode->link[parent] = pLeftChild;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	RedBlackTree<int> rbTree;
	rbTree.Insert(3);
	rbTree.Insert(2);
	rbTree.Insert(5);
	rbTree.Insert(1);
	rbTree.Insert(8);

	rbTree.ShowAllNode();

	return 0;
}
