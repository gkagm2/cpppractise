// Title : Map 만들어보기
// Developer : Sagacity Jang
// Date : 2021.02.08
#include <iostream>
#include "CBST.h"
#include <map>
using namespace std;

int main() {
	/*
	// Map의 사용 예시
	map<int, int> m; // first -> key, second -> value
	m.insert(make_pair(3, 10));
	m.insert(make_pair(1, 30));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(2, 40)); // key값 중복 안됨.

	// Key값을 이용하여 탐색하게되면 O(logN)이 나온다. 정렬되어있는 상태에서 이분탐색으로 들어가기 때문이다.

	for (auto i : m) // key 값으로 정렬됨.
		cout << i.first << " " << i.second << "\n";
	*/

	/*const char* pC1 = "Hello";
	char arrC[30] = "Heeee";*/
	tBSTPair<int, int> p1 = Make_pair(100, 200);
	tBSTPair<int, int> p2 = Make_pair(200, 300);
	

	CBST<int, int> bstInt;
	// bstInt.Insert(Make_pair<int, int>(100, 10)); // 원래라면 이렇게 해야 함. stl에 구현되어있는 make_pair도 template임
	bstInt.Insert(Make_pair(100, 11));  // 문자열쪽에서 문제가 생긴다.?
	bstInt.Insert(Make_pair(50, 12));  // 문자열쪽에서 문제가 생긴다.?
	bstInt.Insert(Make_pair(20, 13));  // 문자열쪽에서 문제가 생긴다.?
	bstInt.Insert(Make_pair(55, 13));  // 문자열쪽에서 문제가 생긴다.?s


	CBST<int, int>::iterator iter = bstInt.begin();

	for (; iter != bstInt.end(); ++iter) {
		cout << iter->first << " ";
	}



	iter = bstInt.find(100);
	if (iter == bstInt.end()) {
		cout << "end";
	}
	else {
		cout << "key : " << (*iter).first << " value : " << (*iter).second << "\n";
		cout << "key : " << iter->first << " value : " << iter->second << "\n";
	}


	map<int, int> m;
	m.insert(make_pair(10,2300));
	m.insert(make_pair(12, 2300)); 
	m.insert(make_pair(11, 2300));
	m.insert(make_pair(9, 2300));
	
	auto i = m.begin();
	++i;
	++i;
	++i;
	++i;



	for (auto t : m) {
		cout << t.first << " " << t.second << "\n";
	}
	

	cout << "\n";


	return 0;
}