#include <iostream>

using namespace std;

constexpr int CLEAN{ 2 };

int dx[4]{ -1, 0, 1, 0 };
int dy[4]{ 0, 1, 0, -1 };
// 0 북 1 동 2 남 3 서

int N, M;
int room[52][52];
int cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int x, y, d;
	cin >> x >> y >> d;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a;
			cin >> a;

			room[i][j] = a;
		}
	}

	while (true) {
		if (room[x][y] == 0) {	// 1번 : 현재 칸이 청소되지 않은 경우
			room[x][y] = CLEAN;	// 청소
			++cnt;
		}

		bool isExist{ false };
		for (int i = 0; i < 4; ++i) {	// 2, 3단계 체크
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (room[nx][ny] == 0) {	// 청소되지 않은 빈칸이 있음
				isExist = true;
			}
		}

		if (!isExist) {	// 2번 : 청소되지 않은 빈칸이 없음
			int nx = x - dx[d];	// 방향 유지한 채로 후진
			int ny = y - dy[d];

			if (room[nx][ny] == 1) {	// 후진할 수 없는 경우
				cout << cnt;
				return 0;
			}

			x = nx;
			y = ny;	// 한칸 후진
		}
		else {	// 3번 : 청소되지 않은 빈칸이 있음
			int temp = d - 1;
			d = (temp == -1) ? 3 : temp;	// 반시계 90도 회전
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (room[nx][ny] == 0) {	// 청소되지 않은 빈칸이면 전진
				x = nx;
				y = ny;
			}
		}
	}
}