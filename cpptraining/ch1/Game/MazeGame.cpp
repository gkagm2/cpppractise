// PROGRAME : Maze Game
// DEVELOP : Sagacity Jang
// DATE : 20191104
#include <iostream>
#include <conio.h>

using namespace std;

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
*/

struct _tagPoint {
	int x;
	int y;
};

typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos) {

	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;

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

 void OutputMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT tStartPos, PPOINT pEndPos) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			
			if (pPlayerPos->x == j && pPlayerPos->y == i) {
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
			else if (pEndPos->x == j && pEndPos->y == i) {
				cout << "★";
			}
		}
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y - 1 >= 0) {
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0') {
			--pPlayerPos->y;
		}
	}
 }

void MoveDown(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y + 1 < 20) {
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0') {
			++pPlayerPos->y;
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x + 1 < 20) {
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0') {
			++pPlayerPos->x;
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x - 1 >= 0) {
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0') {
			--pPlayerPos->x;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput) {
	switch (cInput) {
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	}
}

int main() {
	// 20 x 20 미로를 만들어준다.
	char strMaze[21][21];

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);
		while (true) {
		system("cls");
		OutputMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos); // 미로를 출력한다.

		// 도착시
		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y) {
			cout << "도착했습니다. " << endl;
			break;
		}

		cout << "w : 위, s : 아래, a : 왼쪽, d : 오른쪽, q : 종료 : ";
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q') {
			break;
		}

		MovePlayer(strMaze, &tPlayerPos, cInput);
	}
	return 0;
}