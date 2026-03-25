#include <iostream>

using namespace std;

struct cctv {
	cctv() : x(0), y(0), type(0) {}
	cctv(int a, int b, int c) : x(a), y(b), type(c) {}
	int x, y;
	int type;
};

int dx[5]{ 1, -1, 0, 0, 0 };	// 오른쪽, 왼쪽, 위, 아래, 가만히
int dy[5]{ 0, 0, 1, -1, 0 };

int d[4][4][3]
{
	{ {0, 4, 4}, {1, 4, 4}, {2 ,4, 4}, {3, 4, 4} },	//[0][0][0], [0][1][0] ...
	{ {0, 1, 4}, {2,3, 4}, {0,1, 4}, {2,3, 4} }, // [1][0][0-1], [1][1][0-1] ...
	{ {0,2, 4}, {1,2, 4}, {1, 3, 4}, {0, 3, 4} }, // 
	{ {0,1,2}, {1,2, 3}, {0, 2, 3}, {0, 1, 3} }
};

int N, M;

int arr[9][9];
cctv cctvs[9];
int res{ 65 };
int cn;

void watch(int dir, int t, int x, int y)
{
	for (int ii = 0; ii < 3; ++ii) {
		for (int iii = 1; iii < 8; ++iii) { // 길이 결정
			int nx = x + dx[d[t][dir][ii]] * iii;
			int ny = y + dy[d[t][dir][ii]] * iii;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
			if (arr[nx][ny] == 6) break;

			if (arr[nx][ny] == 0)
				arr[nx][ny] = 9;
		}
	}
}

void func(int curr)
{
	if (curr == cn) {
		int cnt{ 0 };
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (arr[i][j] == 0) ++cnt;
			}
		}
		res = min(cnt, res);
		return;
	}

	int t = cctvs[curr].type;

	int temp[9][9];
	for (int ii = 0; ii < N; ++ii) {
		for (int jj = 0; jj < M; ++jj) {
			temp[ii][jj] = arr[ii][jj];
		}
	}

	for (int i = 0; i < 4; ++i) {
		if (t != 5)
			watch(i, t - 1, cctvs[curr].x, cctvs[curr].y);

		func(curr + 1);
		for (int ii = 0; ii < N; ++ii) {
			for (int jj = 0; jj < M; ++jj) {
				arr[ii][jj] = temp[ii][jj];
			}
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

			arr[i][j] = a;
			if (a != 0 && a != 6) {
				cctvs[cn] = cctv(i, j, a);
				++cn;
				// 번호와 좌표 저장
			}
		}
	}

	for (int i = 0; i < cn; ++i) {
		if (cctvs[i].type == 5) {	// 5번 cctv는 회전해도 의미 없기 때문에 먼저 실행
			int x = cctvs[i].x;
			int y = cctvs[i].y;

			for (int ii = 0; ii < 4; ++ii) {		// 방향 결정
				for (int iii = 0; iii < 8; ++iii) { // 길이 결정
					int nx = x + dx[ii] * iii;
					int ny = y + dy[ii] * iii;

					if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (arr[nx][ny] == 6) break;

					if (arr[nx][ny] == 0) arr[nx][ny] = -1;
				}
			}
		}
	}

	func(0);

	cout << res;
}