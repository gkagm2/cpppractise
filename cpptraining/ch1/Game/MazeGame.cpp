// PROGRAME : Maze Game
// DEVELOP : Sagacity Jang
// DATE : 20191104 ~ 201911
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

/*
0 : ��
1 : ��
2 : ������
3 : ������
4 : ��ź
5 : �Ŀ� ������
6 : ���б� ������
7 : ���� ������
8 : ��Ȧ
*/

struct _tagPoint {
	int x;
	int y;
};

typedef struct _tagPlayer {
	_tagPoint tPos;
	bool bWallPush;
	bool bPushOfOff;
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
				cout << "��";
			}
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i) {
				cout << "��";
			}
			else if (Maze[i][j] == '0') {
				cout << "��";
			}
			else if (Maze[i][j] == '1') {
				cout << "��";
			}
			else if (Maze[i][j] == '2') {
				cout << "��";
			}
			else if (Maze[i][j] == '3') {
				cout << "��";
			}
			else if (Maze[i][j] == '5') { // �Ŀ�
				cout << "��";
			}
			else if (Maze[i][j] == '6') { // ���б�
				cout << "��";
			}
			else if (Maze[i][j] == '7') { // ����
				cout << "��";
			}
		}
		cout << endl;
	}

	cout << "��ź�Ŀ� : " << pPlayer->iBombPower << endl;
	cout << "����� : ";
	if (pPlayer->bTransparency) {
		cout << "ON\t";
	}
	cout << "���б� : ";
	if (pPlayer->bWallPush) {
		cout << "���� / ";
		if (pPlayer->bPushOfOff) {
			cout << "ON " << endl;
		}
		else {
			cout << "OFF" << endl;
		}
	}
	else {
		cout << "�Ұ��� / OFF" << endl;
	}
}

 bool AddItem(char cItemType, PPLAYER pPlayer) {
	 if (cItemType == '5') { // �Ŀ�
		 if (pPlayer->iBombPower < 5) {
			 ++pPlayer->iBombPower;
		 }
		 return true;
	 }
	 else if (cItemType  == '6') { // ���б�
		 pPlayer->bWallPush = true;
		 pPlayer->bPushOfOff = true;
		 return true;
	 }
	 else if (cItemType == '7') { // ����
		 pPlayer->bTransparency = true;
		 return true;
	 }

	 return false; // �������� �ƴ� ���
 }

void MoveUp(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.y - 1 >= 0) {
		// ������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4') {
			--pPlayer->tPos.y;
		}
		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0') { // ���б�
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOfOff) {
				// ���� ��ĭ�� 0���� ũ�ų� ���� ���� �ε����� �ִٴ� �ǹ�.
				if (pPlayer->tPos.y - 2 >= 0) {
					
					// ���� ��ĭ�� ���� �ƴϰ� ���� ���
					if(Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency) {
							--pPlayer->tPos.y;
						}
					}
					// ���� ��ĭ�� ���� ���
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '1') {
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0'; // ���� ��ĭ�� ������ �ٲٰ�
						Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] = '1'; // ��ĭ�� ��� �ٲ۴�.
						--pPlayer->tPos.y; // �÷��̾ �̵��Ѵ�.
					}
					
					else if (pPlayer->bTransparency) {
						--pPlayer->tPos.y;
					}
				}
			}
			// �� �бⰡ OFF ������ ���
			else {
				if (!pPlayer->bPushOfOff) {
					--pPlayer->tPos.y;
				}
			}
		}
		else if (pPlayer->bTransparency) { // ����ȭ�ϱ� �׳� ���� ���
			--pPlayer->tPos.y;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
 }

