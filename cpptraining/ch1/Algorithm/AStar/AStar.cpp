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
// Ŀ�� ��ġ �̵�
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

// �� �� �� �� �� �� �� �� (index ������ ���� ����)
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
	if (x == dest.second&& y == dest.first)
		return true;
	return false;
}

// ������ġ�������� ������������ ��θ� �����Ѵ�.
void TracePath(Cell cellDetails[g_maxY][g_maxX], Pair dest) {
	int x = dest.second;
	int y = dest.first;

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
		GotoXY(0, 0); // system("cls"); ��� ���
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

	// ���� ��带 �ʱ�ȭ �Ѵ�.
	int i = start.first, j = start.second; // i = y, j = x
	cellDetails[i][j].f = 0.f;
	cellDetails[i][j].g = 0.f;
	cellDetails[i][j].h = 0.f;
	cellDetails[i][j].parentX = j;
	cellDetails[i][j].parentY = i;

	// open list�� �����.
	set<pPair> openList;

	// ���� ������ f�� 0���� �д�.
	openList.insert(make_pair(0.f, make_pair(i, j)));

	bool foundDest = false;

	while (!openList.empty()) {
		pPair p = *openList.begin();

		openList.erase(openList.begin()); // openList�� �ִ� vertex�� ����.

		i = p.second.first;  // y
		j = p.second.second; // x
		closedList[i][j] = true;

		// 8������ successor�� �����Ѵ�.
		for (int d = 0; d < 8; ++d) {
			int y = i + dirY[d];
			int x = j + dirX[d];

			if (false == IsValid(x, y))
				continue;

			if (true == IsDestination(x, y, dest)) {
				// ������ Cell�� �θ� �����Ѵ�.
				cellDetails[y][x].parentX = j;
				cellDetails[y][x].parentY = i;
				cout << "�������� ã��\n";
				TracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (false == closedList[y][x] && true == IsUnBlocked(x, y)) {
				float gNew = cellDetails[i][j].g + 1.0f;
				float hNew = GetDistance(x, y, dest.first, dest.second);
				float fNew = gNew + hNew;

				// openList�� �ƴϸ� openList�� �߰��Ѵ�.
				// �̹� openList�� 
				if (cellDetails[y][x].f == (numeric_limits<float>::max)() ||
					cellDetails[y][x].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(y, x)));

					cellDetails[y][x].f = fNew;
					cellDetails[y][x].g = gNew;
					cellDetails[y][x].h = hNew;
					cellDetails[y][x].parentX = j;
					cellDetails[y][x].parentY = i;
				}
			}
		}
	}

	if (false == foundDest)
		cout << "�������� ã�µ� �����߽��ϴ�.\n";
}

void Draw(int curX, int curY) {
	for (int i = 0; i < g_maxY; ++i) {
		for (int j = 0; j < g_maxX; ++j) {
			if (curX == j && curY == i) {
				cout << "��";
			}
			else if (grid[i][j] == Path) {
				cout << "��";
			}
			else if (grid[i][j] == Wall) {
				cout << "��";
			}
			else if (grid[i][j] == Start) {
				cout << "��";
			}
			else if (grid[i][j] == Dest) {
				cout << "��";
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
	start.first = 0; // y
	start.second = 0;// x
	dest.first = g_maxY -4;  
	dest.second = g_maxX - 2;

	for (int i = 0; i < g_maxY; ++i) {
		for (int j = 0; j < g_maxX; ++j) {
			if (i == start.first && j == start.second || 
				i == dest.first && j == dest.second) {
				continue;
			}
			grid[i][j] = rand() % 2;
		}
	}

	grid[start.first][start.second] = Start;
	grid[dest.first][dest.second] = Dest;

	AStar(start, dest);

	return 0;
}