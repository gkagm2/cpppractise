// ������ ���� ����

// �ߺ��� Ű�� ����, Ű�� ������ ���� �� ���� (���� ������ ������ �� ����)
// �ð� ���⵵ O(N)
// ���� ���⵵ O(N+M)

#include <iostream>
using namespace std;

void Print(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int arr[10] = { 1,4,2,5,4,3,1,2,1,4 }; // 1���� 5������ ��
	int copyArr[10] = { 0, };
	int countArr[5] = { 0, }; // 1~5 ������ ���ڸ� ���� �迭 ���� 5

	for (int i = 0; i < 10; ++i) {
		int idx = arr[i];
		++countArr[idx - 1]; // �� ���
	}
	cout << "ī��Ʈ �迭 �� ��� ��\n";
	Print(countArr, 5);
	
	for (int i = 0; i < 5; ++i) {
		if (i == 0)
			continue;
		int count = countArr[i] + countArr[i-1];
		countArr[i] = count; // ���� ���
	}
	cout << "ī��Ʈ �迭 ���� ��� ��\n";
	Print(countArr, 5);

	//
	for (int i = 0; i < 10; ++i) {
		int value = arr[i];
		int destIdx = countArr[value - 1];
		--countArr[value - 1];
		copyArr[destIdx - 1] = value;
	}

	cout << "\n���� ��\n";
	Print(arr, 10);

	for (int i = 0; i < 10; ++i)
		arr[i] = copyArr[i];

	cout << "���� ��\n";
	Print(arr, 10);

	return 0;
}