// AStar algorithm
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <time.h>
#include <windows.h>

using namespace std;

static HANDLE g_hConsole;
// 커서 위치 이동
void GotoXY(int x = 0, int y = 0) {
	COORD coord{ x,y };
	g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(g_hConsole, coord);
}

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int> > pPair;

struct Cell {
	int parentX, parentY;
	float  f, g, h;
};

const int g_maxX = 18;
const int g_maxY = 18;
int grid[g_maxY][g_maxX];

enum Type{
	Path,
	Wall,
	Start,
	Dest
};

// ↖ ↑ ↗ ← → ↙ ↓ ↘ (index 순서에 따른 뱡향)
int dirX[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dirY[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void Draw(int curX, int curY);

int GetDistance(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool IsValid(int x, int y) {
	if (x < 0 || y < 0 || x >= g_maxX || y >= g_maxY)
		return false;
	return true;
}

bool IsUnBlocked(int x, int y) {
	if (grid[y][x] == Wall)
		return false;
	return true;
}

bool IsDestination(int x, int y, Pair dest) {
	if (x == dest.first && y == dest.second)
		return true;
	return false;
}

// 시작위치에서부터 목적지까지의 경로를 추적한다.
void TracePath(Cell cellDetails[g_maxY][g_maxX], Pair dest) {
	int x = dest.first;
	int y = dest.second;

	stack<Pair> path;

	while (!(cellDetails[y][x].parentX == x && cellDetails[y][x].parentY == y)) {
		path.push(make_pair(y, x));

		int tempX = cellDetails[y][x].parentX;
		int tempY = cellDetails[y][x].parentY;
		x = tempX;
		y = tempY;
	}

	path.push(make_pair(y, x));
	while (!path.empty()) { 
		pair<int, int> p = path.top();
		path.pop();
		cout << "->(" << p.first << "," << p.second << ")" << "\n";
		Draw(p.second, p.first);
		Sleep(200);
		GotoXY(0, 0); // system("cls"); 대신 사용
		// system("cls");
	}
	cout << "\n";
}

void AStar(Pair start, Pair dest) {
	if (false == IsValid(start.first, start.second))
		return;
	if (false == IsValid(dest.first, dest.second))
		return;

	if (false == IsUnBlocked(start.first, start.second) ||
		false == IsUnBlocked(dest.first, dest.second))
		return;

	if (IsDestination(start.first, start.second, dest))
		return;

	bool closedList[g_maxY][g_maxX];
	memset(closedList, false, sizeof(closedList));

	Cell cellDetails[g_maxY][g_maxX];

	// init cells
	for (int i = 0; i < g_maxY; ++i) {
		for (int j = 0; j < g_maxX; ++j) {
			cellDetails[i][j].f = (numeric_limits<float>::max)();
			cellDetails[i][j].g = (numeric_limits<float>::max)();
			cellDetails[i][j].h = (numeric_limits<float>::max)();
			cellDetails[i][j].parentX = -1;
			cellDetails[i][j].parentY = -1;
		}
	}

	// 시작 노드를 초기화 한다.
	int yy = start.first, xx = start.second; // i = y, j = x
	cellDetails[yy][xx].f = 0.f;
	cellDetails[yy][xx].g = 0.f;
	cellDetails[yy][xx].h = 0.f;
	cellDetails[yy][xx].parentX = xx;
	cellDetails[yy][xx].parentY = yy;

	// open list를 만든다.
	set<pPair> openList;

	// 시작 지점의 f를 0으로 둔다.
	openList.insert(make_pair(0.f, make_pair(xx, yy)));

	bool foundDest = false;

	while (!openList.empty()) {
		pPair p = *openList.begin();

		openList.erase(openList.begin()); // openList에 있는 vertex를 삭제.

		xx = p.second.first; // x
		yy = p.second.second;// y
		closedList[yy][xx] = true;

		// 8방향의 successor를 생성한다.
		for (int d = 0; d < 8; ++d) {
			int y = yy + dirY[d];
			int x = xx + dirX[d];

			if (false == IsValid(x, y))
				continue;

			if (true == IsDestination(x, y, dest)) {
				// 목적지 Cell의 부모를 설정한다.
				cellDetails[y][x].parentX = xx;
				cellDetails[y][x].parentY = yy;
				cout << "목적지를 찾음\n";
				TracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (false == closedList[y][x] && true == IsUnBlocked(x, y)) {
				float gNew = cellDetails[yy][xx].g + 1.0f;
				float hNew = GetDistance(x, y, dest.second, dest.first);
				float fNew = gNew + hNew;

				// openList가 아니면 openList에 추가한다.
				// 이미 openList면 
				if (cellDetails[y][x].f == (numeric_limits<float>::max)() ||
					cellDetails[y][x].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(x, y)));

					cellDetails[y][x].f = fNew;
					cellDetails[y][x].g = gNew;
					cellDetails[y][x].h = hNew;
					cellDetails[y][x].parentX = xx;
					cellDetails[y][x].parentY = yy;
				}
			}
		}
	}

	if (false == foundDest)
		cout << "목적지를 찾는데 실패했습니다.\n";
}

void Draw(int curX, int curY) {
	for (int i = 0; i < g_maxY; ++i) {
		for (int j = 0; j < g_maxX; ++j) {
			if (curX == j && curY == i) {
				cout << "★";
			}
			else if (grid[i][j] == Path) {
				cout << "□";
			}
			else if (grid[i][j] == Wall) {
				cout << "■";
			}
			else if (grid[i][j] == Start) {
				cout << "⊙";
			}
			else if (grid[i][j] == Dest) {
				cout << "○";
			}
			
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	srand((unsigned int)time(nullptr));

	Pair start;
	Pair dest;
	start.first = 0; // x
	start.second = 0;// y
	dest.first = g_maxX - 2;
	dest.second = g_maxY - 4;  

	for (int i = 0; i < g_maxY; ++i) {
		for (int j = 0; j < g_maxX; ++j) {
			if (i == start.second && j == start.first || 
				i == dest.second && j == dest.first) {
				continue;
			}
			grid[i][j] = rand() % 2;
		}
	}

	grid[start.second][start.first] = Start;
	grid[dest.second][dest.first] = Dest;

	AStar(start, dest);

	return 0;
}