#include <iostream>
#include <queue>

using namespace std;

struct coord {
	coord(int a, int b) : x{ a }, y{ b } {};
	coord() : x{ 0 }, y{ 0 } {};
	int x, y;
};

int dx[4]{ 1, -1, 0, 0 };
int dy[4]{ 0, 0, 1, -1 };

char state[6][6];
bool isUsed[6][6];
coord com[8];
coord coords[26];

int cnt;
void func(int curr, int st)
{
	if (curr == 7) {
		coord c = com[0];
		int scnt{ 0 };
		int len{ 0 };

		bool vis[5][5]{};
		queue<coord> q;
		q.push(c);
		vis[c.x][c.y] = true;

		while (!q.empty()) {
			coord a = q.front();
			q.pop();
			
			++len;
			if (state[a.x][a.y] == 'S') ++scnt;

			if (len == 7) break;

			for (int i = 0; i < 4; ++i) {
				int nx = a.x + dx[i];
				int ny = a.y + dy[i];

				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (vis[nx][ny] == true || !isUsed[nx][ny]) continue;

				vis[nx][ny] = true;
				q.push(coord(nx, ny));				
			}
		}

		if (len >= 7 && scnt >= 4) ++cnt;
		return;
	}

	for (int i = st; i < 25; ++i) {
		coord c = coords[i];
		if (!isUsed[c.x][c.y]) {
			isUsed[c.x][c.y] = true;
			com[curr] = coord(c.x, c.y);
			func(curr + 1, i);
			isUsed[c.x][c.y] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			char c;
			cin >> c;
			state[i][j] = c;

			coords[k] = coord(i, j);
			++k;
		}
	}

	func(0, 0);

	cout << cnt;
}