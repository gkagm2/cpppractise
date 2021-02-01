#include <iostream>
#include "DynamicArrayClass.h"
using namespace std;

int main() {
	DynamicArrList dList;
	dList.PushBack(1);
	dList.PushBack(2);
	dList.PushBack(3);
	dList.PushBack(4);
	dList.PushBack(5);
	dList.PushFront(6);
	dList.PushFront(7);
	dList.PushFront(8);
	dList.PushFront(9);
	dList.Print();
	cout << "\n";
	cout << "Size : " << dList.Size() << "\n";
	dList.Print();
	cout << "\n";
	dList.DeleteAt(0);
	dList.Print();

	cout << "3 search : " << dList.Search(3) << "\n";
	
	cout << "is empty : " << dList.IsEmpty() << "\n";
	dList.DeleteAll();

	dList.PushBack(11);
	dList.PushBack(12);
	dList.PushBack(13);
	dList.PushBack(14);
	dList[2] = 333;
	dList.Print();
	return 0;
}