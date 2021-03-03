#include <iostream>
#include <assert.h>
using namespace std;

// 2-3-4 트리와 Red-Black 트리
//둘 다 balanced tree임

// 이진트로리 2-3-4 트리의 Balanced 특성을 구현한 것
// 빨간 노드와 검정노드 두가지가 있음
// 빨간 노드는 검정노드와 결합되는 의미
// Red-Edge, Black-Edge로 표현하기도 함

/*
Red-Black Tree의 성질
- 부모노드는 왼쪽 서브트리보다 크고 오른쪽 서브트리보다 작다.
  - 이진 검색트리와 동일한 구조
- Root에서 Leaf로 가는 경로의 검정노드의 수는 모두 같다.
- 새로 삽입되는 노드는 Leaf에 위치하며 빨간노드이다.
- 경로상에 연이어 두개의 빨간노드가 있을 수 없다. (회전 필요)
- 부모의 두 자식노드가 모두 빨간노드이면, 부모를 빨간노드로하고 자식은 검정노드로 바뀔 수 있다.(색상 변환)
- Root노드는 빨간노드일 수 없다.(검정으로 변환)
- 빨간노드는 자식이 없던가, 있다면 두개의 검정노드여야 한다.
- 검정노드는 자식이 없던가, 있다면 하나의 빨간노드나  두개의 빨간 노드나 두개의 검정노드를 가진다.
  - 즉 단 하나의 검정노드를 자식으로 가질 수 없다.
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

	Node<T>* _InorderSuccessor(Node<T>* _pNode); // node보다 크며 가장 가까운 값.
	Node<T>* _InorderPredecessor(Node<T>* _pNode); // node보다 작으며 가장 가까운 값.

public:
	void Insert(T _data);
	void Delete(T _data);
	bool Search(const T& _data, Node<T>& _retNode);
	void ShowAllNode();


	void RotateLeft(Node<T>* _pNode);
	void RotateRight(Node<T>* _pNode);

	

public:
	RedBlackTree();
	RedBlackTree(const RedBlackTree& _other); // 복사 참조
	~RedBlackTree();
};

template<typename T>
RedBlackTree<T>::RedBlackTree() :
	m_pRoot(nullptr)
{
	cout << "기본생성자\n";
}

template<typename T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree & _other)
{
	cout << "복사생성자\n";
}

template<typename T>
RedBlackTree<T>::~RedBlackTree()
{
	cout << "소멸자\n";
	// 소멸할경우 어떻게해야될까.
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
	/*			상황
			  _pNode
			  ↙		↘
		    alpha	rightChild
					↙		↘
				beta		gamma
	*/
	// root노드의 부모는 null이여야 함.
	// 노드의 오른쪽 자식이 존재해야 한다.
	if (nullptr == _pNode->link[rightchild])
		return;
	 
	Node<T>* pRightChild = _pNode->link[rightchild];
	Node<T>* pBeta = pRightChild->link[leftchild];
	_pNode->link[rightchild] = pBeta; // rightchild의 왼쪽자식인 beta를  _pNode의 오른쪽 자식으로 넣어줌.
	pBeta->link[parent] = _pNode; // beta의 부모를 _pNode로 해준다.

	pRightChild->link[parent] = _pNode->link[parent];// _pNode의 부모를 rightChild로 해준다.
	if (nullptr == _pNode->link[parent]) { // 부모가 없으면 root임
		m_pRoot = pRightChild;
	}
	else if (_pNode == _pNode->link[parent]->link[leftchild]) // pNode가 오른쪽 부모의 왼쪽 자식이면
		_pNode->link[parent]->link[leftchild] = pRightChild;
	else // pNode가 오른쪽 부모의 왼쪽 자식이면 
		_pNode->link[parent]->link[rightchild] = pRightChild;
	
	pRightChild->link[leftchild] = _pNode;
	_pNode->link[parent] = pRightChild;
}

template<typename T>
void RedBlackTree<T>::RotateRight(Node<T>* _pNode)
{
	/*			상황
			  _pNode
			  ↙		↘
		leftChild	alpha
		↙		↘
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
