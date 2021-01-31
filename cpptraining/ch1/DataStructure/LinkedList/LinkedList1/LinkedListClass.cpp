#pragma once
#include <iostream>
#include "LinkedListClass.h"

void LinkedList::DeleteAll()
{
	Node* pIterNode = pNodeHead;
	while (pIterNode != nullptr) {
		Node* pTempNode = pIterNode;
		pIterNode = pIterNode->link;
		delete pTempNode;
	}
	pNodeHead = nullptr;
	mCount = 0;
}

void LinkedList::DeleteAt(int _idx)
{
	if (_idx < 0 || _idx >= mCount || mCount == 0)
		return;

	Node* delNode = nullptr;
	if (_idx == 0) {
		delNode = pNodeHead;
		pNodeHead = pNodeHead->link;
	}
	else {
		Node* tempNode = pNodeHead;
		for (int i = 0; i < _idx - 1; ++i)
			tempNode = tempNode->link;
		delNode = tempNode->link;
		tempNode->link = delNode->link;
	}
	delete delNode;
	--mCount;
}	

Node* LinkedList::CreateNode(const Data & _data)
{
	Node* newNode = new Node;
	newNode->data = _data;
	newNode->link = nullptr;
	return newNode;
}

LinkedList::LinkedList() :
	mCount(0),
	pNodeHead(nullptr)
{
}

LinkedList::~LinkedList()
{
	DeleteAll();
}

void LinkedList::PushBack(const Data& _data)
{
	Node* pNewNode = CreateNode(_data);
	if (pNodeHead == nullptr)
		pNodeHead = pNewNode;
	else {
		Node* pIterNode = pNodeHead;
		while (pIterNode->link != nullptr)
			pIterNode = pIterNode->link;
		pIterNode->link = pNewNode;
	}

	++mCount;
}

void LinkedList::PushFront(const Data& _data)
{
	Node *pNewNode = CreateNode(_data);
	if (pNodeHead == nullptr)
		pNodeHead = pNewNode;
	else {
		pNewNode->link = pNodeHead;
		pNodeHead = pNewNode;
	}

	++mCount;
}

bool LinkedList::Search(const Data & _data)
{
	Node* pIterNode = pNodeHead;
	while (pIterNode != nullptr) {
		if (pIterNode->data == _data)
			return true;
		pIterNode = pIterNode->link;
	}
	return false;
}

bool LinkedList::IsEmpty()
{
	return mCount > 0;
}

const int LinkedList::Size()
{
	return mCount;
}

void LinkedList::Print()
{
	Node* pIterNode = pNodeHead;
	while (pIterNode != nullptr) {
		std::cout << pIterNode->data << "->";
		pIterNode = pIterNode->link;
	}
}

const Data & LinkedList::At(int _idx)
try {
	if (_idx < 0 || _idx >= mCount || mCount == 0)
		throw __LINE__;

	Node* pIterNode = pNodeHead;
	for (int i = 0; i < _idx; ++i)
		pIterNode = pIterNode->link;
	return pIterNode->data;
}
catch (...) {
	std::cout << "ERROR - file : " __FILE__ << "\n" << __FUNCTION__ << "\n";
}

const Data & LinkedList::operator[](int _idx)
try {
	if (_idx < 0 || _idx >= mCount || mCount == 0)
		throw __LINE__;

	Node* pIterNode = pNodeHead;
	for (int i = 0; i < _idx; ++i)
		pIterNode = pIterNode->link;
	return pIterNode->data;
}
catch (...) {
	std::cout << "ERROR - file : " __FILE__ << "\n" << __FUNCTION__ << "\n";
}
