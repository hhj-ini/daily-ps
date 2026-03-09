#include <iostream>
#include <queue>

using namespace std;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

char grid[102][102];
int vis[102][102];

void BFS(queue<pair<int, int>>& q, const char& c, int N)
{
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (grid[nx][ny] != c || vis[nx][ny] == 1) continue;

			q.push(make_pair(nx, ny));
			vis[nx][ny] = 1;

			if (c == 'G') grid[nx][ny] = 'R';
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char c;
			cin >> c;

			grid[i][j] = c;
		}
	}
	queue<pair<int, int>> q;
	for (int x = 0; x < 2; ++x) {
		int cnt = 0;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (vis[i][j] == 1) continue;
				q.push(make_pair(i, j));

				vis[i][j] = 1;
				++cnt;

				BFS(q, grid[i][j], N);

				if ('G' == grid[i][j]) grid[i][j] = 'R';
			}
		}

		cout << cnt << " ";

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				vis[i][j] = 0;
			}
		}
	}


}