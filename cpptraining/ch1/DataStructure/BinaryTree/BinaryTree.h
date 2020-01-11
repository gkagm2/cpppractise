#pragma once

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;

BTreeNode* MakeBTreeNode(BTData = NULL);
BTData GetData(BTreeNode* br);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

// preorder traversal ���� ��ȸ (��Ʈ ��带 ���� ��ȸ)
void PreorderTraversal() {
	// middle node traversal
	// left sub node traversal
	// right sub node traversal
}

// inorder traversal ���� ��ȸ (��Ʈ ��带 �߰��� ��ȸ)
void InorderTraversal() {
	// left sub node traversal
	// middle node traversal
	// right sub node traversal
}
// postorder traversal ���� ��ȸ (��Ʈ ��带 �������� ��ȸ)
void PostorderTraversal() {
	// left sub node traversal
	// right sub node traversal
	// middle node traversal
}

