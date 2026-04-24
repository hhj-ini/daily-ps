#include <iostream>

using namespace std;

struct coord {
	coord() : x(0), y(0) {};
	coord(int a, int b) : x(a), y(b) {};
	int x, y;
};


coord tetro[5][4]{
	{ {0, 0}, {0, 1}, {0, 2}, {0, 3} },
	{ {0, 0}, {0, 1}, {1, 0}, {1, 1} },
	{ {0, 0}, {1, 0}, {2, 0}, {2, 1} },
	{ {0, 0}, {1, 0}, {1, 1}, {2, 1} },
	{ {0, 0}, {0, 1}, {0, 2}, {1, 1} }
};

coord SZ[5]{
	{1, 4}, {2, 2}, {3, 2}, {3, 2}, {2, 3}
};

int N, M;
int board[502][502];
int res{ 0 };

void rotate(int num)
{
	coord temp[4]{};

	for (int i = 0; i < 4; ++i) {
		temp[i].x = SZ[num].x - 1 - tetro[num][i].y;
		temp[i].y = tetro[num][i].x;

		tetro[num][i] = temp[i];
	}

	int sz = SZ[num].x;
	SZ[num].x = SZ[num].y;
	SZ[num].y = sz;
}

void reverse(int num)
{
	for (int i = 0; i < 4; ++i) {
		int temp = tetro[num][i].x;
		tetro[num][i].x = tetro[num][i].y;
		tetro[num][i].y = temp;
	}

	int sz = SZ[num].x;
	SZ[num].x = SZ[num].y;
	SZ[num].y = sz;
}

void func(int num)
{
	for (int i = -SZ[num].x; i < N + SZ[num].x; ++i) {
		for (int j = -SZ[num].y; j < M + SZ[num].y; ++j) {
			int sum{ 0 };
			for (int k = 0; k < 4; ++k) {
				int nx = i + tetro[num][k].x;
				int ny = j + tetro[num][k].y;

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
					sum = 0;
					break;
				}

				sum += board[nx][ny];
			}

			res = max(res, sum);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 4; ++k) {
				func(i);
				rotate(i);
			}
			reverse(i);
		}
	}

	cout << res;
}