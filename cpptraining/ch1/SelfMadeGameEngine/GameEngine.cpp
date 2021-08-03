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

// Functions
void DrawIndexedPrimitive(HDC hdc, int * _indexBuffer, int _primitiveCounter, Vec3* _vertexBuffer);

//*************** DRAW *************//
static HANDLE g_hConsole;

//screen dimensions
#define WIDTH 1280
#define HEIGHT 720
const int dW = 4, dH = 8; //각 픽셀들의 width과 height

// 커서 위치 이동
void GotoXY(int x = 0, int y = 0) {
	COORD coord{ x,y };
	g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(g_hConsole, coord);
}

char g_palette[] = ".,-~:;=!*#OB8%&"; // 아스키 코들르 이용한 Draw를 위해 팔레트 준비

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

	void RotateX(TYPE _theta) {
		TYPE tx, ty, tz;
		tx = x;
		ty = y * cosf(_theta) - z * sinf(_theta);
		tz = y * sinf(_theta) + z * cosf(_theta);
		y = ty;
		z = tz;
	}
	void RotateY(TYPE _theta) {
		TYPE tx, ty, tz;
		tx = x * cosf(_theta) + z * sinf(_theta);
		tz = x * sinf(_theta) + z * cosf(_theta);
		x = tx;
		z = tz;
	}
	void RotateZ(TYPE _theta) {
		TYPE tx, ty, tz;
		tx = x * cosf(_theta) - y * sinf(_theta);
		ty = x * sinf(_theta) + y * cosf(_theta);
		x = tx;
		y = ty;
	}

	void Translate(TYPE _tx, TYPE _ty, TYPE _tz) {
		x += _tx;
		y += _ty;
		z += _tz;
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



//******************* Matrix ******************//
class Matrix4x4 {
public:
	union {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m_afElements[4][4];
		float f[16];
	};

	Matrix4x4() {
		SetZero();
	}
	Matrix4x4 SetZero() {
		memset(m_afElements, 0, sizeof(m_afElements));
		return *this;
	}

	Matrix4x4 SetIdentityMatrix4x4() {
		SetZero();
		m_afElements[0][0] = m_afElements[1][1] = m_afElements[2][2] = m_afElements[3][3] = 1.f;
		return *this;
	}

	float& operator() (int iRow, int iCol) {
		return m_afElements[iRow][iCol];
	}

	Matrix4x4 operator* (Matrix4x4& mRight) {
		Matrix4x4 mRet;
		mRet.SetZero();

		for (WORD i = 0; i < 4; ++i) {
			for (WORD j = 0; j < 4; ++j) {
				for (WORD k = 0; k < 4; ++k) {
					mRet(i,j) += m_afElements[i][k] * mRight(k, j);
				}
			}
		}
		return mRet;
	}

	Vec3 operator*(Vec3& vLeft) {
		Vec3 vRet;
		vRet.x =
			vLeft.x * m_afElements[0][0] +
			vLeft.y * m_afElements[0][1] +
			vLeft.z * m_afElements[0][2] +
			m_afElements[0][3];
		vRet.y =
			vLeft.x * m_afElements[1][0] +
			vLeft.y * m_afElements[1][1] +
			vLeft.z * m_afElements[1][2] +
			m_afElements[1][3];
		vRet.z =
			vLeft.x * m_afElements[2][0] +
			vLeft.y * m_afElements[2][1] +
			vLeft.z * m_afElements[2][2] +
			m_afElements[2][3];
		return vRet;
	}

	Matrix4x4 operator+(Matrix4x4& mRight) {
		Matrix4x4 mRet;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				mRet(i, j) = m_afElements[i][j] + mRight(i, j);
			}
		}
	}

	Matrix4x4 operator=(Matrix4x4& mRight) {
		memcpy(m_afElements, mRight.m_afElements, sizeof(m_afElements));
		return *this;
	}

	Matrix4x4 SetProjection(float d) {
		SetZero();
		m_afElements[0][0] = d;
		m_afElements[1][1] = d;
		m_afElements[2][2] = 1;
		m_afElements[3][3] = d;

		return *this;
	}
};

