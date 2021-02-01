#include <iostream>
#include "LinkedListClass.h"
using namespace std;

int main() {
	LinkedList list;
	list.PushBack(5);
	list.PushBack(4);
	list.PushBack(3);
	list.PushBack(2);
	list.PushBack(1);
	list.PushFront(9);
	list.PushFront(8);
	list.PushFront(7);
	list.PushFront(6);
	list.Print();
	cout << "\n";
	for (int i = 0; i < list.Size(); ++i)
		cout << list[i] << "\n";

	for (int i = 0; i < list.Size(); ++i)
		cout << list.At(i) << "\n";

	cout << "3 element search : " << list.Search(3) << "\n";

	list.DeleteAll();
	cout << "is empty ? : " << list.IsEmpty() << "\n";
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	cout << list[0];

	cout << "\n\n";
	cout << list.Size() << "\n";

	list.Print();
	cout << "\n";
	list.DeleteAt(0);
	list.Print();
	cout << "\n";

	list[1] = 88;
	list.Print();
	// iterator ? 
	/*for(auto c : list) {

	}*/
	

	return 0;
}