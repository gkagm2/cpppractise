#include <iostream>
#include <ctime>
#include <cstdlib>
#include<conio.h>
using namespace std;

int main() {

	srand(time(NULL)); //���� �߻��� �ʱ�ȭ.

	short player;

	while (true) {
		int key = _getch();
		cout << key << endl;

	}
	while (true) {
		cout << ">>>>>>>>>> Tetris <<<<<<<<<<" << endl;
		cout << ">> 1�ο� 2�ο� ���� : ";
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
			cout << "1 Ȥ�� 2�� �Է��� �ּ���" << endl;
			continue;
		}
	}
	
	if (player == 1) { // 1�ο�
		
	}
	else { // 2�ο�

	}



	return 0;
}

