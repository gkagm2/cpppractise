// Game에 들어가는 매트릭스 연산을 직접 구현
#include<iostream>
#include<string>
using namespace std;

typedef unsigned short WORD;

struct Vector3 {
	float x;
	float y;
	float z;
};
struct Vector2 {
	float x;
	float y;
};


struct Matrix4x4 {
public:
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;

	Matrix4x4() {
		SetZero();
	}
	void SetZero() {
		memset(this, 0, sizeof(Matrix4x4));
		//_11 = _12 = _13 = _14 = _21 = _22 = _23 = _24 = _31 = _32 = _33 = _34 = _41 = _42 = _43 = _44 = 0.0f;
	}
};


// 매트릭스를 출력한다.
inline void PrintMatrix(Matrix4x4& m) {
	float* pM = (float*)&m;
	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			cout << pM[4 * i + j] << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}



// 단위행렬
inline void SetIdentityMatrix4x4(Matrix4x4& m) {
	m._12 = m._13 = m._14 = m._21 = m._23 = m._24 = 0.0f;
	m._31 = m._32 = m._34 = m._41 = m._42 = m._43 = 0.0f;
	m._11 = m._22 = m._33 = m._44 = 1.0f;
}

// 행렬 덧셈
void MatrixPlus(Matrix4x4& q, Matrix4x4& a, Matrix4x4& b) {
	float* pA = (float*)&a;
	float* pB = (float*)&b;
	float pM[16];
	memset(pM, 0, sizeof(Matrix4x4));

	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			pM[4 * i + j] = pA[4 * i + j] + pB[4 * i + j];
		}
	}
	memcpy(&q, pM, sizeof(Matrix4x4));
}

// 행렬 뺄셈
void MatrixMinus(Matrix4x4& q, Matrix4x4& a, Matrix4x4& b) {
	float* pA = (float*)&a;
	float* pB = (float*)&b;
	float pM[16];
	memset(pM, 0, sizeof(Matrix4x4));

	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			pM[4 * i + j] = pA[4 * i + j] - pB[4 * i + j];
		}
	}
	memcpy(&q, pM, sizeof(Matrix4x4));
}


// 행렬 곱셈
void MatrixMultiply(Matrix4x4& q, Matrix4x4& a, Matrix4x4& b) {
	float* pA = (float*)&a;
	float* pB = (float*)&b;
	float pM[16];
	memset(pM, 0, sizeof(Matrix4x4));

	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			for (WORD k = 0; k < 4; ++k) {
				pM[4 * i + j] += pA[4 * i + k] * pB[4 * k + j];
			}
		}
	}
	memcpy(&q, pM, sizeof(Matrix4x4));
}

// 이동 행렬
inline void SetTranslateMatrix(Matrix4x4& m, float tx, float ty, float tz) {
	SetIdentityMatrix4x4(m);
	m._41 = tx, m._42 = ty, m._43 = tz;
}

// 확대,축소 행렬
inline void SetScaleMatrix(Matrix4x4& m, float sx, float sy, float sz) {
	SetIdentityMatrix4x4(m);
	m._11 = sx, m._22 = sy, m._33 = sz;
}

// 회전 행렬 X
void SetRotateXMatrix(Matrix4x4& m, float fRads) {
	SetIdentityMatrix4x4(m);
	m._22 = cos(fRads);
	m._23 = sin(fRads);
	m._32 = -sin(fRads);
	m._33 = cos(fRads);
}

// 회전 행렬 Y
void SetRotateYMatrix(Matrix4x4& m, float fRads) {
	SetIdentityMatrix4x4(m);
	m._11 = cosf(fRads);
	m._13 = -sinf(fRads);
	m._31 = sinf(fRads);
	m._33 = cos(fRads);
}

// 회전 행렬 Z
void SetRotateZMatrix(Matrix4x4& m, float fRads) {
	SetIdentityMatrix4x4(m);
	m._11 = cosf(fRads);
	m._12 = sinf(fRads);
	m._21 = -sinf(fRads);
	m._22 = cos(fRads);
}

// 역행렬

// 행렬 내적


// 행렬 외적





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
