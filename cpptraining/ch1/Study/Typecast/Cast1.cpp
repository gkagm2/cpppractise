#include <iostream>
using namespace std;

struct Vector3 {
public:
	float x;
	float y;
	float z;
};

void Func(float f[3]) {
	f[0] = 5.5f;
	f[1] = 6.6f;
	f[2] = 7.7f;
}

int main() {
	Vector3 v;
	v.x = 1.1f;
	v.y = 2.2f;
	v.z = 3.3f;

	Func((float*)&v); // 배열 형태로 바꿀 수 있다.

	cout << v.x << " " << v.y << " " << v.z << "\n";

	return 0;
}