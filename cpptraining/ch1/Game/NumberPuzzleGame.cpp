// PROGRAM : 숫자 퍼즐 게임
// DEV : Sagacity Jang
// DATE : 2019.10.30

#include <iostream>
#include <time.h>

// console input output 헤더파일. 콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일이다.
#include <conio.h>

using namespace std;

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i) {
		iNumber[i] = i + 1;
	}

	// 가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을 사용할 때 INT_MAX 값을 사용할 것이다.
	iNumber[24] = INT_MAX; // singed int 중 가장 큰 숫자

	// 별이 있는 위치를 저장할 변수
	int iStarIndex = 24;

	// 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만  섞어준다. 즉 인덱스 0 ~ 23번 인덱스 까지만 섞어준다.
	int iTemp, idx1, idx2;

	// Shuffle
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;
		
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	bool bGame = true;

	while (bGame) {
		cout << endl;
		// Show
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {

				// Print numbers
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t"; // 줄번호 * 가로개수 + 칸번호 (1차원 배열을 2차원 형식으로)
				}
			}
			cout << endl;
		}
		cout << endl;

		cout << "w : 위, s : 아래, a : 왼쪽, d : 오른쪽, q : 종료";

		// _getch() 함수는 문자 1개를 입력받는 함수. Enter를 치지 않더라도 누르는 순간 문자를 반환하고 종료.
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') {
			break;
		}

		switch (cInput) {
		case 'q':
		case'Q':
			bGame = false;
			break;

		case 'w':
		case 'W':;
			if (iStarIndex >= 5) { // 맨 윗줄이 아니면
				iNumber[iStarIndex] = iNumber[iStarIndex - 5]; // 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex - 5] = INT_MAX; //교체한다.
				iStarIndex -= 5; // 별이 한칸 위로 올라갔으므로 위의 인덱스로 넣어준다.
			}
			break;

		case 's':
		case 'S':
			if (iStarIndex < 20) {
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;

		case 'a':
		case 'A':
			if (iStarIndex % 5 != 0) {
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				iStarIndex -= 1;
			}
			break;

		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4) {
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				iStarIndex += 1;
			}

			break;
		}

		bool bWin = true;

		// 퍼즐을 맞추었는지 체크.
		for (int i = 0; i < 24; ++i) {
			if (iNumber[i] != i + 1) {
				bWin = false;
				cout << " bWin : false : " << iNumber[i] << ", " << i << endl;
				break;
			}
		}

		if (bWin) {
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		if (!bGame) { // 게임 종료
			break;
		}
		//system("cls");
	}
	cout << "게임을 종료합니다." << endl;


	return 0;
}