#include <iostream>
#include <queue>
#include <list>
#include <climits>

using namespace std;

//		   동 서 남 북
int dx[4]{ 1, -1, 0, 0 };
int dy[4]{ 0, 0, -1, 1 };

int map[102][102];
int vis[102][102];
int dist[102][102][50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int a;
			cin >> a;

			map[i][j] = a;
			for (int k = 0; k < 50; ++k) {
				dist[i][j][k] = -1;
			}
		}
	}

	int mapNum{ 0 };

	list<pair<int, int>> l;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (1 == vis[i][j] || 0 == map[i][j]) continue;
			++mapNum;

			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			vis[i][j] = 1;
			map[i][j] = mapNum;

			while (!q.empty()) {
				bool isSeaside{ false };
				pair<int, int> p = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int nx = p.first + dx[k];
					int ny = p.second + dy[k];

					// 범위를 벗어난 경우는 제외
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

					// 이미 방문했거나, 바다인 경우 제외
					if (1 == vis[nx][ny]) continue;

					if (0 == map[nx][ny]) {	// 한 면이라도 바다가 있는 경우
						isSeaside = true;
						continue;
					}

					vis[nx][ny] = 1;
					map[nx][ny] = mapNum;
					q.push(make_pair(nx, ny));
				}

				if (isSeaside) {
					auto pos = l.begin();
					l.insert(pos, make_pair(p.first, p.second));
				}
			}
		}
	}

	int minDist = INT_MAX;

	for (int x = 1; x <= mapNum; ++x) {
		queue<pair<int, int>> q;

		for (const pair<int, int>& p : l) {
			if (x == map[p.first][p.second]) {
				q.push(make_pair(p.first, p.second));
				dist[p.first][p.second][x] = 0;
			}
		}

		while (!q.empty()) {
			pair<int, int> curr = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int nx = curr.first + dx[i];
				int ny = curr.second + dy[i];

				// 범위를 벗어난 경우는 제외
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

				// 이미 방문한 곳이거나, 시작점의 대륙과 같으면 제외
				if (-1 != dist[nx][ny][x] || x == map[nx][ny]) continue;
				
				if (0 != map[nx][ny] && x != map[nx][ny]) {	// 다른 대륙 만남
					minDist = min(minDist, dist[curr.first][curr.second][x] + 1);
					break;
				}

				dist[nx][ny][x] = dist[curr.first][curr.second][x] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	cout << minDist - 1;

	// 시간 복잡도: O(map * N * N);
}