#include <iostream>
#include "DoubleLinkedListClass_Template.h"
#include <list>
using namespace std;

int main() {
	CDoubleLinkedList<int> mylist;
	mylist.PushBack(5);
	mylist.PushBack(4);
	mylist.PushBack(3);
	mylist.PushBack(2);
	mylist.PushBack(1);
	mylist.PushFront(9);
	mylist.PushFront(8);
	mylist.PushFront(7);
	mylist.PushFront(6);
	mylist.Print();
	cout << "\n";
	for (int i = 0; i < mylist.Size(); ++i)
		cout << mylist[i] << "\n";

	for (int i = 0; i < mylist.Size(); ++i)
		cout << mylist.At(i) << "\n";

	cout << "3 element search : " << mylist.Search(3) << "\n";

	mylist.DeleteAll();
	cout << "is empty ? : " << mylist.IsEmpty() << "\n";
	mylist.PushBack(1);
	mylist.PushBack(2);
	mylist.PushBack(3);
	mylist.PushBack(4);
	mylist.PushBack(5);
	cout << mylist[0];

	cout << "\n\n";
	cout << mylist.Size() << "\n";

	mylist.Print();
	cout << "\n";
	cout << "\n";
	cout << "\n";

	CDoubleLinkedList<int>::iterator iterBegin = mylist.begin();
	CDoubleLinkedList<int>::iterator iterEnd = mylist.end();
	for (; iterBegin != iterEnd; ++iterBegin) {
		cout << *iterBegin << " ";
	}
	
	//Erase 테스트
	cout << "\n";
	iterBegin = mylist.begin();
	++iterBegin;
	--iterBegin;

	mylist.Erase(iterBegin);
	cout << "\n";
	cout << *iterBegin;
	cout << "\n";
	mylist.Print();
	cout << "\n";

	//Insert 테스트
	CDoubleLinkedList<int> t;
	auto tIter = t.begin();
	t.Insert(tIter, 4);
	t.Insert(tIter, 3);
	t.Print();
	tIter--;
	cout << *tIter;
	
	return 0;
}