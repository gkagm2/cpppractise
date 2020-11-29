#include <iostream>
using namespace std;

void Print_NumToBit(const int &num, const int &bitSize) {
	cout << "number : " << num << " -> bit : ";
	for (int i = bitSize - 1; i >= 0; --i) {
		if (num & (1 << i))  cout << "1";
		else cout << "0";
	}
}

int main() {
	int num = 6;
	
	Print_NumToBit(num, 32);

	return 0;
}