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
	vector<int>::iterator iter; // �ݺ��ڸ� ����
	iter = find(v.begin(), v.end(), 33); // [begin, end] ���� 33�� ã��

	if (iter == v.end())
		cout << "33�� �����ϴ�." << endl;
	else
		cout << *iter << endl;

	iter = find(v.begin(), v.end(), 66); // [begin, end] ���� 66�� ã��
	if (iter == v.end()) 
		cout << "66�� �����ϴ�." << endl;
	else {
		cout << *iter << endl;
	}
	return 0;
}
