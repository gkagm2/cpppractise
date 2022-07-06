// Çà·Ä °ö¼À
#include <iostream>
#include <vector>
using namespace std;

void InputMat(vector<vector<int>> &mat, int a, int b) {
	mat.resize(a);
	for (int i = 0; i < mat.size(); ++i)
		mat[i].resize(b);

	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[i].size(); ++j) {
			int value;
			cin >> value;
			mat[i][j] = value;
		}
	}
}

void MulMat(vector<vector<int>> &resultMat, const vector<vector<int>> &matA, const vector<vector<int>> & matB) {
	// Resize matrix
	int sizeA, sizeB, sizeC;
	sizeA = matA.size();
	sizeB = matA[0].size();
	sizeC = matB[0].size();

	resultMat.resize(sizeA);
	for (int i = 0; i < resultMat.size(); ++i)
		resultMat[i].resize(sizeC);

	// Calculate
	for (int i = 0; i < sizeA; ++i) {
		for (int j = 0; j < sizeC; ++j) {
			for (int l = 0; l < sizeB; ++l) {
				resultMat[i][j] += matA[i][l] * matB[l][j];
			}
		}
	}
}

void PrintMat(vector<vector<int>> &mat) {
	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[i].size(); ++j)
			cout << mat[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, k;

	vector<vector<int>> aMat;
	vector<vector<int>> bMat;
	vector<vector<int>> resultMat;

	cin >> n >> m;
	InputMat(aMat, n, m);
	cin >> m >> k;
	InputMat(bMat, m, k);
	MulMat(resultMat, aMat, bMat);
	PrintMat(resultMat);

	return 0;
}