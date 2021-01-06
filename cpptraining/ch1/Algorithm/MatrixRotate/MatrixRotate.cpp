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

int main() {
	int n = 5;

	// Init
	int i = 1;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			mat[y][x] = i++;
		}
	}

	Rotate90CW(n);
	
	Draw(n);
	return 0;
}
