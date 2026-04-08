#include <iostream>

using namespace std;
int dy[4]{ 1, -1, 0, 0 };// 동 서 북 남
int dx[4]{ 0, 0, -1, 1 };// 동 서 북 남

int board[22][22];
int dice[4][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a;
			cin >> a;

			board[i][j] = a;			
		}
	}

	for (int i = 0; i < K; ++i) {
		int dir;
		cin >> dir;
		
		int nx = x + dx[dir - 1];
		int ny = y + dy[dir - 1];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		
		int temp[4]{};
		// 주사위 회전
		switch (dir) {	// 1-4 순서대로 동서북남
		case 1:	// 동
		{
			for (int ii = 0; ii < 3; ++ii) {
				int curr = (ii - 1 + 3) % 3;
				temp[ii] = dice[1][curr];
			}
			for (int ii = 0; ii < 3; ++ii) {
				dice[1][ii] = temp[ii];
			}
			int t = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = t;
			break;
		}
		case 2:	// 서
		{
			for (int ii = 0; ii < 3; ++ii) {
				int curr = (ii + 1) % 3;
				temp[ii] = dice[1][curr];
			}
			for (int ii = 0; ii < 3; ++ii) {
				dice[1][ii] = temp[ii];
			}

			int t = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = t;
			break;
		}
		case 3:	// 북
		{
			for (int ii = 0; ii < 4; ++ii) {
				int curr = (ii + 1) % 4;
				temp[ii] = dice[curr][1];
			}

			for (int ii = 0; ii < 4; ++ii) {
				dice[ii][1] = temp[ii];
			}
			break;
		}
		case 4:	// 남
		{
			for (int ii = 0; ii < 4; ++ii) {
				int curr = (ii - 1 + 4) % 4;
				temp[ii] = dice[curr][1];
			}
			for (int ii = 0; ii < 4; ++ii) {
				dice[ii][1] = temp[ii];
			}
			break;
		}
		}

		if (board[nx][ny] == 0) {
			board[nx][ny] = dice[3][1];
		}
		else {
			dice[3][1] = board[nx][ny];
			board[nx][ny] = 0;
		}
		
		cout << dice[1][1] << '\n';

		x = nx;
		y = ny;
	}
}