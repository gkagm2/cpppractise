#include <iostream>
#include <ctime>
#include <cstdlib>
#include<conio.h>
using namespace std;

int main() {

	srand(time(NULL)); //난수 발생기 초기화.

	short player;

	while (true) {
		int key = _getch();
		cout << key << endl;

	}
	while (true) {
		cout << ">>>>>>>>>> Tetris <<<<<<<<<<" << endl;
		cout << ">> 1인용 2인용 선택 : ";
		cin >> player;
		try {
			if (player > 2 || player < 1) {
				system("cls");
				throw -1;
			}
			else
				break;


		}
		catch (int exp) {
			cout << "1 혹은 2를 입력해 주세요" << endl;
			continue;
		}
	}
	
	if (player == 1) { // 1인용
		
	}
	else { // 2인용

	}



	return 0;
}

