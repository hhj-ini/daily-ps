#include <iostream>
#include <queue>

using namespace std;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int maze[100][100];
int length[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			maze[i][j] = s[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	
	length[0][0] = 1;
	q.push(make_pair(0, 0));
	
	while (!q.empty()) {
		pair<int, int>p{ q.front() };
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (0 > nx || N <= nx || 0 > ny || M <= ny) continue;
			if (0 != length[nx][ny] || 0 == maze[nx][ny]) continue;

			
			length[nx][ny] = length[p.first][p.second] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	cout << length[N - 1][M - 1];

	// 시간복잡도: O(N*M)
}