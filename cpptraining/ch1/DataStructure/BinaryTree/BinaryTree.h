#pragma once

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;

BTreeNode* MakeBTreeNode();
BTData GetData(BTreeNode* br);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void DeleteTree(BTreeNode* bt);

// preorder traversal ���� ��ȸ (��Ʈ ��带 ���� ��ȸ)
void PreorderTraversal(BTreeNode* bt);

// inorder traversal ���� ��ȸ (��Ʈ ��带 �߰��� ��ȸ)
void InorderTraversal(BTreeNode* bt);

// postorder traversal ���� ��ȸ (��Ʈ ��带 �������� ��ȸ)
void PostorderTraversal(BTreeNode* bt);