void MoveDown(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.y + 1 < 20) {
		// ������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4') {
			++pPlayer->tPos. y;
		}
		// �� �бⰡ �����ϰ� �ٷ� �Ʒ�ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0') { // ���б�
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOfOff) {
				// ���� �ؿ� ĭ�� 20���� �۰ų� ���� ���� �ε����� �ִٴ� �ǹ�.
				if (pPlayer->tPos.y + 2 <= 20) {

					// ���� �ؿ� ĭ�� ���� �ƴϰ� ���� ���
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency) {
							++pPlayer->tPos.y;
						}
					}
					// ���� �ؿ� ĭ�� ���� ���
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '1') {
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0'; // ���� �ؿ� ĭ�� ������ �ٲٰ�
						Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] = '1'; // �ؿ�ĭ�� ��� �ٲ۴�.
						++pPlayer->tPos.y; // �÷��̾ �̵��Ѵ�.
					}

					else if (pPlayer->bTransparency) {
						++pPlayer->tPos.y;
					}
				}
			}
			// �� �бⰡ OFF ������ ���
			else {
				if (!pPlayer->bPushOfOff) {
					++pPlayer->tPos.y;
				}
			}
		}
		else if (pPlayer->bTransparency) { // ����ȭ�ϱ� �׳� ���� ���
			++pPlayer->tPos.y;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MoveRight(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.x + 1 < 20) {
		// ������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4') {
			++pPlayer->tPos.x;
		}
		// �� �бⰡ �����ϰ� �ٷ� ������ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '0') { // ���б�
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOfOff) {
				// �������� ������ĭ�� 20���� �۰ų� ���� ���� �ε����� �ִٴ� �ǹ�.
				if (pPlayer->tPos.x + 2 <= 20) {

					// �������� ������ĭ�� ���� �ƴϰ� ���� ���
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '0')
					{
						if (pPlayer->bTransparency) {
							++pPlayer->tPos.x;
						}
					}
					// �������� ������ĭ�� ���� ���
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '1') {
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '0'; // �������� ������ĭ�� ������ �ٲٰ�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] = '1'; // ������ĭ�� ��� �ٲ۴�.
						++pPlayer->tPos.x; // �÷��̾ �̵��Ѵ�.
					}

					else if (pPlayer->bTransparency) {
						++pPlayer->tPos.x;
					}
				}
			}
			// �� �бⰡ OFF ������ ���
			else {
				if (!pPlayer->bPushOfOff) {
					++pPlayer->tPos.x;
				}
			}
		}
		else if (pPlayer->bTransparency) { // ����ȭ�ϱ� �׳� ���� ���
			++pPlayer->tPos.x;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MoveLeft(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.x - 1 >= 0) {
		// ������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4') {
			--pPlayer->tPos.x;
		}
		// �� �бⰡ �����ϰ� �ٷ� ����ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '0') { // ���б�
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOfOff) {
				// ������ ����ĭ�� 0���� ũ�ų� ���� ���� �ε����� �ִٴ� �ǹ�.
				if (pPlayer->tPos.x - 2 >= 0) {

					// ������ ����ĭ�� ���� �ƴϰ� ���� ���
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0')
					{
						if (pPlayer->bTransparency) {
							--pPlayer->tPos.x;
						}
					}
					// ������ ����ĭ�� ���� ���
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '1') {
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0'; // ������ ����ĭ�� ������ �ٲٰ�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '1'; // ����ĭ�� ��� �ٲ۴�.
						--pPlayer->tPos.x; // �÷��̾ �̵��Ѵ�.
					}

					else if (pPlayer->bTransparency) {
						--pPlayer->tPos.x;
					}
				}
			}
			// �� �бⰡ OFF ������ ���
			else {
				if (!pPlayer->bPushOfOff) {
					--pPlayer->tPos.x;
				}
			}
		}
		else if (pPlayer->bTransparency) { // ����ȭ�ϱ� �׳� ���� ���
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

// ������ ������ const�� �����ϸ� ����Ű�� ����� ���� ������ �� ����.
void CreateBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount) {
	if (*pBombCount == 5) {
		return;
	}
	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0') { // ���̸� ��ź���� ���ϰ� �Ѵ�.
		return;
	}

	// ��ź�� ��ġ�� ��ġ�� ��ġ���� ���ϰ� �Ѵ�.
	for (int i = 0; i < *pBombCount; ++i) {
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y) {
			return;
		}
	}

	pBombArr[*pBombCount] = pPlayer->tPos; // ��ź�� ��ġ�� ��ġ ����
	++(*pBombCount);

	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void DropItem(int iItemNumber) {

}


void Fire(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount) {
	for (int i = 0; i < *pBombCount; ++i) {
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';
		// �÷��̾ ��ź�� �¾����� ���������� ������.
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y) {
			// TODO (Sagacity Jang) : ���������ٰ� �־��ֱ� tPlayerPos
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}
		
		for (int j = 1; j <= pPlayer->iBombPower; ++j) {
			if (pBombArr[i].y - 1 >= 0) { // ����
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0') {
					// ������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 40) { // 20 % Ȯ��
						int iPercent = rand() % 100;
						if (iPercent < 40) {
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';
						}
						else if (iPercent < 70) {
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
				// �÷��̾ ��ź�� �¾����� ���������� ������.
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j) {
					// TODO (Sagacity Jang) : ���������ٰ� �־��ֱ� tPlayerPos
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].y + j < 20) {
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] == '0') {
					// ������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 40) { // 20 % Ȯ��
						int iPercent = rand() % 100;
						if (iPercent < 40) {
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';
						}
						else if (iPercent < 70) {
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
				// �÷��̾ ��ź�� �¾����� ���������� ������.
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j) {
					// TODO (Sagacity Jang) : ���������ٰ� �־��ֱ� tPlayerPos
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].x - j >= 0) {
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0') {
					// ������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 40) { // 20 % Ȯ��
						int iPercent = rand() % 100;
						if (iPercent < 40) {
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';
						}
						else if (iPercent < 70) {
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
				// �÷��̾ ��ź�� �¾����� ���������� ������.
				if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y) {
					// TODO (Sagacity Jang) : ���������ٰ� �־��ֱ� tPlayerPos
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].x + j < 20) {
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0') {
					// ������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 40) { // 20 % Ȯ��
						int iPercent = rand() % 100;
						if (iPercent < 40) {
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';
						}
						else if (iPercent < 70) {
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
				// �÷��̾ ��ź�� �¾����� ���������� ������.
				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y) {
					// TODO (Sagacity Jang) : ���������ٰ� �־��ֱ� tPlayerPos
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

	// 20 x 20 �̷θ� ������ش�.
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
		OutputMaze(strMaze, &tPlayer); // �̷θ� ����Ѵ�.

		// ������
		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y) {
			cout << "�����߽��ϴ�. " << endl;
			break;
		}
		cout << "t : ��ź��ġ, u : ��ź ��Ʈ����, i :���б� ON/OFF" << endl;
		cout << "w : ��, s : �Ʒ�, a : ����, d : ������, q : ���� : ";
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
		else if (cInput == 'i' || cInput == 'I') {
			if (tPlayer.bWallPush) {
				tPlayer.bPushOfOff = !tPlayer.bPushOfOff; // of / off ��� �����
			}
		}

		MovePlayer(strMaze, &tPlayer, cInput);
	}
	return 0;
}