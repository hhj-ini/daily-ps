#include <iostream>
#include <list>

using namespace std;

int dx[4]{ 0, 1, 0, -1 };
int dy[4]{ 1, 0, -1, 0 };
		// 동 남 서 북

constexpr int BODY{ -1 };
constexpr int APPLE{ 1 };

int board[102][102];
pair<int, char> p[102];
int x, y, d;		// 현재위치, 방향

list<pair<int, int>> snake;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; ++i) {
		int a, b;
		cin >> a >> b;

		board[a - 1][b - 1] = APPLE;
	}

	int L;
	cin >> L;

	for (int i = 0; i < L; ++i) {
		int a;
		char c;

		cin >> a >> c;

		p[i] = make_pair(a, c);
	}

	snake.push_front(make_pair(0, 0));
	int sec{ 0 };
	unsigned int idx{ 0 };

	while (true) {
		x = x + dx[d];
		y = y + dy[d];

		if (x < 0 || x >= N || y < 0 || y >= N) break; 	// 벽이나 자기자신과 부딪힘
		if (board[x][y] == BODY) break;

		snake.push_front(make_pair(x, y));
		if (board[x][y] == 0) {	// 사과가 없었을 경우
			pair<int, int> tail = snake.back();
			snake.pop_back();
			board[tail.first][tail.second] = 0;
		}

		board[x][y] = BODY;
		++sec;

		if (idx < L) {
			if (p[idx].first == sec) {	// 방향 전환
				if ('L' == p[idx].second) {	// 왼쪽으로 (반시계)
					d = (d - 1 == -1) ? 3 : d - 1;
				}
				else {	// 오른쪽으로 (시계)
					d = (d + 1) % 4;
				}
				++idx;
			}
		}
	}

	cout << sec +1;
}