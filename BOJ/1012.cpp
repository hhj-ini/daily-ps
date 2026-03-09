#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int coord[52][52];	// 배추밭
int vis[52][52];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int M, N;
		cin >> M >> N;	// 열개수, 행개수

		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				coord[j][k] = 0;
				vis[j][k] = 0;
			}
		}

		int K;
		cin >> K;
		for (int j = 0; j < K; ++j) {
			int a, b;
			cin >> a >> b;	// 열, 행 순서로 입력
			coord[b][a] = 1;
		}

		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (coord[j][k] == 1 && vis[j][k] != 1) {
					queue<pair<int, int>> q;

					q.push(make_pair(j, k));
					vis[j][k] = 1;
					++cnt;

					while (!q.empty()) {
						pair<int, int> p = q.front();
						q.pop();

						for (int l = 0; l < 4; ++l) {
							int nx = p.first + dx[l];
							int ny = p.second + dy[l];

							if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
							if (coord[nx][ny] != 1 || vis[nx][ny] != 0) continue;

							q.push(make_pair(nx, ny));
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}

		cout << cnt << "\n";
	}

	// 시간복잡도: O(N*M);
}