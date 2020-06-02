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
	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			pM[4 * i + j] = pA[4 * i + j] + pB[4 * i + j];
		}
	}
	memcpy(&q, pM, sizeof(Matrix4x4));
}



/*
// 행렬 곱셈
void MatrixMultiply(Matrix4x4& q, Matrix4x4& a, Matrix4x4& b) {
	float* pA = (float*)&b;
	float* pB = (float*)&b;
	float pM[16];

	memset(pM, 0, sizeof(pM));

	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++i) {
			
		}
	}
}
*/

// 행렬 내적


// 행렬 외적


// 역행렬




int main() {

	float pM[16];

	memset(pM, 0, sizeof(pM));
	cout << sizeof(pM) << '\n';

	Matrix4x4 m1;
	Matrix4x4 m2;
	Matrix4x4 m3;

	SetIdentityMatrix4x4(m1);

	// Matrix Plus test
	MatrixPlus(m3, m2, m1);
	float* p3 = (float*)&m3;
	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			cout << p3[4*i + j];
		}
		cout << '\n';
	}

	return 0;
}
