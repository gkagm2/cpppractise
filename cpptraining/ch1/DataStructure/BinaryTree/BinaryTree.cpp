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
	cout << GetData(GetLeftSubTree(bt1)) << endl;

	return 0;
}

BTreeNode * MakeBTreeNode(BTData = NULL)
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