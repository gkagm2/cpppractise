// PROGRAME : Maze Game
// DEVELOP : Sagacity Jang
// DATE : 20191104 ~ 201911
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 파워 아이템
6 : 벽밀기 아이템
7 : 투명 아이템
8 : 웜홀
*/

struct _tagPoint {
	int x;
	int y;
};

typedef struct _tagPlayer {
	_tagPoint tPos;
	bool bWallPush;
	bool bTransparency;
	int iBombPower;

}PLAYER, *PPLAYER;

typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPLAYER pPlayer, PPOINT pStartPos, PPOINT pEndPos) {

	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	pPlayer->tPos = *pStartPos;

	strcpy_s(Maze[0],  "21101110011111110110");
	strcpy_s(Maze[1],  "00111011110100011100");
	strcpy_s(Maze[2],  "00100100000111000010");
	strcpy_s(Maze[3],  "01100111111001111110");
	strcpy_s(Maze[4],  "01000010100000000001");
	strcpy_s(Maze[5],  "11111110001111111111");
	strcpy_s(Maze[6],  "10100010111010000010");
	strcpy_s(Maze[7],  "10011110100110111010");
	strcpy_s(Maze[8],  "01000100100010101110");
	strcpy_s(Maze[9],  "01110110111100110000");
	strcpy_s(Maze[10], "01011100000100011110");
	strcpy_s(Maze[11], "01000011110100000010");
	strcpy_s(Maze[12], "01111110010101111111");
	strcpy_s(Maze[13], "00100000010101010001");
	strcpy_s(Maze[14], "11111111110101011101");
	strcpy_s(Maze[15], "10100010000101100101");
	strcpy_s(Maze[16], "10111100111100101101");
	strcpy_s(Maze[17], "10100111100011101011");
	strcpy_s(Maze[18], "10001010001110001100");
	strcpy_s(Maze[19], "11111011100011110113");
}

 void OutputMaze(char Maze[21][21], PPLAYER pPlayer) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			
			if (Maze[i][j] == '4') {
				cout << "※";
			}
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i) {
				cout << "◇";
			}
			else if (Maze[i][j] == '0') {
				cout << "■";
			}
			else if (Maze[i][j] == '1') {
				cout << "□";
			}
			else if (Maze[i][j] == '2') {
				cout << "☆";
			}
			else if (Maze[i][j] == '3') {
				cout << "★";
			}
			else if (Maze[i][j] == '5') { // 파워
				cout << "㉬";
			}
			else if (Maze[i][j] == '6') { // 벽밀기
				cout << "▣";
			}
			else if (Maze[i][j] == '7') { // 투명
				cout << "▦";
			}
		}
		cout << endl;
	}

	cout << "폭탄파워 : " << pPlayer->iBombPower << endl;
	cout << "벽통과 : ";
	if (pPlayer->bTransparency) {
		cout << "ON\t";
	}
	cout << "벽밀기 : ";
	if (pPlayer->bWallPush) {
		cout << "ON" << endl;
	}
	else {
		cout << "OFF" << endl;
	}
}

 bool AddItem(char cItemType, PPLAYER pPlayer) {
	 if (cItemType == '5') { // 파워
		 if (pPlayer->iBombPower < 5) {
			 ++pPlayer->iBombPower;
		 }
		 return true;
	 }
	 else if (cItemType  == '6') { // 벽밀기
		 pPlayer->bWallPush = true;
		 return true;
	 }
	 else if (cItemType == '7') { // 투명
		 pPlayer->bTransparency = true;
		 return true;
	 }

	 return false; // 아이템이 아닐 경우
 }

void MoveUp(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.y - 1 >= 0) {
		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4') {
			--pPlayer->tPos.y;
		}
		else if (pPlayer->bTransparency) { // 투명화니까 그냥 벽을 통과
			--pPlayer->tPos.y;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
 }

