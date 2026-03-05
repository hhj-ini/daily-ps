#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

char maze[1000][1000];
int escape[1000][1000];
int fire[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int R, C;
	cin >> R >> C;

	queue<pair<int, int>> q;
	queue<pair<int, int>> jq;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			char c;
			cin >> c;

			maze[i][j] = c;
			escape[i][j] = -1;
			fire[i][j] = INT_MAX;

			if ('F' == c) {
				q.push(make_pair(i, j));

				fire[i][j] = 1;
			}
			else if ('J' == c) {
				jq.push(make_pair(i, j));

				escape[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {	// 불에 대한 이동 시간 구하기. (지훈이의 영향을 받지 않음)
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if ('#' == maze[nx][ny] || INT_MAX != fire[nx][ny]) continue;	// 벽을 만났거나, 이미 방문했을 경우

			fire[nx][ny] = fire[p.first][p.second] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	while (!jq.empty()) {	// 지훈이의 이동시간 구하기. (불의 영향을 받음)
		pair<int, int> jp = jq.front();
		jq.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = jp.first + dx[i];
			int ny = jp.second + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;	// 범위를 벗어나는 경우
			if ('.' != maze[nx][ny] || -1 != escape[nx][ny]) continue;	// 갈 수 없는 곳이거나, 이미 방문한 칸일 경우 
			if (fire[nx][ny] <= escape[jp.first][jp.second] + 1) continue;	// 불이 먼저 방문한 경우도 불가능
			escape[nx][ny] = escape[jp.first][jp.second] + 1;
			jq.push(make_pair(nx, ny));
		}
	}


	int minTime = INT_MAX;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (-1 == escape[i][j]) continue;	// 탈출할 수 없는 경우
			if (i != 0 && i != R - 1 && j != 0 && j != C - 1) continue;	// 가장자리가 아닌경우
			
			minTime = min(minTime, escape[i][j]);
		}
	}

	if (minTime != INT_MAX) {
		cout << minTime;
		return 0;
	}
	
	cout << "IMPOSSIBLE";
	// 시간복잡도 (2*R*C);
}