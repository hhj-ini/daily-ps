#include <iostream>
#include <queue>

using namespace std;

int dx[4]{ 0, 1, 0, -1 };
int dy[4]{ 1, 0, -1, 0 };

char puyo[14][8];
int vis[14][8];
int res;


bool func()
{
	bool ispuyo{ false };
	for (int i = 11; i >= 0; --i) {
		for (int j = 0; j < 6; ++j) {
			// 뿌요 터뜨리기
			if (puyo[i][j] != '.' && vis[i][j] != res + 1) {
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				vector<pair<int, int>> v;
				v.push_back(make_pair(i, j));
				vis[i][j] = res + 1;
				int cnt{ 1 };
				while (!q.empty()) {
					pair<int, int> p = q.front();
					q.pop();

					for (int ii = 0; ii < 4; ++ii) {
						int nx = p.first + dx[ii];
						int ny = p.second + dy[ii];

						if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
						if (vis[nx][ny] == res + 1) continue;
						if (puyo[p.first][p.second] != puyo[nx][ny]) continue;

						vis[nx][ny] = res + 1;
						q.push(make_pair(nx, ny));
						v.push_back(make_pair(nx, ny));
						++cnt;
					}
				}

				if (cnt >= 4) {	// 터질 수 있는 그룹
					for (const pair<int, int>& elem : v) {
						puyo[elem.first][elem.second] = '.';
					}
					ispuyo = true;
				}
			}
		}
	}

	if (!ispuyo) {
		return false;
	}

	int temp[14][8]{};
	for (int j = 0; j < 6; ++j) {
		int n{ 11 };
		for (int i = 11; i >= 0; --i) {
			if (puyo[i][j] != '.') {
				temp[n][j] = puyo[i][j];
				--n;
			}
		}
	}

	for (int i = 11; i >= 0; --i) {
		for (int j = 0; j < 6; ++j) {
			if (temp[i][j] != '\0') {
				puyo[i][j] = temp[i][j];
			}
			else {
				puyo[i][j] = '.';
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			char c;
			cin >> c;

			puyo[i][j] = c;
		}
	}

	while (func()) {
		++res;
	}

	cout << res;
}