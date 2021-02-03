#include <iostream>
#include "DynamicArrayClass.h"
#include <vector>
#include <cassert>
#include <typeinfo>
using namespace std;

int main() {
	/*DynamicArrList dList;
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
	dList.DeleteAt(0);
	cout << "\n";
	dList.Print();

	cout << "3 search : " << dList.Search(3) << "\n";
	
	cout << "is empty : " << dList.IsEmpty() << "\n";
	dList.DeleteAll();
	*/

	DynamicArrList dList;
	dList.PushBack(11);
	dList.PushBack(12);
	dList.PushBack(13);
	dList.PushBack(14);
	dList.PushBack(15);
	dList.PushBack(16);
	dList.PushBack(17);

	cout << "plus operator";
	DynamicArrList::iterator iter = dList.begin();
	cout << *iter;
	cout << "\n";
	iter++;
	cout << "\n";
	cout << *(iter++);
	cout << "\n";
	cout << *(iter);
	cout << "\n";
	cout << *(++iter);
	cout << "\n";
	++iter;
	cout << *iter;
	cout << "\n";

	cout << "\n";
	cout << "---\n";
	cout << *iter;
	cout << "---\n";
	cout << "\n";


	cout << "minus operator";
	DynamicArrList::iterator iter2 = dList.end();
	cout << *(--iter2);
	cout << "\n";
	cout << *(iter2--);
	cout << "\n";
	cout << *(iter2);
	cout << "\n";
	--iter2;
	cout << *iter2; 
	cout << "\n";

	// 이게 되네?? 범위기반 begin()과 end()를 구현해놓으면 된다.
	for (auto c : dList)
		cout << c << "-";
		
	cout << "\n";


	cout << "iter loop\n";
	iter = dList.begin();

	for (iter; iter != dList.end(); ++iter)
		cout << *iter << "-";
	cout << "\n";

	return 0;
}