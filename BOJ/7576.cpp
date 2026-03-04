#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int box[1000][1000];
int day[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M, N;
	cin >> M >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int t;
			cin >> t;
			box[i][j] = t;
			day[i][j] = -1;
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (1 == box[i][j]) {
				day[i][j] = 0;
				q.push(make_pair(i, j));				
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	// 범위를 넘어갔을 경우
			if (-1 == box[nx][ny] || -1 != day[nx][ny]) continue;	// 박스에 토마토가 없는 경우, 방문한 경우 제외

			q.push(make_pair(nx, ny));		
			day[nx][ny] = day[p.first][p.second] + 1;
		}
	}

	int maxDay = INT_MIN;
	// -1이 배열에 있으면 -1을 출력, 없으면 가장 큰 값 출력
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (-1 == day[i][j] && -1 != box[i][j]) {	// 토마토가 익을 수 없고, 박스에 토마토가 있는 경우
				cout << -1;
				return 0;
			}
			if (day[i][j] > maxDay) {
				maxDay = day[i][j];
			}
		}
	}

	cout << maxDay;

	// 시간복잡도 O(N*M);
}