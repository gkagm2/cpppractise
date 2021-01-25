#include <iostream>
#include <vector>
using namespace std;

// 포인터로부터의 참조 하기
void separateOddsAndEvens(const int arr[], int size, int*& odds, int& numOdds, int *& evens, int& numEvens) {
	numOdds = numEvens = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1)
			++numOdds;
		else
			++numEvens;
	}

	odds = new int[numOdds];
	evens = new int[numEvens];

	int oddsPos = 0, evensPos = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1)
			odds[oddsPos++] = arr[i]; //smae -> (*odds)[oddsPos++] = arr[i];
		else
			evens[evensPos++] = arr[i];
		int t;
		t = odds[oddsPos++] = arr[i];
	}
}

// 보통같이 하는 경우
void separateOddsAndEvens2(const int arr[], int size, int** odds, int* numOdds, int ** evens, int* numEvens) {
	*numOdds = *numEvens = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1)
			++(*numOdds);
		else
			++(*numEvens);
	}

	*odds = new int[*numOdds];
	*evens = new int[*numEvens];

	int oddsPos = 0, evensPos = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1)
			(*odds)[oddsPos++] = arr[i];
		else
			(*evens)[evensPos++] = arr[i];
	}
}

// 벡터로 할 경우
void separateOddsAndEvens3(const vector<int>& arr, vector<int>& odds, vector<int>& evens) {
	int numOdds = 0, numEvens = 0;
	for (auto& i : arr) {
		if (i % 2 == 1)
			++numOdds;
		else
			++numEvens;
	}
	odds.reserve(numOdds);
	evens.reserve(numEvens);
	for (auto& i : arr) {
		if (i % 2 == 1)
			odds.push_back(i);
		else
			evens.push_back(i);
	}
}

int main() {

	int *odds = nullptr;
	int *evens = nullptr;
	int numOdds, numEvens;

	int arr[10] = { 1,2,3,4,5,9,8,7,6,10 };
	separateOddsAndEvens(arr, 10, odds, numOdds, evens, numEvens);

	//separateOddsAndEvens2(arr, 10, &odds, &numOdds, &evens, &numEvens);

	for (int i = 0; i < numOdds; ++i)
		cout << odds[i] << " ";
	cout << "\n";

	for (int i = 0; i < numEvens; ++i)
		cout << evens[i] << " ";
	cout << "\n";

	delete odds;
	delete evens;

	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> oddsVec, evensVec;
	separateOddsAndEvens3(vec, oddsVec, evensVec);

	return 0;
}