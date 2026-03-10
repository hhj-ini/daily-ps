#include <iostream>
#include <queue>
#include <list>

using namespace std;

int dx[4]{ 1, -1, 0, 0 };
int dy[4]{ 0, 0, 1, -1 };

int board[302][302];
int water[302][302];
int vis[302][302];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	list<pair<int, int>> l;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int h;
			cin >> h;

			board[i][j] = h;

			if (0 != h) {
				auto pos = l.begin();
				l.insert(pos, make_pair(i, j));
			}
		}
	}

	int year{ 0 };	

	while (!l.empty()) {
		// 1. 빙산 개수 세기
		int cnt{ 0 };

		for (pair<int, int> p : l) {
			if (0 != vis[p.first][p.second]) continue;
			queue<pair<int, int>> q;
			q.push(make_pair(p.first, p.second));
			vis[p.first][p.second] = 1;

			++cnt;
			while (!q.empty()) {
				pair<int, int> curr = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int nx = curr.first + dx[k];
					int ny = curr.second + dy[k];

					// 범위가 넘어갔을 경우 제외
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

					// 방문했으면 제외
					if (0 != vis[nx][ny]) continue;

					// 사방의 물을 계산 & 이번에 조사하는 칸이 물이면 제외
					if (0 >= board[nx][ny]) {
						++water[curr.first][curr.second];
						continue;
					}

					q.push(make_pair(nx, ny));
					vis[nx][ny] = 1;
				}
			}
		}

		// 2. 빙산 2개면 루프 탈출
		if (2 <= cnt) {
			//빙산이 분리되는 최초의 시간
			cout << year;
			return 0;
		}

		// 3. 빙산을 기준에 맞게 녹이기	
		bool isMelted{ true };	// 전부 녹았는지 확인하는 변수

		for (auto it = l.begin(); it != l.end(); ) {
			pair<int, int> p = *it;

			vis[p.first][p.second] = 0;

			board[p.first][p.second] = 
				(board[p.first][p.second] - water[p.first][p.second] <= 0) ? 
				0 : board[p.first][p.second] - water[p.first][p.second];
			water[p.first][p.second] = 0;

			if (0 < board[p.first][p.second]) {
				isMelted = false;	// 0(물)이 아닌게 1개라도 있다면 전부 녹은게 아님
				++it;
			}
			else {	// 물이면 리스트에서 삭제
				it = l.erase(it);
			}
		}

		if (isMelted) {
			cout << 0;
			return 0;
		}

		++year;
	}

	// 시간 복잡도: O(N*M * year);
}