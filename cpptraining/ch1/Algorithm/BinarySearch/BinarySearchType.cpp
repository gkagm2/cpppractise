#include <iostream>
using namespace std;

// Type 1
bool BinarySearch1(int arr[], int size, int x) {
	int l = 0, r = size - 1;

	while (l <= r) {
		int k = (l + r) / 2;
		if (arr[k] == x) {
			return true; // found
		}
		if (arr[k] > x)
			r = k - 1;
		else
			l = k + 1;
	}
	return false; // not found
}

// Type 2
bool BinarySearch2(int arr[], int size, int x) {
	int k = 0;

	for (int b = size / 2; b >= 1; b /= 2) {
		while (k + b < size && arr[k + b] <= x)
			k += b;
	}

	if (arr[k] == x)
		return true;
	return false;
}


int main() {

	int arr[10] = { 1,2,3,4,8,9,11,12,13,14};
	//cout << BinarySearch1(arr, 10, 7);
	cout << BinarySearch2(arr, 10, 8);


	return 0;
}