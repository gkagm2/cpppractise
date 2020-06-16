#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[502][502]; // 미로 칸 ( 1 : 길, 0 : 벽)
int vis[502][502]; // 방문 표시 칸 (1 : 방문함, 0 방문하지 않음)

// n은 행, m은 열
int n = 10, m = 10;

// 방향 설정
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<pair<int, int>> q;

	vis[0][0] = 1;
	q.push({ 0,0 });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		cout << '(' << cur.X + ',' << cur.Y << ") -> ";
		
		for (int dir = 0; dir < 4; ++dir) {
			int x = cur.X + dx[dir];
			int y = cur.Y + dy[dir];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;
			if (vis[x][y] || board[x][y] == 0)
				continue;
			vis[x][y] = 1; // 방문했쪄영
			q.push({ x,y });

		}
	}

	return 0;
}
