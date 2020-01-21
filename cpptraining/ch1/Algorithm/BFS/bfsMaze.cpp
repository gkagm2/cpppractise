// Breadth first search
#include <iostream>
#include <queue>
using namespace std;

#define MAZE_MAX_X 7
#define MAZE_MAX_Y 7

struct Position {
	int x;
	int y;
	
	Position(int _x = 0, int _y  = 0) : x(_x), y(_y) {}
public:
	bool operator==(const Position &_pos) {
		if (x == _pos.x && y == _pos.y) {
			return true;
		}
		return false;
	}
};

int maze[MAZE_MAX_X][MAZE_MAX_Y];
Position startPos(0,0);
Position destinationPos(MAZE_MAX_X-1, MAZE_MAX_Y-1);

Position MoveTo(Position cur, int dir) {
	
	switch (dir) {
	case 0:
		++cur.x; // 오른쪽으로 이동
		break;
	case 1: // 위로 이동
		++cur.y;
		break;
	case 2: // 아래로 이동
		--cur.y;
		break;
	case 3: // 왼쪽으로 이동
		--cur.x;
		break;
	}
	return cur;
}

int main() {
	queue<Position> que;

	Position cur(0, 0);

	que.push(cur);

	maze[0][0] = -1;
	bool isFound = false;

	while (!que.empty()) {
		cur = que.front();
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			Position p = MoveTo(cur, dir);

			maze[p.x][p.y] = maze[cur.x][cur.y] - 1;

			if (p == destinationPos) {
				cout << "Found the path\n";
				isFound = true;
				break;
			}
			que.push(p);
		}
	}

	return 0;
}