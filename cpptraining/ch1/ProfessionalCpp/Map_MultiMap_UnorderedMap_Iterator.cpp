#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	// �ߺ������� Ű���� ���̳ʸ� ����Ʈ�� ������ ��
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

	// ���� Ű�� ���� �׸� ��ȸ�� �� �ִ� �ݺ���  lower_bound(), upper_bound()
	lower = m.lower_bound(iter->first); // �ߺ��Ǵ� Ű ���� ������ ������
	up = m.upper_bound(iter->first); // �ߺ��Ǵ� Ű ���� ���� ������

	for (; lower != up; ++lower) { // ���
		cout << lower->first << " " << lower->second << "\n";
	}

	cout << "\n";

	// �ߺ������� Ű���� �ؽø�
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

	pair<unordered_multimap<int, int >::iterator, unordered_multimap<int, int>::iterator> pair1 = um.equal_range(0); // Ű���� �Է¹޾� �ߺ��Ǵ� Ű�� ���ۺ��� ���� �ݺ��ڸ� ������. first: begin(), second: end()
	for (; pair1.first != pair1.second; ++pair1.first) {
		int key = pair1.first->first;
		int value = pair1.first->second;
		cout << key << " " << value << "\n";
	}


	return 0;
}
