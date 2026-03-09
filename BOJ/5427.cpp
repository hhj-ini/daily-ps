#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

char maze[1002][1002];
int dist[1002][1002];
int fdist[1002][1002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;


	for (int i = 0; i < T; ++i) {
		int w, h;
		cin >> w >> h;
		queue<pair<int, int>> q;

		queue<pair<int, int>> fq;

		for (int j = 0; j < h; ++j) {
			for (int k = 0; k < w; ++k) {
				char c;
				cin >> c;
				maze[j][k] = c;
				dist[j][k] = -1;
				fdist[j][k] = INT_MAX;

				if ('@' == c) {
					q.push(make_pair(j, k));
					dist[j][k] = 0;
				}
				else if ('*' == c) {
					fq.push(make_pair(j, k));
					fdist[j][k] = 0;
				}
			}
		}

		while (!fq.empty()) {	// 불의 bfs
			pair<int, int> p = fq.front();
			fq.pop();

			for (int j = 0; j < 4; ++j) {
				int nx = p.first + dx[j];
				int ny = p.second + dy[j];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if ('#' == maze[nx][ny] || INT_MAX != fdist[nx][ny]) continue;

				fq.push(make_pair(nx, ny));
				fdist[nx][ny] = fdist[p.first][p.second] + 1;
			}
		}

		int minDist = -1;
		while (!q.empty()) {	// 상근이의 bfs
			pair<int, int> p = q.front();
			q.pop();
			
			for (int j = 0; j < 4; ++j) {
				int nx = p.first + dx[j];
				int ny = p.second + dy[j];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if ('.' != maze[nx][ny] || -1 != dist[nx][ny]) continue;

				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[p.first][p.second] + 1;
			}

			if (p.first != 0 && p.first != h - 1 && p.second != 0 && p.second != w - 1) continue;
			// 탈출 불가능한 위치면 아래 코드 실행 필요 X

			if (dist[p.first][p.second] >= fdist[p.first][p.second]) continue;
			// 불이 붙으려는 칸 탈출 불가능

			minDist = dist[p.first][p.second];
			break;
		}

		if (-1 == minDist) {
			cout << "IMPOSSIBLE" << "\n";
			continue;
		}
		cout << minDist + 1 << "\n";
	}

	// 시간 복잡도: O(2*h*w)
}