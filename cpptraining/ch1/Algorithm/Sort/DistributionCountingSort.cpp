// 분포수 세기 정렬

// 중복된 키가 많고, 키의 범위가 적을 때 유리 (양의 정수만 정렬할 수 있음)
// 시간 복잡도 O(N)
// 공간 복잡도 O(N+M)

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

	int arr[10] = { 1,4,2,5,4,3,1,2,1,4 }; // 1에서 5까지의 수
	int copyArr[10] = { 0, };
	int countArr[5] = { 0, }; // 1~5 범위의 숫자를 담을 배열 따라서 5

	for (int i = 0; i < 10; ++i) {
		int idx = arr[i];
		++countArr[idx - 1]; // 빈도 계산
	}
	cout << "카운트 배열 빈도 계산 후\n";
	Print(countArr, 5);
	
	for (int i = 0; i < 5; ++i) {
		if (i == 0)
			continue;
		int count = countArr[i] + countArr[i-1];
		countArr[i] = count; // 누적 계산
	}
	cout << "카운트 배열 누적 계산 후\n";
	Print(countArr, 5);

	//
	for (int i = 0; i < 10; ++i) {
		int value = arr[i];
		int destIdx = countArr[value - 1];
		--countArr[value - 1];
		copyArr[destIdx - 1] = value;
	}

	cout << "\n복사 전\n";
	Print(arr, 10);

	for (int i = 0; i < 10; ++i)
		arr[i] = copyArr[i];

	cout << "복사 후\n";
	Print(arr, 10);

	return 0;
}