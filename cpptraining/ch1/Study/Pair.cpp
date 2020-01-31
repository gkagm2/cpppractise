#include <iostream>
#include <vector>
using namespace std;

// pair training
int main() {
	//////////////// vector pair �̿� ���� 1
	vector<pair<int, int>> vec;
	vec.push_back(make_pair(4, 6));
	vec.push_back(make_pair(7, 8));

	// ���
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i].first << vec[i].second << '\n'; // �����  first�� second�� ����
	}


	cout << '\n';


	//////////////// vector2 pair �̿� ���� 2
	vector<pair<int, char>> vec2 = { {1,'a'}, {2,'b'} };
	vec2.push_back(make_pair(3, 'c'));


	// iterator�� �̿��� ���
	vector<pair<int, char>>::iterator iter = vec2.begin();
	vector<pair<int, char>>::iterator iterEnd = vec2.end();

	for (iter; iter != iterEnd; ++iter) {
		cout << iter->first << iter->second << '\n';
	}

	return 0;
}