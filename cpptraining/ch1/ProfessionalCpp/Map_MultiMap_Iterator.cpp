#include <iostream>
#include <map>
using namespace std;

int main()
{
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

	return 0;
}
