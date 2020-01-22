#include <iostream>
#include <stack>
#include <Windows.h>
using namespace std;

#define MAX 8
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

struct Position {
	int x;
	int y;
	Position(int _x=0, int _y=0) : x(_x), y(_y){}
};
int offset[4][2] = { // 북 동 남 서 방향으로 한 칸 이동할 때 x좌표와 y좌표의 변화량
	{0, -1},
	{1, 0},
	{0, 1},
	{-1, 0} };

Position MoveTo(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][0];
	next.y = pos.y + offset[0][dir];
	return next;
}

// 0 : 길
// 1 : 벽
// 2 : 목적지
// 3 : 출발지 플레이어
// 4 : pathway
// 5 : block
int maze[MAX][MAX] = {
	{3,0,0,0,0,0,0,1},
	{0,1,1,0,1,1,0,1},
	{0,0,0,1,0,0,0,1},
	{0,1,0,0,1,1,0,0},
	{0,1,0,0,0,0,1,1},
	{0,1,0,0,0,1,0,1},
	{0,0,0,0,0,0,0,1},
	{0,1,1,1,0,1,0,2},
};
int n; // 미로의 크기

Position destinationPos;


int ReadMaze() {
	return 0;
} // 파일에서 읽어오기
int PrintMaze() {

	for (int y = 0; y < MAX; ++y) {
		for (int x = 0; x < MAX; ++x) {
			
			if (maze[y][x] == 1) {
				cout << "■";
			}
			else if (maze[y][x] == 3) {
				cout << "※";
			}
			else if (maze[y][x] == 4) {
				cout << "◈";
			}
			else if (maze[y][x] == 2) {
				cout << "◎";
			}
			else if (maze[y][x] == 5) {
				cout << "▦";
			}
			if (maze[y][x] == 0) {
				cout << "□";
			}
			
		}
		cout << '\n';
	}
	return 0;
}
bool Moveable(Position pos, int dir) {
	if (dir == 0) { // 북
		if (pos.y == 0)
			return false;
	}
	else if (dir == 1) { // 동
		if (pos.x == MAX - 1)
			return false;
	}
	else if (dir == 2) { // 남
		if (pos.y == MAX - 1)
			return false;
	}
	else if (dir == 3) { // 서
		if (pos.x == 0)
			return false;
	}
	return true;
}

// stack을 위치로 넣었을 경우.
//int main() {
//	ReadMaze();
//
//	stack<Position> stk; // 위치를 저장 할 스택
//	Position cur(0,0);
//
//	while (true) {
//		maze[cur.x][cur.y] = VISITED; // 현재 위치를 방문했다고 표시한다.
//		if (cur.x == destinationPos.x && cur.y == destinationPos.y) {
//			cout << "Found the path\n";
//			break;
//		}
//		bool forwarded = false; // 4방향 중 한 곳으로 전진하는데 성공했는지를 표시한다.
//		for (int dir = 0; dir < 4; ++dir) {
//			if (Moveable(cur, dir)) { // 이동할 수 있으면
//				stk.push(cur); // 현재 위치를 stack에 push 하고
//				cur = MoveTo(cur, dir); // 한칸 이동
//				forwarded = true;
//				break;
//			}
//		}
//
//		if (!forwarded) { // 4 방향 중 어떤 방향으로 가지 못했다면
//			maze[cur.x][cur.y] = BACKTRACKED; // 왔다가 되돌아간 위치임을 표시
//			if (stk.empty()) { // 되돌아갈 위치가 없다면 원래 길이 없는 미로.
//				cout << "No path exists.\n";
//				break;
//			}
//			cur = stk.top();
//			stk.pop();
//		}
//	}
//	PrintMaze();
//
//	return 0;
//}

// stack을 방향을 넣었을 경우.
int main() {
	//ReadMaze();

	stack<int> stk; // 위치를 저장 할 스택
	Position cur(0, 0);
	
	int initDir = 0; // 어떤 위치에 도착했을 때 처음으로 시도해 볼 이동 방향

	while (true) {
		maze[cur.x][cur.y] = VISITED; // 현재 위치를 방문했다고 표시한다.
		if (cur.x == destinationPos.x && cur.y == destinationPos.y) {
			cout << "Found the path\n";
			break;
		}
		bool forwarded = false; // 4방향 중 한 곳으로 전진하는데 성공했는지를 표시한다.
		for (int dir = initDir; dir < 4; ++dir) {
			if (Moveable(cur, dir)) { // 이동할 수 있으면
				stk.push(dir); // 스택에는 이동하는 방향을 push
				cur = MoveTo(cur, dir); // 한칸 이동
				forwarded = true;
				initDir = 0; // 처음 방문하는 위치에서는 항상 0번 방향부터 시도해 본다.
				break;
			}
		}

		if (!forwarded) { // 4 방향 중 어떤 방향으로 가지 못했다면
			maze[cur.x][cur.y] = BACKTRACKED; // 왔다가 되돌아간 위치임을 표시
			if (stk.empty()) { // 되돌아갈 위치가 없다면 원래 길이 없는 미로.
				cout << "No path exists.\n";
				break;
			}
			int d = stk.top();
			stk.pop();
			maze[cur.x][cur.y] = 5;
			cur = MoveTo(cur, (d + 2) % 4); // 이전 위치에서 지금 위치에 올 때 d방향으로 이동했었다면 되돌아 가려면 (d+2)%4번 방향으로 이동하면 된다.

			initDir = d + 1; // 되돌아 간 위치에서는 d + 1번 방향부터 시도해보면 된다.
		}
	}
	PrintMaze();

	return 0;
}

