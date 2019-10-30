// PROGRAM : Baseball game
// DEV : Sagacity Jang
// DATE : 2019.10.29

/*
야구게임 만들기
1 ~ 9 사이의 랜덤한 숫자 3개를 얻어온다. 단, 숫자는 중복되어서는 안된다.
3개의 숫자는 ***의 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
사용자는 이 3개의 숫자를 맞출때까지 계속해서 3개씩 숫자를 입력한다.
만약 맞춰야 할 숫자가 7 3 8 일 경우 사용자는 3개의 숫자를 계속 입력한다.
입력 : 1 2 4를 입력했을 경우 1 2 4는 맞춰야할 숫자중 아무것도 없으므로 Out을 출력한다.

입력 : 7 5 9를 입력했을 경우 7은 맞춰야할 숫자중 있고 위치도 같으므로 strike이다.
5, 9는 없으므로 출력은 1strike 0ball을 출력한다.

입력 : 7 8 6을 입력했을 경우 7은 1strike 8은 숫자는 있지만 위치가 다르므로 ball이 된다.
1strike 1ball을 출력한다.

이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게 입력하면 게임이 종료된다.
만약 입력받은 숫자 3개중 한개라도 0이 있을 경우 게임을 종료한다.
*/

#include <iostream>
#include <ctime>
using namespace std;

#define MAX_INPUT_NUMBER 3
#define MAX_HIT_NUMBER 9
int main() {

	srand((unsigned int)time(0)); // Random

	bool bGameStart = true;

	int iBallNums[MAX_INPUT_NUMBER] = {}; // 기본을 설정되는 값
	int iInputNums[MAX_INPUT_NUMBER] = {};		// 입력한 값
	int iBallNumList[MAX_HIT_NUMBER] = {};

	int iStrike = 0;
	int iBall = 0;
	int iTurnCount = 1;

	// Insert number
	for (int i = 0; i < MAX_HIT_NUMBER; ++i) {
		iBallNumList[i] = i + 1;
	}

	// Shuffle
	int idx1, idx2, iTemp;
	for (int i = 0; i < 50; ++i) {
		idx1 =(rand() % MAX_HIT_NUMBER); // 1 ~ 9 index값 대입
		idx2 = (rand() % MAX_HIT_NUMBER);// 1 ~ 9 index값 대입

		iTemp = iBallNumList[idx1];
		iBallNumList[idx1] = iBallNumList[idx2];
		iBallNumList[idx2] = iTemp;
	}

	// Print iBallNumList
	for (int i = 0; i < MAX_HIT_NUMBER; i++)
	{
		cout << iBallNumList[i] << ", ";
	}

	// Ball init
	for (int i = 0; i < MAX_INPUT_NUMBER; ++i) {
		iBallNums[i] = iBallNumList[i];
	}

	cout << endl;

	// Game start
	while (bGameStart) {
	_START:
		iStrike = iBall = 0;

		// Input number
		cout << "1 ~ 9까지 숫자 3개를 입력하세요 : ";
		for (int i = 0; i < MAX_INPUT_NUMBER; ++i) {
			cin >> iInputNums[i];
			if (iInputNums[i] == 0) { // 0인지 체크한다.
				bGameStart = false;
				break;
			}
			else if (iInputNums[i] < 0 || iInputNums[i] > MAX_HIT_NUMBER) { // 범위에 벗어나면
				cout << "숫자 범위를 벗어났습니다." << endl;
				goto _START;
			}
		}

		if (!bGameStart) { // Game close
			break;
		}
		
		// 같은지 체크한다.
		for (int i = 0; i < MAX_INPUT_NUMBER - 1; ++i) {
			for (int j = i + 1; j < MAX_INPUT_NUMBER; ++j) {
				if (iInputNums[i] == iInputNums[j]) {
					cout << "같은 숫자를 입력하였습니다. " << endl;
					goto _START;
				}
			}
		}

		// Check strike or ball
		for (int i = 0; i < MAX_INPUT_NUMBER; ++i) {
			// 포함되어있는지 확인한다.
			for (int j = 0; j < MAX_INPUT_NUMBER; ++j) {
				if (iBallNums[i] == iInputNums[j]) { // 같은게 있으면
					if (i == j) {
						++iStrike;
					}
					else {
						++iBall;
					}
				}
			}
			// 자리가 맞는지 확인한다.
		}

		system("cls");

		// print
		cout << iStrike << "strike, " << iBall <<"ball" << endl;
		
		if (iStrike == MAX_INPUT_NUMBER) {
			cout << iTurnCount <<"번째에 맞췄습니다." << endl;
			break;
		}

		// Init value
		++iTurnCount;
		
	}
	cout << "Game을 종료합니다." << endl;

	return 0;
}