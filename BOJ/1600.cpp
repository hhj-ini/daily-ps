#include <iostream>
#include <queue>

using namespace std;

struct node {
	node(int a, int b, int c) : x(a), y(b), cnt(c) {};
	int x, y, cnt;
};

int dx[12]{ 1, 1, 2, 2, -1, -1, -2, -2, 
			1, -1, 0, 0 };
int dy[12]{ -2, 2, -1, 1, -2, 2, -1, 1,
			0, 0, 1, -1 };
int dk[12]{ 1, 1, 1, 1, 1, 1, 1, 1,
			0, 0, 0, 0 };


int board[202][202];
int dist[202][202][32];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;

	int W, H;
	cin >> W >> H;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			int num;
			cin >> num;

			board[i][j] = num;
		}
	}

	// 시작점 0, 0
	// 도착점 H-1, W-1

	queue<node> q;
	q.push(node(0, 0, 0));	// 마지막 변수는 능력을 사용한 횟수
	dist[0][0][0] = 1;

	while (!q.empty()) {
		node curr = q.front();
		q.pop();

		if (curr.x == H - 1 && curr.y == W - 1) {
			cout << dist[H-1][W-1][curr.cnt] - 1;
			return 0;
		}

		for (int i = 0; i < 12; ++i) {
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];
			int nk = curr.cnt + dk[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W || nk > K) continue;

			if (0 != dist[nx][ny][nk] || 1 == board[nx][ny]) continue;

			dist[nx][ny][nk] = dist[curr.x][curr.y][curr.cnt] + 1;
			q.push(node(nx, ny, nk));
		}
	}

	cout << -1;

	// 시간 복잡도: O(H * W)
}