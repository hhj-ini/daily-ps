#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct Node {
	Node(int nx, int ny, int nbroken) : x(nx), y(ny), broken(nbroken) {};
	int x, y, broken;
};

// 우 좌 상 하
int dx[4]{ 1, -1, 0, 0 };
int dy[4]{ 0, 0, 1, -1 };

char map[1002][1002];
int dist[1002][1002][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			char c;
			cin >> c;
			map[i][j] = c;

			dist[i][j][0] = INT_MAX;
			dist[i][j][1] = INT_MAX;
		}
	}

	queue<Node> q;
	q.push(Node(N, M, 0));
	dist[N][M][0] = 1;

	while (!q.empty()) {
		Node n = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = n.x + dx[i];
			int ny = n.y + dy[i];
			int nstate = n.broken;
			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;	// 범위 밖
			if ('1' == map[nx][ny]) {
				if (0 == nstate) {
					nstate = 1;
				}
				else continue;
			}

			if (INT_MAX != dist[nx][ny][nstate]) continue;

			dist[nx][ny][nstate * 1] = dist[n.x][n.y][n.broken] + 1;
			q.push(Node(nx, ny, nstate));

			if (1 == nx && 1 == ny) break; // 도착
		}
	}

	int minDist = (dist[1][1][0] < dist[1][1][1]) ? dist[1][1][0] : dist[1][1][1];

	if (INT_MAX == minDist) {
		cout << -1;
		return 0;
	}
	cout << minDist;

	// 시간 복잡도: O(2*N*M)
}