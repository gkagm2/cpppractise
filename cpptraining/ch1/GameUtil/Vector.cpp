
#include <iostream>
#include <math.h>
using namespace std;

struct Vector3 {
	float x;
	float y;
	float z;

	Vector3() :x(0),y(0),z(0){}
	Vector3(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	// 벡터의 크기
	float GetLength() {
		return GetMagnitude();
	}

	// 벡터의 크기
	float GetMagnitude() {
		float u = sqrtf(x*x + y * y + z * z);
		return u;
	}

	// 정규화 (단위벡터 만들기)
	Vector3 GetNormalized() {
		float u = GetLength();
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
Vector3 GetCross(Vector3 v1, Vector3 v2) {
	Vector3 p;
	p.x = (v1.y*v2.z - v1.z*v2.y);
	p.y = (v1.z*v2.x - v1.x*v2.z);
	p.z = (v1.x*v2.y - v1.y*v2.x);
	return p;
}

// 내적
float GetDotVector3(Vector3 v1, Vector3 v2)
{
	float scala = 0;
	scala = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return scala;
}

float GetDistance(Vector3 v1, Vector3 v2) {
	Vector3 v = v1 - v2;
	return v.GetMagnitude();
}


int main()
{
	Vector3 v1(0.3, 1, 0);
	Vector3 v2(-1, 0, 0);
	float scale = GetDotVector3(v1, v2);
	cout << scale << "\n";

	Vector3 v3(1, 2, 3);
	cout << v3.GetLength() << "\n";

	Vector3 v4(1, 1, 0);
	cout << v4.GetLength() << "\n";
	Vector3 v01(1, 0, -1), v02(0, 1, 1);
	cout <<" distance : " << GetDistance(v01, v02) << "\n";
	

	Vector3 v5(0, 0, 21);
	Vector3 v6(21, 0, 0);
	Vector3 resultV = GetCross(v5, v6);
	cout << "cross : ";
	resultV.PrintPosition();
	
	
}
