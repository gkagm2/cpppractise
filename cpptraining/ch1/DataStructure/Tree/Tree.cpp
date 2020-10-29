#include <iostream>
using namespace std;
typedef int Data;

struct Node {
public:
	Data data;
	Node *left;
	Node *right;
}typedef *PNODE;

PNODE CreateNode(Data _data) {
	PNODE newNode = new Node();
	newNode->data = _data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

PNODE AddChild(PNODE _parrent, Data _data) {
	if (_parrent->left != nullptr && _parrent->right != nullptr)
		return nullptr;

	PNODE newNode = CreateNode(_data);

	if (_parrent->left == nullptr)
		_parrent->left = newNode;
	else if (_parrent->right == nullptr)
		_parrent->right = newNode;

	return newNode;
}

void Preorder(PNODE _pNode) {
	if (_pNode == nullptr) return;
	cout << _pNode->data << " ";
	Preorder(_pNode->left);
	Preorder(_pNode->right);
}

void Inorder(PNODE _pNode) {
	if (_pNode == nullptr) return;
	Inorder(_pNode->left);
	cout << _pNode->data << " ";
	Inorder(_pNode->right);
}

void Postorder(PNODE _pNode) {
	if (_pNode == nullptr) return;
	Postorder(_pNode->left);
	Postorder(_pNode->right);
	cout << _pNode->data << " ";
}

int main() {

	PNODE root = CreateNode(0);

	PNODE childNode1 = AddChild(root, 1);
	PNODE childNode2 = AddChild(childNode1, 2);
	PNODE childNode3 = AddChild(childNode2, 3);
	PNODE childNode4 = AddChild(childNode3, 4);
	PNODE childNode5 = AddChild(childNode4, 5);
	PNODE childNode6 = AddChild(root, 6);

	cout << "preorder" << "\n";
	Preorder(root);
	cout << "inorder" << "\n";
	Inorder(root);
	cout << "postorder" << "\n";
	Postorder(root);
	
	return 0;
}