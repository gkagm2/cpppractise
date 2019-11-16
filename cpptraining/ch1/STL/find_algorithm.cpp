#include <iostream>
#include <vector> // vector
#include <algorithm> // find algorithm

using namespace std;

int main() {
		
	vector<int> v;
	
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);
	v.push_back(55);
	v.pop_back();

	cout << v.empty() << endl;

	cout << v.size() << endl;
	vector<int>::iterator iter; // 반복자만 생성
	iter = find(v.begin(), v.end(), 33); // [begin, end] 에서 33을 찾기

	if (iter == v.end())
		cout << "33이 없습니다." << endl;
	else
		cout << *iter << endl;

	iter = find(v.begin(), v.end(), 66); // [begin, end] 에서 66을 찾기
	if (iter == v.end()) 
		cout << "66이 없습니다." << endl;
	else {
		cout << *iter << endl;
	}
	return 0;
}
