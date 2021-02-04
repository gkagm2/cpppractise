#include <iostream>
#include "DynamicArrayClass.h"
#include <vector>
#include <cassert>
#include <typeinfo>
using namespace std;

int main() {
	CVector vec0;
	vec0.PushBack(1);
	vec0.PushBack(2);
	vec0.PushBack(3);
	vec0.PushBack(4);
	vec0.PushBack(5);
	vec0.PushFront(6);
	vec0.PushFront(7);
	vec0.PushFront(8);
	vec0.PushFront(9);
	vec0.Print();
	cout << "\n";
	cout << "Size : " << vec0.Size() << "\n";
	vec0.Print();
	vec0.DeleteAt(0);
	cout << "\n";
	vec0.Print();

	cout << "3 search : " << vec0.Search(3) << "\n";
	
	cout << "is empty : " << vec0.IsEmpty() << "\n";
	vec0.DeleteAll();
	

	CVector vec;
	vec.PushBack(11);
	vec.PushBack(12);
	vec.PushBack(13);
	vec.PushBack(14);
	vec.PushBack(15);
	vec.PushBack(16);
	vec.PushBack(17);

	cout << "plus operator";
	CVector::iterator iter = vec.begin();
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
	CVector::iterator iter2 = vec.end();
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
	for (auto c : vec)
		cout << c << "-";
		
	cout << "\n";


	cout << "iter loop\n";
	iter = vec.begin();

	for (iter; iter != vec.end(); ++iter)
		cout << *iter << "-";
	cout << "\n";

	// Erase 테스트
	iter = vec.begin();
	vec.Print();
	cout << "\n";
	iter = vec.end();
	--iter;
	iter = vec.Erase(iter);

	cout << "\n";
	vec.Print();

	// error
	//iter = vec.begin();
	//iter = vec.Erase(iter);
	//cout << "\n";
	//cout << *iter;


	CVector vec1;
	CVector vec2;
	vec1.PushBack(1);
	vec1.PushBack(2);
	vec1.PushBack(3);
	vec1.PushBack(4);
	vec2.PushBack(10);
	vec2.PushBack(20);
	vec2.PushBack(30);
	vec2.PushBack(40);

	auto diter1 = vec1.begin();
	auto diter2 = vec2.begin();
	// vec1.Erase(diter2); // error


	return 0;
}