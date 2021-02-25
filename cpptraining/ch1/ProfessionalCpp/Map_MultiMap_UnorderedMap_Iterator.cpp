#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	// 중복가능한 키값의 바이너리 이진트리 형태의 맵
	multimap<int, int> m;
	m.insert(make_pair(4, 2));
	m.insert(make_pair(4, 4));
	m.insert(make_pair(4, 1));
	m.insert(make_pair(1, 2));
	m.insert(make_pair(1, 5));
	m.insert(make_pair(1, 23));
	m.insert(make_pair(1, 72));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 2));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(0, 2));
	m.insert(make_pair(0, 1));
	m.insert(make_pair(0, 2));
	m.insert(make_pair(0, 3));

	multimap<int, int>::iterator iter, lower, up;

	iter = m.begin(); // 0

	// 같은 키를 가진 항목만 순회할 수 있는 반복자  lower_bound(), upper_bound()
	lower = m.lower_bound(iter->first); // 중복되는 키 값의 시작을 가져옴
	up = m.upper_bound(iter->first); // 중복되는 키 값의 끝을 가져옴

	for (; lower != up; ++lower) { // 사용
		cout << lower->first << " " << lower->second << "\n";
	}

	cout << "\n";

	// 중복가능한 키값의 해시맵
	unordered_multimap<int, int> um;
	um.insert(make_pair(4, 2));
	um.insert(make_pair(4, 4));
	um.insert(make_pair(4, 1));
	um.insert(make_pair(1, 2));
	um.insert(make_pair(1, 5));
	um.insert(make_pair(1, 23));
	um.insert(make_pair(1, 72));
	um.insert(make_pair(1, 1));
	um.insert(make_pair(3, 2));
	um.insert(make_pair(2, 2));
	um.insert(make_pair(0, 2));
	um.insert(make_pair(0, 1));
	um.insert(make_pair(0, 2));
	um.insert(make_pair(0, 3));

	pair<unordered_multimap<int, int >::iterator, unordered_multimap<int, int>::iterator> pair1 = um.equal_range(0); // 키값을 입력받아 중복되는 키의 시작부터 끝의 반복자를 가져옴. first: begin(), second: end()
	for (; pair1.first != pair1.second; ++pair1.first) {
		int key = pair1.first->first;
		int value = pair1.first->second;
		cout << key << " " << value << "\n";
	}


	return 0;
}
