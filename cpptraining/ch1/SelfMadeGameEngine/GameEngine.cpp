// Last Update : 2021.1.10
// Title : Sagacity Jang's game engine
// Developer : Sagacity Jang
// Email : gkagm2@gmail.com

#include <iostream>
#include <Windows.h>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

const float PI = 3.1415926f;

#define COLOR_WHITE RGB(255,255,255)
#define COLOR_GREEN RGB(0,255,0)
#define COLOR_RED RGB(255,0,0)
#define COLOR_BLUE RGB(0,0,255)

template<typename TYPE> class Vector2;
template<typename TYPE> class Vector3;

typedef Vector2<float> Vec2;
typedef Vector3<float> Vec3;
class CObject;

// all object
vector<CObject *> gObjects;


//******************* Matrix ******************//
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

// TODO (Sagacity Jang)
// 역행렬

// 행렬 내적


// 행렬 외적



//*************** Vector *************//

template<typename TYPE>
class Vector2 {
public:
	TYPE x;
	TYPE y;
public:
	Vector2() : x(0), y(0) {}
	Vector2(TYPE _x, TYPE _y) : x(_x), y(_y) {}

	// 벡터의 크기
	virtual TYPE GetLength() {
		return GetMagnitude();
	}

	// 벡터의 크기
	virtual TYPE GetMagnitude() {
		TYPE u = sqrtf(x * x + y * y);
		return u;
	}

	// 정규화 (단위벡터 만들기)
	Vector2 GetNormalized() {
		TYPE u = GetLength();
		Vector2 normalizedVec(x / u, y / u);
		return normalizedVec;
	}

	virtual Vector2 operator-(const Vector2& v) {
		Vector2 resultVec(x - v.x, y - v.y);
		return resultVec;
	}
	virtual Vector2 operator+(const Vector2& v) {
		Vector2 resultVec(x + v.x, y + v.y);
		return resultVec;
	}

	virtual void PrintPosition() {
		cout << "(" << x << "," << y << ")";
	}
};

template<typename TYPE>
class Vector3 : public Vector2<TYPE> {
public:
	TYPE z;
public:
	Vector3() : z(0) {}
	Vector3(TYPE _x, TYPE _y, TYPE _z) : z(_z), Vector2(_x, _y) {}

	// 벡터의 크기
	virtual TYPE GetMagnitude() {
		TYPE u = sqrtf(x * x + y * y + z * z);
		return u;
	}

	// 정규화 (단위벡터 만들기)
	virtual Vector3 GetNormalized() {
		TYPE u = GetLength();
		Vector3 normalizedVec(x / u, y / u, z / u);
		return normalizedVec;
	}

	Vector3 operator-(const Vector3& v) {

		Vector3 resultVec(x - v.x, y - v.y, z - v.z);
		return  resultVec;
	}

	Vector3 operator+(const Vector3& v) {
		Vector3 resultVec(x + v.x, y + v.y, z + v.z);
		return  resultVec;
	}

	void PrintPosition() {
		cout << "(" << x << "," << y << "," << z << ")";
	}
};

// 외적
Vec3 GetCross(Vec3 v1, Vec3 v2) {
	Vec3 p;
	p.x = (v1.y * v2.z - v1.z * v2.y);
	p.y = (v1.z * v2.x - v1.x * v2.z);
	p.z = (v1.x * v2.y - v1.y * v2.x);
	return p;
}

// 내적
float GetDotVector3(Vec3 v1, Vec3 v2)
{
	float scala = 0;
	scala = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return scala;
}

float GetDistance(Vec3 v1, Vec3 v2) {
	Vec3 v = v1 - v2;
	return v.GetMagnitude();
}

// --------- Math -----------
// 각도를 호도법으로 변환
float Degree2Radians(float _degree) {
	return _degree * PI / 180; // 1 rad = 180deg / pi ~= 57.2958deg
}

// 호도법을 각도로 변환
float Radians2Degree(float _radians) {
	return _radians * 180 / PI; // 1deg = pi / 180 ~= 0.0175 rad
}

// TODO (Jang) : 폴리곤 제작
class CPolygon : public CObject{
public:
	CPolygon() {
		m_sizeIndex = 0;
		m_sizeVertex = 0;
	}
	virtual ~CPolygon() {}

	int m_indexBuffer[100];
	int m_sizeIndex;
	Vec3 m_vertexBuffer[100];
	int m_sizeVertex;

	virtual void Draw(HDC &hdc) override {
		DrawIndexedPrimitive(hdc, m_indexBuffer, 6, m_vertexBuffer);
	}
	void SetIndexBuffer() {
		int buffer[] = {
			0,1,
			1,3,
			3,0,
			1,2,
			2,3,
			3,1
		};
		for (int i = 0; i < 12; ++i) {
			m_indexBuffer[i] = buffer[i];
		}
		m_sizeIndex = 12;
	}
	void SetVertexBuffer() {
		m_vertexBuffer[0] = Vec3(0.0f, 100.0f, 0.0f);
		m_vertexBuffer[1] = Vec3(0.0f, 0.0f, 0.0f);
		m_vertexBuffer[2] = Vec3(100.0f, 0.0f, 0.0f);
		m_vertexBuffer[3] = Vec3(100.0f, 100.0f, 0.0f);
		m_sizeVertex = 4;
	}
};

