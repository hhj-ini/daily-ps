#include <iostream>
#include <numeric>

using namespace std;

enum STATE {
	KEEP, FAIL, SUCC
};

int dx[4]{ 0, 0, 1, -1 };	
int dy[4]{ 1, -1, 0, 0 };
// 오른쪽, 왼쪽, 아래, 위 (로 기울이기)


int N, M;
char board[12][12];
int rx, ry;
int bx, by;

int res{ numeric_limits<int>::max()};

STATE move(int dir)
{
	STATE res = STATE::KEEP;
	int nx = rx;
	int ny = ry;
	while (true) {
		nx = nx + dx[dir];
		ny = ny + dy[dir];

		// . R O B #
		if (board[nx][ny] == '#') {	// 벽
			nx = nx - dx[dir];
			ny = ny - dy[dir];
			break;
		}
		else if (board[nx][ny] == 'O') { // 골인
			res = STATE::SUCC;
			break;
		}
	
	}

	board[rx][ry] = '.';

	int nbx = bx;
	int nby = by;

	while (true) {
		nbx = nbx + dx[dir];
		nby = nby + dy[dir];

		if (board[nbx][nby] == '#') {	// 벽
			nbx = nbx - dx[dir];
			nby = nby - dy[dir];
			break;
		}
		else if (board[nbx][nby] == 'O') {	// 골인
			res = STATE::FAIL;
			break;
		}
	}

	board[bx][by] = '.';
	
	if (nx == nbx && ny == nby) {	// 같은 위치
		switch (dir) {
		case 0:
		{
			if (by > ry) {
				--ny;
			}
			else {
				--nby;
			}
			break;
		}
		case 1:
		{
			if (by > ry) {
				++nby;
			}
			else {
				++ny;
			}
			break;
		}
		case 2:
		{
			if (bx > rx) {
				--nx;
			}
			else {
				--nbx;
			}
			break;
		}
		case 3:
		{
			if (bx > rx) {
				++nbx;
			}
			else {
				++nx;
			}
			break;
		}
		}
	}

	board[nx][ny] = 'R';
	rx = nx; ry = ny;
	board[nbx][nby] = 'B';
	bx = nbx; by = nby;

	return res;
}

void func(int curr)
{
	if (curr > 10) {
		return;
	}

	int temp[12][12];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			temp[i][j] = board[i][j];
		}
	}

	int tx = rx;
	int ty = ry;

	int tbx = bx;
	int tby = by;

	for (int i = 0; i < 4; ++i) {	// 4가지 기울이기
		STATE st = move(i);
		switch (st) {
		case KEEP:
		{
			func(curr + 1);
			break;
		}
		case SUCC:
		{
			res = min(curr, res);
			return;
		}
		case FAIL:
		{
			break;
		}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				board[i][j] = temp[i][j];
			}
		}
		rx = tx; ry = ty; bx = tbx; by = tby;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c;
			cin >> c;
			board[i][j] = c;

			if (c == 'B') {
				bx = i;
				by = j;
			}
			else if (c == 'R') {
				rx = i;
				ry = j;
			}
		}
	}

	func(1);
	if (res == numeric_limits<int>::max()) {
		cout << -1; 
		return 0;
	}
	cout << res;
}