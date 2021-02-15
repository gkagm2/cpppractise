// Title : Map ������
// Developer : Sagacity Jang
// Date : 2021.02.08
#include <iostream>
#include "CBST.h"
#include <map>
using namespace std;

int main() {
	/*
	// Map�� ��� ����
	map<int, int> m; // first -> key, second -> value
	m.insert(make_pair(3, 10));
	m.insert(make_pair(1, 30));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(2, 40)); // key�� �ߺ� �ȵ�.

	// Key���� �̿��Ͽ� Ž���ϰԵǸ� O(logN)�� ���´�. ���ĵǾ��ִ� ���¿��� �̺�Ž������ ���� �����̴�.

	for (auto i : m) // key ������ ���ĵ�.
		cout << i.first << " " << i.second << "\n";
	*/

	/*const char* pC1 = "Hello";
	char arrC[30] = "Heeee";*/
	tBSTPair<int, int> p1 = Make_pair(100, 200);
	tBSTPair<int, int> p2 = Make_pair(200, 300);
	

	CBST<int, int> bstInt;
	// bstInt.Insert(Make_pair<int, int>(100, 10)); // ������� �̷��� �ؾ� ��. stl�� �����Ǿ��ִ� make_pair�� template��
	bstInt.Insert(Make_pair(100, 11));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(98, 12));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(97, 13));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(99, 13));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(106, 13));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(105, 13));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(101, 13));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(103, 13));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(102, 13));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(104, 13));  // ���ڿ��ʿ��� ������ �����.?


	CBST<int, int>::iterator iter = bstInt.end();

	--iter;
	--iter;
	--iter;
	++iter;
	++iter;
	++iter;



	for (; iter != bstInt.end(); ++iter) {
		cout << iter->first << " ";
	}



	iter = bstInt.find(100);
	iter = bstInt.erase(iter);


	//cout << "key : " << iter->first << " value : " << iter->second << "\n";
	//++iter;
	//cout << "key : " << iter->first << " value : " << iter->second << "\n";
	//++iter;
	for (auto i : bstInt) {
		cout << "key : " << i.first << " value : " << i.second << "\n";
	}

	if (iter == bstInt.end()) {
		cout << "end";
	}
	else {
		cout << "key : " << (*iter).first << " value : " << (*iter).second << "\n";
		cout << "key : " << iter->first << " value : " << iter->second << "\n";
	}

	bstInt.clear();

	map<int, int> m;
	m.insert(make_pair(10,2300));
	m.insert(make_pair(12, 2300)); 
	m.insert(make_pair(11, 2300));
	m.insert(make_pair(9, 2300));
	auto i = m.begin();
	++i;
	++i;
	++i;

	for (auto t : m) {
		cout << t.first << " " << t.second << "\n";
	}
	i = m.find(10);
	i =m.erase(i);

	for (; i != m.end(); ++i) {
		cout << i->first << " " << i->second << "\n";
	}
	cout << "\n";

	return 0;
}