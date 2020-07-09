#include <iostream>
#include <math.h>
using namespace std;

struct vec2 {
public:
	float x;
	float y;

	vec2() {

	}
	vec2(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

//      (시작점)--------------------------------------->(끝점)

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	vec2 posStart(0,0);// 시작점
	vec2 posEnd(10,10);// 끝점

	vec2 arrow1(0, 0);// 화살표 1
	vec2 arrow2(0, 0);// 화살표 2

	float width = 1;  // 너비
	float length = 3; // 길이

	float distance = sqrtf(powf(posEnd.x - posStart.x, 2) + powf(posEnd.y - posStart.y, 2));
	cout << "distance : " << distance << '\n';

	//float th = atan2f(pend.x - pstart.x, pend.y - pstart.y) * (180 / 3.14f);
	float th = atan2f(posEnd.y - posStart.y, posEnd.x - posStart.x);
	cout << "th : " << th << '\n';

	arrow1.x = (distance - length) * cosf(th) - (width / 2.f) * sinf(th) + posStart.x;
	arrow1.y = (distance - length) * sinf(th) + (width / 2.f) * cosf(th) + posStart.y;

	arrow2.x = (distance - length) * cosf(th) + (width / 2.f) * sinf(th) + posStart.x;
	arrow2.y = (distance - length) * sinf(th) - (width / 2.f) * cosf(th) + posStart.y;

	cout << "arrow1 x : " << arrow1.x << ", y : " << arrow1.y << '\n';
	cout << "arrow2 x : " << arrow2.x << ", y : " << arrow2.y << '\n';

	return 0;
}
