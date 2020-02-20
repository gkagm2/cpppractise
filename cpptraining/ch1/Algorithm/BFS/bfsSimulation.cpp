/*
4 6
201111
101010
101011
111013
*/

#include <iostream>
#include <queue>
#include <Windows.h>
using namespace std;

#define X first;
#define Y second;

void BFS(int x, int y);
void Render(int xSize, int ySize);
void MapSetting(int xSize, int ySize);

int xMapSize, yMapSize;

char map[101][101] = { 0, };
int check[101][101] = { 0, };

int g_startPosX;
int g_startPosY;

int g_destinationPosX;
int g_destinationPosY;

// 오른쪽, 아래, 왼쪽, 위 순서
int g_directionX[4] = { 1, 0, -1, 0 };
int g_directionY[4] = { 0 ,1, 0, -1 };

// param x, y : startPosition
void BFS(int x, int y) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	check[y][x] = 1;

	while (!q.empty()) {
		x = q.front().X;
		y = q.front().Y;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			// 한칸씩 움직임
			int nx = x + g_directionX[i];
			int ny = y + g_directionY[i];

			// 목적지에 왔으면
			if (nx == g_destinationPosX && ny == g_destinationPosY) {
				check[ny][nx] = check[y][x] + 1;
				break;
			}

			// map size 범위 초과시 넘어감
			if (nx < 0 || nx >= xMapSize ||
				ny < 0 || ny >= yMapSize) {
				continue;
			}

			// 방문하지 않았고 길 이면
			if (check[ny][nx] == 0 && map[ny][nx] == '1') {
				q.push(make_pair(nx, ny)); // que에 넣음
				check[ny][nx] = check[y][x] + 1; // 1 더해줌
			}
			// 방문하지 않았는데 벽이면
			else if (check[ny][nx] == 0) {
				check[ny][nx] = -1; // 벽이므로 -1로 바꿔준다.
			}
		}
		Render(xMapSize, yMapSize);
		Sleep(1000);
		system("cls");
	}
}

void MapSetting(int xSize, int ySize) {
	cout << "map 정보를 입력하세요 (벽 : 0 ,길 : 1, 시작점 : 2 , 목적지 : 3)\n";
	
	for (int y = 0; y < ySize; ++y) {
		for (int x = 0; x < xSize; ++x) {
			cin >> map[y][x];

			// 시작점이면 변수에 넣어준다.
			if (map[y][x] == '2') {
				g_startPosX = x;
				g_startPosY = y;
			}
			// 목적지면 변수에 넣어준다.
			else if (map[y][x] == '3') {
				g_destinationPosX = x;
				g_destinationPosY = y;
			}
		}
	}
	system("cls");
}

void Render(int xSize, int ySize) {
	/*
	0 : wall
	1 : path
	2 : start coordinates
	3 : destination coordinate
	*/
	for (int y = 0; y < ySize; ++y) {
		for (int x = 0; x < xSize; ++x) {
			
			if (map[y][x] == '0') {
				cout << "■ ";
			}
			else if (map[y][x] == '1' && check[y][x] > 0) {
				cout << check[y][x]<<" ";
			}
			else if (map[y][x] == '1' && check[y][x] == 0) {
				cout << "□ ";
			}

			else if (map[y][x] == '2' && check[y][x] == 0) {
				cout << "☆ ";
			}
			else if (map[y][x] == '2' && check[y][x] > 0) {
				cout << check[y][x] << " ";
			}

			else if (map[y][x] == '3' && check[y][x] == 0) {
				cout << "★ ";
			}
			else if (map[y][x] == '3' && check[y][x] > 0) {
				cout << check[y][x] << " ";
			}
		}
		cout << '\n';
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cout << "맵 y(행)와 x(열)의 사이즈를 입력하세요 범위 y : 1~100 , x :1~100)";
	cin >> yMapSize >> xMapSize;
	MapSetting(xMapSize, yMapSize);

	BFS(g_startPosX, g_startPosY);

	cout << "최단거리 : " << check[g_destinationPosY][g_destinationPosX];

	return 0;
}