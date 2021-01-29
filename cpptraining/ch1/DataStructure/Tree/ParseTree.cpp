#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "BinaryTree_Template.h"
using namespace std;

class ParseTree : public BinaryTree<string> {
public:
	void BuildParseTree(const string& strPostfix);
	bool IsOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}
};

void ParseTree::BuildParseTree(const string& strPostfix) {
	Node *pNode;
	int i = 0;
	stack<Node*> stk;
	RemoveAll();
	while (strPostfix[i]) {
		while (strPostfix[i] == ' ') {
			++i;
		}
		pNode = new Node;
		if (IsOperator(strPostfix[i])) {
			pNode->data = strPostfix[i];
			++i;
			pNode->pRight = stk.top();
			stk.pop();
			pNode->pLeft = stk.top();
			stk.pop();
		}
		else {
			do {
				pNode->data += strPostfix[i];
				++i;
			} while (strPostfix[i] != ' ' && i < strPostfix.size());
			pNode->pLeft = m_pNodeTail;
			pNode->pRight = m_pNodeTail;
		}
		stk.push(pNode);
	}
	m_pNodeHead->pLeft = stk.top();
	stk.pop();
}

int main() {

	ParseTree tree;
	string strPostfix = "A B + C D - * E / F G * +";
	tree.BuildParseTree(strPostfix);

	tree.PreOrderTraversal();
	return 0;
}