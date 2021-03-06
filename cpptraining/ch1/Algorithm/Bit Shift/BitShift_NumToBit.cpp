#include <iostream>
using namespace std;

void PrintBit(const int &num, const int &bitSize) {
	cout << "number : " << num << " -> \tbit : ";
	for (int i = bitSize - 1; i >= 0; --i) {
		if (num & (1 << i))  cout << "1";
		else cout << "0";
	}
	cout << "\n";
}

// The formula x & ~(1 << k) sets the kth bit of x to zero,
int BitToZero(const int &num, const int &zeroSettingBit) {
	int number = num & ~(1 << zeroSettingBit);
	PrintBit(number, 32);
	return number;
}

// The formula x | (1 << k) sets the kth bit of x to one
int BitToOne(const int &num, const int &oneSettingBit) {
	int number = num | (1 << oneSettingBit);
	PrintBit(number, 32);
	return 0;
}

// formula x ^ (1 << k) inverts the kth bit of x.
int InvertBit(const int &num, const int &kThBit) {
	int number = num ^ (1 << kThBit);
	PrintBit(number, 32);
	return number;
}

// The formula x & (x��1) sets the last one bit of x to zero
int LastOneBitToZero(const int &num) {
	int number = num & (num - 1);
	PrintBit(number, 32);
	return number;
}

// The formula x & -x sets all the one bit to zero, except for the last one bit.
int AllTheOneBitToZero(const int &num) {
	int number = num % -num;
	PrintBit(number, 32);
	return number;
}

// The formula x | (x - 1) inverts all the bits after the last one bit
int InvertsAllTheBitsAfterLastOneBit(const int &num) {
	int number = num | (num - 1);
	PrintBit(number, 32);
	return number;
}

// A positive number x is a power of two exactly when x & (x - 1) ==  0
// ��� x�� x & (x - 1) == 0 �� �� 2�� �ŵ� ����
void CheckPowerOfTwo(const int &num) {
	int checkNum = num & (num - 1);
	if (checkNum == 0) cout << num << "is power of two\n";
	else cout << num << "isn't power of two\n";
	PrintBit(num & (num - 1), 32);
}

// Prints all elements that belong to the set
void PrintsAllElements(const int &num) {
	for (int i = 0; i < 32; ++i) {
		if (num & (1 << i))
			cout << i << "|";
	}
	cout << "\n";
}

int GetOneCountFromBit(const int &num) {
	int oneCnt = 0;
	for (int i = 0; i < 32; ++i) {
		if ((num & (1 << i)))
			++oneCnt;
	}
	return oneCnt;
}
int GetZeroCountFromBit(const int &num) {
	int zeroCnt = 0;
	for (int i = 0; i < 32; ++i) {
		if (!(num & (1 << i)))
			++zeroCnt;
	}
	return zeroCnt;
}


// Iterating through subsets

// The following code goes through the subsets of {0,1,...,n��1}
void Iterating1(const int &n) {
	for (int b = 0; b < (1 << n); ++b) {
		PrintBit(b, n);
	}
	cout << "\n";
}

// The following code goes through the subsets with exactly k elements
void Iterating2(const int &n, const int &k) {
	for (int b = 0; b < (1 << n); ++b) {
		if (GetOneCountFromBit(b) == k) {
			PrintBit(b, n);
		}
	}
	cout << "\n";
}

// The following code goes through the subsets of a set x
void Iterating3(const int &x) {
	int b = 0;
	do {
		PrintBit(b, x);
	} while (b = (b - x) & x);
	cout << "\n";
}




int main() {
	int num = 9;
	
	cout << "Original bit\n";
	PrintBit(num, 32);

	cout << "Change zero\n";
	BitToZero(num, 1);
	BitToZero(num, 2);

	cout << "Change one\n";
	BitToOne(num, 1);
	BitToOne(num, 0);

	cout << "Invert bit\n";
	InvertBit(num, 1);
	InvertBit(num, 0);

	cout << "LastOneBitToZero\n";
	LastOneBitToZero(num);


	cout << "AllTheOneBitToZero\n";
	AllTheOneBitToZero(num);

	cout << "InvertsAllBitsLastOneBit\n";
	InvertsAllTheBitsAfterLastOneBit(num);

	cout << "~~~~~~\n";
	CheckPowerOfTwo(num);

	cout << "Prints all elements that belong to set\n";
	PrintsAllElements(num);

	cout << "Counts the number of bits set to zero.\n";
	cout << GetZeroCountFromBit(num) << "\n";

	cout << "Counts the number of bits set to one.\n";
	cout << GetOneCountFromBit(num) << "\n";

	/////////////// Iterating
	cout << "The following code goes through the subsets of {0,1,...,n��1}\n";
	Iterating1(4);

	cout << "The following code goes through the subsets with exactly k elements\n";
	Iterating2(4, 3);

	cout << "The following code goes through the subsets of a set x\n";
	Iterating3(60);

	return 0;
}