#include <iostream>
#include <queue>

using namespace std;

int dx[8]{ 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[8]{ 2, -2, 1, -1, 2, -2, 1, -1 };

int dist[302][302];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int c = 0; c < T; ++c) {
		int I;
		cin >> I;

		int x1, y1;	// 나이트 시작점
		cin >> x1 >> y1;

		int x2, y2;	// 나이트 도착점
		cin >> x2 >> y2;

		for (int i = 0; i < I; ++i) {
			for (int j = 0; j < I; ++j) {
				dist[i][j] = -1;
			}
		}

		queue<pair<int, int>> q;
		q.push(make_pair(x1, y1));
		dist[x1][y1] = 0;

		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();

			if (p.first == x2 && p.second == y2) {
				cout << dist[p.first][p.second] << "\n";
				break;
			}

			for (int i = 0; i < 8; ++i) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];

				if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
				if (dist[nx][ny] != -1) continue;

				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[p.first][p.second] + 1;
			}
		}
	}

	// 시간 복잡도 : O(I*I)
}