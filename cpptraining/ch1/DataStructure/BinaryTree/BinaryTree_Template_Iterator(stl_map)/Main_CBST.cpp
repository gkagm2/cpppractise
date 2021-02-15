// Title : Map ������
// Developer : Sagacity Jang
// Date : 2021.02.08
#include <iostream>
#include "CBST.h"
#include <set>
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
	bstInt.Insert(Make_pair(200, 12));  // ���ڿ��ʿ��� ������ �����.?
	bstInt.Insert(Make_pair(300, 13));  // ���ڿ��ʿ��� ������ �����.?


	CBST<int, int>::iterator iter = bstInt.begin();

	iter = bstInt.find(100);
	if (iter == bstInt.end()) {
		cout << "end";
	}
	else {
		cout << "key : " << (*iter).first << " value : " << (*iter).second << "\n";
		cout << "key : " << iter->first << " value : " << iter->second << "\n";
	}


	//set<int, int> s;
	//s.insert(12, 1);
	//auto i = s.begin();


	return 0;
}