// 매트릭스를 출력한다.
inline void PrintMatrix(Matrix4x4& m) {
	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			cout << m(i,j) << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}

// 단위행렬
inline void SetIdentityMatrix4x4(Matrix4x4& m) {
	memset(m.m_afElements, 0, sizeof(m.m_afElements));
	m(0, 0) = m(1, 1) = m(2, 2) = m(3, 3) = 1.0f;
}

// 행렬 덧셈
void MatrixPlus(Matrix4x4& q, Matrix4x4& a, Matrix4x4& b) {
	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			q(i,j) = a(i, j) + b(i, j);
		}
	}
}

// 행렬 뺄셈
void MatrixMinus(Matrix4x4& q, Matrix4x4& a, Matrix4x4& b) {
	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			q(i,j) = a(i, j) - b(i, j);
		}
	}
}

// 행렬 곱셈
void MatrixMultiply(Matrix4x4& q, Matrix4x4& a, Matrix4x4& b) {
	for (WORD i = 0; i < 4; ++i) {
		for (WORD j = 0; j < 4; ++j) {
			for (WORD k = 0; k < 4; ++k) {
				q(i,j) += a(i, k) * b(k, j);
			}
		}
	}
}

// 이동 행렬
inline void SetTranslateMatrix(Matrix4x4& m, float tx, float ty, float tz) {
	SetIdentityMatrix4x4(m);
	m(3,0) = tx;
	m(3,1) = ty;
	m(3,2) = tz;
}

// 확대,축소 행렬
inline void SetScaleMatrix(Matrix4x4& m, float sx, float sy, float sz) {
	SetIdentityMatrix4x4(m);
	m(0,0) = sx;
	m(1,1) = sy;
	m(2,2) = sz;
}

// 회전 행렬 X
void SetRotateXMatrix(Matrix4x4& m, float fRads) {
	SetIdentityMatrix4x4(m);
	m(1,1) = cos(fRads);
	m(1,2) = sin(fRads);
	m(2,1) = -sin(fRads);
	m(2,2) = cos(fRads);
}

// 회전 행렬 Y
void SetRotateYMatrix(Matrix4x4& m, float fRads) {
	SetIdentityMatrix4x4(m);
	m(0,0) = cosf(fRads);
	m(0,2) = -sinf(fRads);
	m(2,0) = sinf(fRads);
	m(2,2) = cos(fRads);
}

// 회전 행렬 Z
void SetRotateZMatrix(Matrix4x4& m, float fRads) {
	SetIdentityMatrix4x4(m);
	m(0,0) = cosf(fRads);
	m(0,1) = sinf(fRads);
	m(1,0) = -sinf(fRads);
	m(1,1) = cos(fRads);
}

// 프로젝션
void SetProjection(Matrix4x4& m, float d) {
	m.SetZero();
	m(0,0) = d;
	m(1,1) = d;
	m(2,2) = 1;
	m(3,3) = d;
}

// 전치 행렬
void TransposedMatrix(Matrix4x4& m) {
	float t;
	t = m(0,1);
	m(0,1) = m(1,0);
	m(1,0) = t;
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			t = m(y,x);
			m(y,x) = m(x,y);
			m(x,y) = t;
		}
	}
}

// TODO (Sagacity Jang)
// 역행렬
void InverseMatrix(Matrix4x4& m) {
	// Determinant (행렬식 이용)

}

// 가역행렬
void Determinant(Matrix4x4& m) {

}


// 행렬 내적


// 행렬 외적

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

class CPolygon {
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

