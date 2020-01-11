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

// preorder traversal 전위 순회 (루트 노드를 먼저 순회)
void PreorderTraversal(BTreeNode* bt);

// inorder traversal 중위 순회 (루트 노드를 중간에 순회)
void InorderTraversal(BTreeNode* bt);

// postorder traversal 후위 순회 (루트 노드를 마지막에 순회)
void PostorderTraversal(BTreeNode* bt);

