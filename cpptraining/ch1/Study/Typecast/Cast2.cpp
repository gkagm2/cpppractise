#include <iostream>
using namespace std;

struct Vector3 {
public:
	float x;
	float y;
	float z;

	void operator=(float _f[3]) {
		x = _f[0];
		y = _f[1];
		z = _f[2];
	}
};

int main() {
	Vector3 v;
	v.x = 1.1f;
	v.y = 2.2f;
	v.z = 3.3f;

	float arr[3] = { 11.1f, 22.2f, 33.3f };
	v = arr; // float[3]의 배열을 Vector3에 넣을 수 있다.

	cout << v.x << " " << v.y << " " << v.z << "\n";

	return 0;
}