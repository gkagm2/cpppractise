#include <iostream>
using namespace std;

int main() {

	// *
	// **
	// ***
	// ****
	// *****
	for(int i=0; i < 5; ++i){
		for (int j = 0; j < i + 1; ++j) {
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	//*****
	//****
	//***
	//**
	//*
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5 - i; ++j) {
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	//   *		���� 3, �� : 1
	//  ***		���� 2, �� : 3
	// *****	���� 1, �� : 5
	//*******	���� 0, �� : 7k
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3 - i; ++j) {
			cout << " ";
		}
		for (int j = 0; j < i * 2 + 1; ++j) {
			cout << "*";
		}
		cout << endl;
	}


	cout << endl;
	//   *
	//  ***
	// *****
	//*******
	// *****
	//  ***
	//   *
	int iLine = 7;
	int iCount = 0;
	for (int i = 0; i < iLine; ++i) {

		iCount = i;

		if (i > iLine / 2) {
			iCount = iLine - 1 - i;
		}

		for (int j = 0; j < 3 - iCount; ++j) {
			cout << "1";
		}
		for (int j = 0; j < iCount * 2 + 1; ++j) {
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
	return 0;
}