void DrawIndexedPrimitive(HDC hdc, int * _indexBuffer, int _primitiveCounter, Vec3* _vertexBuffer) {
	int i1, i2;
	int counter = 0;

	for (int i = 0; i < _primitiveCounter; ++i) {
		// get index
		i1 = _indexBuffer[counter];
		i2 = _indexBuffer[counter + 1];

		// draw line
		MoveToEx(hdc, (int)_vertexBuffer[i1].x, (int)_vertexBuffer[i1].y, nullptr);
		LineTo(hdc, _vertexBuffer[i2].x, _vertexBuffer[i2].y);
		counter += 2;
	}
}

//********************* Using Consle Graphics *******************//
//************************** Object *****************************//
class CObject {
protected:
	vector<Vec3> mPrimitive;
protected:
	Vec3 mPosition;
	Vec3 mScale;
	Vec3 mRotation;
private:
	Vec3 mMin;
	Vec3 mMax;
	Vec3 mMid;
private:
	Vec3 mMargin;
protected:
	COLORREF mColor;
private:
	void UpdateProperty() {
		mMin.x = (mPosition.x - mMargin.x);
		mMin.y = (mPosition.y - mMargin.y);
		mMin.z = (mPosition.z - mMargin.z);
		mMax.x = (mPosition.x + mMargin.x);
		mMax.y = (mPosition.y + mMargin.y);
		mMax.z = (mPosition.z + mMargin.z);
		mMid.x = (mMin.x + mMax.x) / 2;
		mMid.y = (mMin.y + mMax.y) / 2;
		mMid.z = (mMin.z + mMax.z) / 2;
	}
public:
	const Vec3 GetMin() {
		return mMin;
	}
	const Vec3 GetMax() {
		return mMax;
	}
	const Vec3 GetMid() {
		return mMid;
	}

public:
	CObject() {
		mColor = COLOR_WHITE;
		mPosition = Vec3(150, 150, 0);
		mMargin = Vec3(75, 75, 0);
		mScale = Vec3(1, 1, 1);
		mRotation = Vec3(0, 0, 0);
		UpdateProperty();
	}

	const COLORREF GetColor() {
		return mColor;
	}
	void SetColor(COLORREF _color) {
		mColor = _color;
	}

	const Vec3 GetPosition() {
		return mPosition;
	}
	void SetPosition(Vec3 _position) {
		mPosition = _position;
		UpdateProperty();
	}

	const Vec3 GetMargin() {
		return mMargin;
	}
	void SetMargin(Vec3 _margin) {
		mMargin = _margin;
		UpdateProperty();
	}

	const Vec3 GetScale() {
		return mScale;
	}
	void SetScale(Vec3 _scale) {
		mScale = _scale;
		SetMargin(Vec3(mMargin.x * _scale.x, mMargin.y * _scale.y, mMargin.z * _scale.z));
	}

	const Vec3 GetRotationEulur() {
		return mRotation;
	}
	void SetRotationEuler(Vec3 _rotation) {
		mRotation = _rotation;
		UpdateProperty();
	}

	virtual void Draw(HDC &hdc) { cout << "CObject draw\n"; }
};

class BoxObject : public CObject {
public:
	virtual void Draw(HDC &hdc) override {
		Vec3 min = GetMin();
		Vec3 max = GetMax();
		for (int y = min.y; y < max.y; ++y) {
			for (int x = min.x; x < max.x; ++x) {
				SetPixel(hdc, x, y, mColor);
			}
		}
	}
};

class WireBoxObject : public CObject {
public:
	virtual void Draw(HDC &hdc) override {
		// TODO (Jang) : 라인그려서 wire box 그리기
		Vec3 min = GetMin();
		Vec3 max = GetMax();

		SetROP2(hdc, R2_NOT); // color setting 어떻게하나?
		MoveToEx(hdc, min.x, min.y, NULL);
		LineTo(hdc, min.x, max.y);
		LineTo(hdc, max.x, max.y);
		LineTo(hdc, max.x, min.y);
	}
};





// TODO (Sagacity Jang) : 프레임 워크로 만들기
void Render() {
	HWND myConsole = GetConsoleWindow();
	HDC hdc = GetDC(myConsole);
	PAINTSTRUCT ps;

	/*
	CPolygon poly;
	poly.SetIndexBuffer();
	poly.SetVertexBuffer();
	poly.Draw(hdc);
	*/
	for (int i = 0; i < 2; ++i) {
		gObjects[i]->Draw(hdc);
	}

	// TODO (Jang) : 라인그리기 테스트중
	SetROP2(hdc, R2_NOT);
	
	hdc = BeginPaint(myConsole, &ps);


	cin.ignore();
	system("cls");
	ReleaseDC(myConsole, hdc);
}

// Testing
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	// Create objects
	BoxObject boxObj2;
	boxObj2.SetScale(Vec3(0.5f, 0.5f, 0.5f));
	boxObj2.SetColor(COLOR_GREEN);
	gObjects.push_back(&boxObj2);

	BoxObject boxObj;
	boxObj.SetScale(Vec3(0.2f, 0.2f, 0.2f));
	boxObj.SetColor(COLOR_RED);
	boxObj.SetPosition(Vec3(20, 20, 0));
	gObjects.push_back(&boxObj);

	WireBoxObject wireBoxObj;
	wireBoxObj.SetScale(Vec3(0.2f, 0.2f, 0.2f));
	wireBoxObj.SetColor(COLOR_RED);
	wireBoxObj.SetPosition(Vec3(150, 150, 0));
	gObjects.push_back(&wireBoxObj);

	while (true) {
		Render();
	}
	
	return 0;
}