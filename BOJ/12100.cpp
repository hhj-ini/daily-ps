#include <iostream>

using namespace std;

int ac[4]{ 0, 1, 0, 1 };
int extra[4]{ 1, -1, 1, -1 };

int board[22][22];
int res;
int N;

void move(int dir)
{	// 좌우 이동
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int nj = abs((N*ac[dir]) - j - ac[dir]);
			if (board[i][nj] == 0) {
				int a{ extra[dir] };
				while (board[i][nj] == 0) {
					if (nj + a < 0 || nj + a >= N) break;
					board[i][nj] = board[i][nj + a];
					board[i][nj + a] = 0;
					a += extra[dir];	
				}
			}
		}
	}
}

void move2(int dir)
{	// 상하 이동
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int nj = abs((N * ac[dir]) - j - ac[dir]);
			if (board[nj][i] == 0) {
				int a{ extra[dir] };
				while (board[nj][i] == 0) {
					if (nj + a < 0 || nj + a >= N) break;
					board[nj][i] = board[nj + a][i];
					board[nj + a][i] = 0;
					a += extra[dir];
				}
			}
		}
	}
}

void combine(int dir)
{	//좌우 combine
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int nj = abs((N * ac[dir]) - j - ac[dir]);
			if (board[i][nj] != 0) {
				int a{ extra[dir] };
				if (board[i][nj] == board[i][nj + a] && board[i][nj] != 0) {
					board[i][nj] *= 2;
					board[i][nj + a] = 0;

					
					while (true) {
						nj = nj + a;
						if (nj + a < 0 || nj + a >= N) break;
						board[i][nj] = board[i][nj + a];
						board[i][nj + a] = 0;
					}
				}
			}
		}
	}
}

void combine2(int dir)
{	// 상하 combine
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int nj = abs((N * ac[dir]) - j - ac[dir]);
			if (board[nj][i] != 0) {
				int a{ extra[dir] };
				if (board[nj][i] == board[nj + a][i] && board[nj][i] != 0) {
					board[nj][i] *= 2;
					board[nj + a][i] = 0;
					
					while (true) {
						nj = nj + a;
						if (nj + a< 0 || nj + a>= N) break;
						board[nj][i] = board[nj + a][i];
						board[nj + a][i] = 0;
					}
				}
			}
		}
	}
}

void func(int curr)
{
	if (curr == 5) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				res = max(res, board[i][j]);
			}
		}
		return;
	}

	int temp[22][22]{ 0, };



	for (int i = 0; i < 4; ++i) {
		// 각 방향에 따라 DFS로 탐색
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				temp[i][j] = board[i][j];
			}
		}
		if (i < 2) { move(i); combine(i); }
		else { move2(i); combine2(i); }

		func(curr + 1);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				board[i][j] = temp[i][j];
			}
		}
	}

	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	func(0);
	cout << res;
}