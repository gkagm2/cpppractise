// Matrix를 이용한 샘플 코드
#include "GameEngine.cpp"

void Sample_PlusMatrix() {
	float pM[16];

	memset(pM, 0, sizeof(pM));
	cout << sizeof(pM) << '\n';

	Matrix4x4 m1;
	Matrix4x4 m2;
	Matrix4x4 m3;

	SetIdentityMatrix4x4(m1);

	// Matrix Plus test
	MatrixPlus(m3, m2, m1);
	cout << "matrix plus" << '\n';
	PrintMatrix(m3);
}

void Sample_MinusMatrix() {
	float pM[16];

	memset(pM, 0, sizeof(pM));
	cout << sizeof(pM) << '\n';

	Matrix4x4 m1;
	memset(&m1, 0, sizeof(Matrix4x4));
	Matrix4x4 m2;
	memset(&m2, 0, sizeof(Matrix4x4));
	Matrix4x4 m3;
	memset(&m3, 0, sizeof(Matrix4x4));

	m1._11 = 2;
	m1._22 = 2;
	m1._33 = 2;
	m1._12 = 3;
	
	m2._11 = 10;
	m2._22 = 10;
	m2._33 = 10;
	m2._12 = 1;

	MatrixMinus(m3, m2, m1);

	cout << "matrix minus" << '\n';
	PrintMatrix(m3);
}

void Sample_Multiply() {
	float pM[16];

	memset(pM, 0, sizeof(pM));
	cout << sizeof(pM) << '\n';

	Matrix4x4 m1;
	Matrix4x4 m2;
	Matrix4x4 m3;

	m1._11 = 2;
	m1._22 = 2;
	m1._33 = 2;
	m1._12 = 3;

	m2._11 = 10;
	m2._22 = 10;
	m2._33 = 10;
	m2._12 = 1;

	MatrixMultiply(m3, m2, m1);

	cout << "matrix multply" << '\n';
	PrintMatrix(m3);
}

int main() {
	Sample_PlusMatrix();
	cout << '\n';
	Sample_MinusMatrix();
	cout << '\n';
	Sample_Multiply();
	return 0;
}
