#include <iostream>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

int dx[6]{ 1, 0, -1, 0, 0, 0 };
int dy[6]{ 0, 1, 0, -1, 0, 0 };
int dz[6]{ 0, 0, 0, 0, 1, -1 };

int box[100][100][100];
int day[100][100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M, N, H;

	cin >> M >> N >> H;

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				int t;
				cin >> t;

				box[i][j][k] = t;
				day[i][j][k] = -1;

				if (1 == t) {
					q.push(make_tuple(i, j, k));
					day[i][j][k] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		tuple<int, int, int> t = q.front();
		q.pop();

		for (int i = 0; i < 6; ++i) {
			int nz = get<0>(t) + dz[i];
			int nx = get<1>(t) + dx[i];
			int ny = get<2>(t) + dy[i];
		
			if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	// 범위를 넘어가는 경우
			if (-1 == box[nz][nx][ny] || -1 != day[nz][nx][ny]) continue;				// 박스에 토마토가 없는 경우, 이미 방문한 경우

			day[nz][nx][ny] = day[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
			q.push(make_tuple(nz, nx, ny));
		}	
	}

	int minDay = INT_MIN;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (-1 == day[i][j][k] && -1 != box[i][j][k]) {	// 익을 수 없는자리면서 토마토가 들어있는 자리
					cout << -1;
					return 0;
				}
				
				minDay = max(minDay, day[i][j][k]);
			}
		}
	}

	cout << minDay;


	// 시간복잡도 O(H*N*M);
}