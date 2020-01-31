#include <iostream>
#include <vector>
using namespace std;

// pair training
int main() {
	//////////////// vector pair 이용 예제 1
	vector<pair<int, int>> vec;
	vec.push_back(make_pair(4, 6));
	vec.push_back(make_pair(7, 8));

	// 출력
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i].first << vec[i].second << '\n'; // 출력은  first와 second로 가능
	}


	cout << '\n';


	//////////////// vector2 pair 이용 예제 2
	vector<pair<int, char>> vec2 = { {1,'a'}, {2,'b'} };
	vec2.push_back(make_pair(3, 'c'));


	// iterator를 이용한 출력
	vector<pair<int, char>>::iterator iter = vec2.begin();
	vector<pair<int, char>>::iterator iterEnd = vec2.end();

	for (iter; iter != iterEnd; ++iter) {
		cout << iter->first << iter->second << '\n';
	}

	return 0;
}