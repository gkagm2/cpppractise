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
int offset[4][2] = { // �� �� �� �� �������� �� ĭ �̵��� �� x��ǥ�� y��ǥ�� ��ȭ��
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

// 0 : ��
// 1 : ��
// 2 : ������
// 3 : ����� �÷��̾�
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
int n; // �̷��� ũ��

Position destinationPos;


int ReadMaze() {
	return 0;
} // ���Ͽ��� �о����
int PrintMaze() {

	for (int y = 0; y < MAX; ++y) {
		for (int x = 0; x < MAX; ++x) {
			
			if (maze[y][x] == 1) {
				cout << "��";
			}
			else if (maze[y][x] == 3) {
				cout << "��";
			}
			else if (maze[y][x] == 4) {
				cout << "��";
			}
			else if (maze[y][x] == 2) {
				cout << "��";
			}
			else if (maze[y][x] == 5) {
				cout << "��";
			}
			if (maze[y][x] == 0) {
				cout << "��";
			}
			
		}
		cout << '\n';
	}
	return 0;
}
bool Moveable(Position pos, int dir) {
	if (dir == 0) { // ��
		if (pos.y == 0)
			return false;
	}
	else if (dir == 1) { // ��
		if (pos.x == MAX - 1)
			return false;
	}
	else if (dir == 2) { // ��
		if (pos.y == MAX - 1)
			return false;
	}
	else if (dir == 3) { // ��
		if (pos.x == 0)
			return false;
	}
	return true;
}

// stack�� ��ġ�� �־��� ���.
//int main() {
//	ReadMaze();
//
//	stack<Position> stk; // ��ġ�� ���� �� ����
//	Position cur(0,0);
//
//	while (true) {
//		maze[cur.x][cur.y] = VISITED; // ���� ��ġ�� �湮�ߴٰ� ǥ���Ѵ�.
//		if (cur.x == destinationPos.x && cur.y == destinationPos.y) {
//			cout << "Found the path\n";
//			break;
//		}
//		bool forwarded = false; // 4���� �� �� ������ �����ϴµ� �����ߴ����� ǥ���Ѵ�.
//		for (int dir = 0; dir < 4; ++dir) {
//			if (Moveable(cur, dir)) { // �̵��� �� ������
//				stk.push(cur); // ���� ��ġ�� stack�� push �ϰ�
//				cur = MoveTo(cur, dir); // ��ĭ �̵�
//				forwarded = true;
//				break;
//			}
//		}
//
//		if (!forwarded) { // 4 ���� �� � �������� ���� ���ߴٸ�
//			maze[cur.x][cur.y] = BACKTRACKED; // �Դٰ� �ǵ��ư� ��ġ���� ǥ��
//			if (stk.empty()) { // �ǵ��ư� ��ġ�� ���ٸ� ���� ���� ���� �̷�.
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

// stack�� ������ �־��� ���.
int main() {
	//ReadMaze();

	stack<int> stk; // ��ġ�� ���� �� ����
	Position cur(0, 0);
	
	int initDir = 0; // � ��ġ�� �������� �� ó������ �õ��� �� �̵� ����

	while (true) {
		maze[cur.x][cur.y] = VISITED; // ���� ��ġ�� �湮�ߴٰ� ǥ���Ѵ�.
		if (cur.x == destinationPos.x && cur.y == destinationPos.y) {
			cout << "Found the path\n";
			break;
		}
		bool forwarded = false; // 4���� �� �� ������ �����ϴµ� �����ߴ����� ǥ���Ѵ�.
		for (int dir = initDir; dir < 4; ++dir) {
			if (Moveable(cur, dir)) { // �̵��� �� ������
				stk.push(dir); // ���ÿ��� �̵��ϴ� ������ push
				cur = MoveTo(cur, dir); // ��ĭ �̵�
				forwarded = true;
				initDir = 0; // ó�� �湮�ϴ� ��ġ������ �׻� 0�� ������� �õ��� ����.
				break;
			}
		}

		if (!forwarded) { // 4 ���� �� � �������� ���� ���ߴٸ�
			maze[cur.x][cur.y] = BACKTRACKED; // �Դٰ� �ǵ��ư� ��ġ���� ǥ��
			if (stk.empty()) { // �ǵ��ư� ��ġ�� ���ٸ� ���� ���� ���� �̷�.
				cout << "No path exists.\n";
				break;
			}
			int d = stk.top();
			stk.pop();
			maze[cur.x][cur.y] = 5;
			cur = MoveTo(cur, (d + 2) % 4); // ���� ��ġ���� ���� ��ġ�� �� �� d�������� �̵��߾��ٸ� �ǵ��� ������ (d+2)%4�� �������� �̵��ϸ� �ȴ�.

			initDir = d + 1; // �ǵ��� �� ��ġ������ d + 1�� ������� �õ��غ��� �ȴ�.
		}
	}
	PrintMaze();

	return 0;
}

