// 클래스 종속 열거 데이터 타입
#include <iostream>

class Paper {
public:
	enum class Colors { Red = 1, Green, Blue, Yellow };
private:
	Colors mColor = Colors::Red;
public:
	
	void SetColor(Colors color);
};

void Paper::SetColor(Colors color) {
	mColor = color;
}

int main() {
	Paper paper;
	paper.SetColor(Paper::Colors::Blue);

	return 0;
}