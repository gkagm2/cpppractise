// 선 사이의 length 값 만큼의 위치값 구하기
//      (시작점)---(StartMarginPos)--------------------------------(EndMarginPos)---(끝점)

#include <iostream>
#include <math.h>
using namespace std;

struct vec2 {
public:
	float x;
	float y;

	vec2() {
		x = 0;
		y = 0;
	}
	vec2(float x, float y) {
		this->x = x;
		this->y = y;
	}
};


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vec2 posStart(0, 0);// 시작점
	vec2 posEnd(-10, -10);// 끝점

	vec2 startMarginPos(0, 0);// 선 사이의 위치
	vec2 endMarginPos(0, 0);// 선 사이의 위치

	float length = 1; // 길이

	if (fabsf(posEnd.x) == fabsf(posStart.x)) // 세로면 
	{
		if (posEnd.y - posStart.y > 0) {
			endMarginPos.y = posEnd.y - length;
			startMarginPos.y = posStart.y + length;
		}
		else {
			endMarginPos.y = posEnd.y + length;
			startMarginPos.y = posStart.y - length;
		}
		endMarginPos.x = posEnd.x;
		startMarginPos.x = posEnd.x;
	}
	else if (fabsf(posEnd.y) == fabsf(posStart.y)) // 가로면
	{
		if (posEnd.x - posStart.x > 0)
		{
			endMarginPos.x = posEnd.x - length;
			startMarginPos.x = posStart.x + length;
		}
		else
		{
			endMarginPos.x = posEnd.x + length;
			startMarginPos.x = posStart.x - length;
		}
		endMarginPos.y = posEnd.y;
		startMarginPos.y = posEnd.y;
	}
	else // exist angle
	{
		float th = atan2f(posEnd.y - posStart.y, posEnd.x - posStart.x);

		float distance = sqrtf(powf(posEnd.x - posStart.x, 2) + powf(posEnd.y - posStart.y, 2));

		
		endMarginPos.x = (distance - length) * cosf(th) + posStart.x;
		endMarginPos.y = (distance - length) * sinf(th) + posStart.y;

		startMarginPos.x = length * cosf(th) + posStart.x;
		startMarginPos.y = length * sinf(th) + posStart.y;
		
	}
	cout << "endMarginPos : " << endMarginPos.x << ", " << endMarginPos.y << "\n";
	cout << "startMarginPos : " << startMarginPos.x << ", " << startMarginPos.y << "\n";

	return 0;
}
