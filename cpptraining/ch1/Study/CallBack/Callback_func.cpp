#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ForEach(vector<int>& vec, int(*Func)(int)) {
	for (int value : vec) {
		Func(value);
	}
}

int Print(int num) {
	cout << num << " ";
	return 0;
}

int Print2(int num) {
	cout << num << "\n";
	return 0;
}

int main() {
	vector<int> vec = { 1,6,4,2,5,3 };
	ForEach(vec, Print);
	ForEach(vec, Print2);

	return 0;
}