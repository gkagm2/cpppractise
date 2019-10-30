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

	//   *		공백 3, 별 : 1
	//  ***		공백 2, 별 : 3
	// *****	공백 1, 별 : 5
	//*******	공백 0, 별 : 7k
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