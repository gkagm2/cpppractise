// Ŭ���� ���� ���� ������ Ÿ��
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