	virtual void Draw(HDC &hdc) {
		DrawIndexedPrimitive(hdc, m_indexBuffer, 6, m_vertexBuffer);
	}
	virtual void SetIndexBuffer() {
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
	virtual void SetVertexBuffer() {
		m_vertexBuffer[0] = Vec3(0.0f, 100.0f, 0.0f);
		m_vertexBuffer[1] = Vec3(0.0f, 0.0f, 0.0f);
		m_vertexBuffer[2] = Vec3(100.0f, 0.0f, 0.0f);
		m_vertexBuffer[3] = Vec3(100.0f, 100.0f, 0.0f);
		m_sizeVertex = 4;
	}

	void RotateX(float _theta) {
		for (int i = 0; i < m_sizeVertex; ++i) {
			m_vertexBuffer[i].RotateX(_theta);
		}
	}
	void RotateY(float _theta) {
		for (int i = 0; i < m_sizeVertex; ++i) {
			m_vertexBuffer[i].RotateY(_theta);
		}
	}
	void RotateZ(float _theta) {
		for (int i = 0; i < m_sizeVertex; ++i) {
			m_vertexBuffer[i].RotateZ(_theta);
		}
	}
	void Translate(float tx, float ty, float tz) {
		for (int i = 0; i < m_sizeVertex; ++i) {
			m_vertexBuffer[i].Translate(tx, ty, tz);
		}
	}

	void Transform(Matrix4x4& _mat) {
		for (int i = 0; i < m_sizeVertex; ++i) {
			m_vertexBuffer[i] = _mat * m_vertexBuffer[i];
		}
	}

	void Projection(Matrix4x4& _mat) {
		// TODO (Jang) : 프로젝션 매트릭스를 구현
		float d = _mat(0,0);
		float z;

		for (int i = 0; i < m_sizeVertex; ++i) {
			z = m_vertexBuffer[i].z;
			m_vertexBuffer[i] = _mat * m_vertexBuffer[i];
			m_vertexBuffer[i].x /= (z + d);
			m_vertexBuffer[i].y /= (z + d);
		}
	}
};

class CCubeObject : public CPolygon {
public:
	Vec3 mid;
	CCubeObject() {
		mid = Vec3(200.f, 200.f, 0.f);
	}
	virtual void SetIndexBuffer() {
		//		// Cube Index
		//		5-------6	 +z
		//	1-------2	|	/
		//	|	|	|	|  /----+x
		//	|	4---|---7  |
		//	0-------3	   |
		//				   +y

		int buffer[] = {
			0,1,
			1,2,
			2,3,
			3,0,
			4,5,
			5,6,
			6,7,
			7,4,
			0,4,
			1,5,
			2,6,
			3,7
		};
		for (int i = 0; i < 24; ++i) {
			m_indexBuffer[i] = buffer[i];
		}
		m_sizeIndex = 24;
	}

	virtual void SetVertexBuffer() {
		m_vertexBuffer[0] = Vec3(-50.0f, 50.0f, -50.0f) + mid;
		m_vertexBuffer[1] = Vec3(-50.0f, -50.0f, -50.0f) + mid;
		m_vertexBuffer[2] = Vec3(50.0f, -50.0f, -50.0f) + mid;
		m_vertexBuffer[3] = Vec3(50.0f, 50.0f, -50.0f) + mid;
		m_vertexBuffer[4] = Vec3(-50.0f, 50.0f, 50.0f) + mid;
		m_vertexBuffer[5] = Vec3(-50.0f, -50.0f, 50.0f) + mid;
		m_vertexBuffer[6] = Vec3(50.0f, -50.0f, 50.0f) + mid;
		m_vertexBuffer[7] = Vec3(50.0f, 50.0f, 50.0f) + mid;
		m_sizeVertex = 8;
	}