void MoveDown(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.y + 1 < 20) {
		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4') {
			++pPlayer->tPos. y;
		}
		else if (pPlayer->bTransparency) { // 투명화니까 그냥 벽을 통과
			++pPlayer->tPos.y;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MoveRight(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.x + 1 < 20) {
		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4') {
			++pPlayer->tPos.x;
		}
		else if (pPlayer->bTransparency) { // 투명화니까 그냥 벽을 통과
			++pPlayer->tPos.x;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MoveLeft(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.x - 1 >= 0) {
		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4') {
			--pPlayer->tPos.x;
		}
		else if (pPlayer->bTransparency) { // 투명화니까 그냥 벽을 통과
			--pPlayer->tPos.x;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cInput) {
	switch (cInput) {
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayer);
		break;
	}
}

// 포인터 변수를 const로 생성하면 가리키는 대상의 값을 변경할 수 없다.
void CreateBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount) {
	if (*pBombCount == 5) {
		return;
	}
	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0') { // 벽이면 폭탄생성 못하게 한다.
		return;
	}

	// 폭탄을 설치한 위치에 설치하지 못하게 한다.
	for (int i = 0; i < *pBombCount; ++i) {
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y) {
			return;
		}
	}

	pBombArr[*pBombCount] = pPlayer->tPos; // 폭탄을 설치한 위치 저장
	++(*pBombCount);

	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void DropItem(int iItemNumber) {

}


void Fire(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount) {
	for (int i = 0; i < *pBombCount; ++i) {
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';
		// 플레이어가 폭탄에 맞았을때 시작점으로 보낸다.
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y) {
			// TODO (Sagacity Jang) : 시작점에다가 넣어주기 tPlayerPos
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}
		
		for (int j = 1; j <= pPlayer->iBombPower; ++j) {
			if (pBombArr[i].y - 1 >= 0) { // 윗쪽
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0') {
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20) { // 20 % 확률
						int iPercent = rand() % 100;
						if (iPercent < 70) {
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';
						}
						else if (iPercent < 80) {
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';
						}
						else {
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
						}
					}
					else {
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';
					}
				}
				// 플레이어가 폭탄에 맞았을때 시작점으로 보낸다.
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j) {
					// TODO (Sagacity Jang) : 시작점에다가 넣어주기 tPlayerPos
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].y + j < 20) {
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] == '0') {
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20) { // 20 % 확률
						int iPercent = rand() % 100;
						if (iPercent < 70) {
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';
						}
						else if (iPercent < 80) {
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';
						}
						else {
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
						}
					}
					else {
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
					}
				}
				// 플레이어가 폭탄에 맞았을때 시작점으로 보낸다.
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j) {
					// TODO (Sagacity Jang) : 시작점에다가 넣어주기 tPlayerPos
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].x - j >= 0) {
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0') {
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20) { // 20 % 확률
						int iPercent = rand() % 100;
						if (iPercent < 70) {
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';
						}
						else if (iPercent < 80) {
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';
						}
						else {
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
						}
					}
					else {
						Maze[pBombArr[i].y][pBombArr[i].x - j] = '1';
					}
				}
				// 플레이어가 폭탄에 맞았을때 시작점으로 보낸다.
				if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y) {
					// TODO (Sagacity Jang) : 시작점에다가 넣어주기 tPlayerPos
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].x + j < 20) {
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0') {
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20) { // 20 % 확률
						int iPercent = rand() % 100;
						if (iPercent < 70) {
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';
						}
						else if (iPercent < 80) {
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';
						}
						else {
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
						}
					}
					else {
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
					}
				}
				// 플레이어가 폭탄에 맞았을때 시작점으로 보낸다.
				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y) {
					// TODO (Sagacity Jang) : 시작점에다가 넣어주기 tPlayerPos
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}
	}

	*pBombCount = 0;
}

void InitPlayer(PPLAYER tPlayer) {
	tPlayer->tPos.x = 0;
	tPlayer->tPos.y = 0;
	tPlayer->bTransparency = false;
	tPlayer->bWallPush = false;
	tPlayer->iBombPower = 1;
}


int main() {
	srand((unsigned int)time(0));

	// 20 x 20 미로를 만들어준다.
	char strMaze[21][21];

	PLAYER tPlayer;
	POINT tStartPos;
	POINT tEndPos;

	

	int iBombCount = 0;
	int iAddBomb = 0;

	POINT tBombPos[5];


	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);
	InitPlayer(&tPlayer);
		while (true) {
		system("cls");
		OutputMaze(strMaze, &tPlayer); // 미로를 출력한다.

		// 도착시
		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y) {
			cout << "도착했습니다. " << endl;
			break;
		}
		cout << "t : 폭탄설치, u : 폭탄 터트리기, i : 벽밀기" << endl;
		cout << "w : 위, s : 아래, a : 왼쪽, d : 오른쪽, q : 종료 : ";
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q') {
			break;
		}
		else if (cInput == 't' || cInput == 'T') {
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		}
		else if (cInput == 'u' || cInput == 'U') {
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);
		}

		MovePlayer(strMaze, &tPlayer, cInput);
	}
	return 0;
}