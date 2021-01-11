#include <iostream>
#include <Windows.h>
using namespace std;
int mat[10][10];

void Draw(int n) {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cout << mat[y][x] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

// Rotate 90 degree CW
void Rotate90CW(int n) {
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - 1 - i; j++)
		{
			int Top = mat[i][j]; // Top
			mat[i][j] = mat[n - 1 - j][i]; // top < left
			mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j]; // left < bottom
			mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i]; // bottom < right
			mat[j][n - 1 - i] = Top; // right < Top
		}
	}
}

void Rotate90CWCopy(int n) {
	int **pMap = new int*[n];
	for (int i = 0; i < n; ++i)
		pMap[i] = new int[n];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			pMap[j][n - i - 1] = mat[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			mat[i][j] = pMap[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
		delete [] pMap[i];
	delete[] pMap;
}


// Rotate 90 degree CCW
void Rotate90CCW(int n) {
	for (int i = 0; i < n ; ++i) {
		for (int j = i; j < n - 1 - i; ++j) {
			int top = mat[i][j];
			mat[i][j] = mat[j][n - 1 - i]; // r -> t
			mat[j][n-1-i] = mat[n - 1 - i][n - 1 - j]; // b -> r
			mat[n-1-i][n -1 -j] = mat[n - 1 - j][i]; // l -> b
			mat[n - 1 - j][i] = top; // t - > l
		}
	}
}

void Rotate90CCWCopy(int n) {
	int **pMap = new int*[n];
	for (int i = 0; i < n; ++i)
		pMap[i] = new int[n];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			pMap[n - j - 1][i] = mat[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			mat[i][j] = pMap[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
		delete[] pMap[i];
	delete[] pMap;
}

int main() {
	int n = 5;

	// Init
	int i = 1;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			mat[y][x] = i++;
		}
	}

	Draw(n);
	Rotate90CW(n);
	Draw(n);
	Rotate90CWCopy(n);
	Draw(n);

	Rotate90CCWCopy(n);
	Draw(n);
	Draw(n);
	Rotate90CCW(n);
	Draw(n);
	return 0;
}
