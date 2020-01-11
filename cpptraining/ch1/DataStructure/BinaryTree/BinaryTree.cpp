#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);

	// bt1의 왼쪽 자식 노드의 데이터 출력
	//cout << GetData(GetLeftSubTree(bt1)) << endl;
	cout << "전위 : ";
	PreorderTraversal(bt1);

	cout << endl;
	cout << "중위 : ";
	InorderTraversal(bt1);

	cout << endl;
	cout << "후위 : ";
	PostorderTraversal(bt1);

	DeleteTree(bt1);

	return 0;
}

BTreeNode * MakeBTreeNode()
{
	BTreeNode *newBTNode = new BTreeNode();
	newBTNode->left = NULL;
	newBTNode->right = NULL;
	return newBTNode;
}

BTData GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->left != NULL) {
		delete main->left;
	}
	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->right != NULL) {
		delete main->right;
	}
	main->right = sub;
}

void DeleteTree(BTreeNode * bt)
{
	if (bt == NULL) {
		return;
	}
	// 후위로 없애기 

	// left sub node traversal
	DeleteTree(bt->left);
	// right sub node traversal
	DeleteTree(bt->right);
	// middle node traversal
	cout << bt->data << " 삭제, ";
	delete bt;
}

// 전위 순회
void PreorderTraversal(BTreeNode * bt)
{
	if (bt == NULL) {
		return;
	}

	// middle node traversal
	cout << bt->data << " -> ";
	// left sub node traversal
	PreorderTraversal(bt->left);
	// right sub node traversal
	PreorderTraversal(bt->right);

}

// 중위 순회
void InorderTraversal(BTreeNode * bt)
{
	if (bt == NULL) {
		return;
	}

	// left sub node traversal
	InorderTraversal(bt->left);
	// middle node traversal
	cout << bt->data << " -> ";
	// right sub node traversal
	InorderTraversal(bt->right);
}

// 후위 순회
void PostorderTraversal(BTreeNode * bt)
{
	if (bt == NULL) {
		return;
	}

	// left sub node traversal
	PostorderTraversal(bt->left);
	// right sub node traversal
	PostorderTraversal(bt->right);
	// middle node traversal
	cout << bt->data << " -> ";
}