	virtual void Draw(HDC &hdc) {
		DrawIndexedPrimitive(
			hdc, 
			m_indexBuffer,	// index buffer
			12,				// primitive counter  
			m_vertexBuffer);// vertex buffer
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

class Box2DObject : public CObject {
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

class Box3DObject : public CObject {
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
		PAINTSTRUCT ps;
		// hdc = BeginPaint(myConsole, &ps); //TODO Jang) : 이걸 어떻게 가져와야되나..
		MoveToEx(hdc, min.x, min.y, NULL);
		LineTo(hdc, min.x, max.y);
		LineTo(hdc, max.x, max.y);
		LineTo(hdc, max.x, min.y);
		// EndPaint(myConsole, &ps);
	}
};


HDC hdc, backMemDC, memDC;
HWND myConsole;

HBITMAP backBitmap = nullptr;
HBITMAP myBitmap, prevBitmap;

RECT backWindowRT;



// TODO (Sagacity Jang) : 프레임 워크로 만들기
void Render() {
	// TODO : 윈도우핸들로 받아서 해버리니까 콘솔 더블버퍼링이 안먹힘.
	myConsole = GetConsoleWindow();
	hdc = GetDC(myConsole);

	backMemDC = CreateCompatibleDC(hdc);
	prevBitmap = (HBITMAP)SelectObject(backMemDC, backBitmap);

	//InvalidateRect(myConsole, NULL, TRUE);
	/*
	CPolygon poly;
	SetROP2(hdc, R2_NOT);
	poly.SetIndexBuffer();
	poly.SetVertexBuffer();
	poly.RotateX(PI / 4.0f);
	poly.RotateZ(g_fTheta);
	g_fTheta += 0.1f;
	poly.Translate(150.0f, 100.0f, 0.f);
	poly.Draw(hdc);

	CPolygon poly1;
	poly1.SetIndexBuffer();
	poly1.SetVertexBuffer();
	poly1.RotateX(PI / 4.0f);
	poly1.RotateY(g_fTheta);
	g_fTheta += 0.1f;
	poly1.Translate(150.0f, 100.0f, 0.f);
	poly1.Draw(hdc);
	*/
	

	Matrix4x4 matRotX;
	Matrix4x4 matRotY;
	Matrix4x4 matTrans;
	Matrix4x4 matTransform;
	Matrix4x4 matProjection;
	static float s_fTheta = 0.0f;
	s_fTheta += 0.1f;
	CCubeObject cube;
	SetROP2(hdc, R2_NOT);
	SetRotateXMatrix(matRotX, 0.5f);
	SetRotateYMatrix(matRotY, s_fTheta);
	SetTranslateMatrix(matTrans, 100.f, 100.f, 0);
	SetProjection(matProjection, 500.f);

	matTransform = matTrans * matRotY * matRotX;

	cube.SetIndexBuffer();
	cube.SetVertexBuffer();
	cube.Projection(matProjection);
	cube.Draw(hdc);
	
	for (int i = 0; i < gObjects.size(); ++i) {
		gObjects[i]->Draw(hdc);
	}

	// TODO (Jang) : 라인그리기 테스트중
	ReleaseDC(myConsole, hdc);
	

	// HDC로 해서 그런가 더블버퍼링을 다른 방식으로 해야될듯
	// GotoXY(0, 0); // 깜빡임 현상을 없애기 위하여 system("cls")대신에 사용 함.
}

// Testing
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	// Create objects
	Box2DObject boxObj2;
	boxObj2.SetScale(Vec3(0.5f, 0.5f, 0.5f));
	boxObj2.SetColor(COLOR_GREEN);
	gObjects.push_back(&boxObj2);

	Box2DObject boxObj;
	boxObj.SetScale(Vec3(0.2f, 0.2f, 0.2f));
	boxObj.SetColor(COLOR_RED);
	boxObj.SetPosition(Vec3(20, 20, 0));
	gObjects.push_back(&boxObj);

	WireBoxObject wireBoxObj;
	wireBoxObj.SetScale(Vec3(0.2f, 0.2f, 0.2f));
	wireBoxObj.SetColor(COLOR_RED);
	wireBoxObj.SetPosition(Vec3(150, 150, 0));
	gObjects.push_back(&wireBoxObj);

	CCubeObject cube;
	
	while (true) {
		Render();
	}
	return 0;
}