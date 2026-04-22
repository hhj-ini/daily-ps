#include <iostream>
#include <queue>
#include <limits.h>

constexpr int N = 5;
constexpr int EP = 4;

using namespace std;

struct coord {
	coord(int a, int b, int c) :x(a), y(b), z(c), d(0) {};
	coord(int a, int b, int c, int dis) :x(a), y(b), z(c), d(dis) {};
	int x, y, z;
	int d;
};

int dx[6]{ 1, -1, 0, 0, 0, 0 };
int dy[6]{ 0, 0, 1, -1, 0, 0 };
int dz[6]{ 0, 0, 0, 0, 1, -1 };

int maze[6][6][6];	// 입력받은 정보를 저장
int vis[6][6][6];	// 거리 계산 위한 vis 배열

int res{INT_MAX  };		// 최소거리 저장
int arr[5];		// 5개판의 배치 순서를 저장하는 배열
bool isUsed[5];	// 순열 만들기 위해 숫자 사용 여부 저장하는 배열
int seq;

void rotate(int z)
{
	int temp[5][5]{};
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			temp[i][j] = maze[z][N - 1 - j][i];
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			maze[z][i][j] = temp[i][j];
		}
	}
}

void DFS(int temp[5][5][5])
{
	int dis{ -1 };
	queue<coord> q;
	q.push(coord(0, 0, 0));
	vis[0][0][0] = seq;

	while (!q.empty()) {
		coord c = q.front();
		q.pop();

		for (int i = 0; i < 6; ++i) {
			int nx = c.x + dx[i];
			int ny = c.y + dy[i];
			int nz = c.z + dz[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || nz < 0 || nz >= N) continue;
			if (temp[nz][nx][ny] == 0 || vis[nz][nx][ny] == seq) continue;

			if (nx == EP && nz == EP && ny == EP) {
				dis = c.d + 1;
				res = min(dis, res);
				return;
			}
			vis[nz][nx][ny] = seq;
			q.push(coord(nx, ny, nz, c.d + 1));
		}
	}

}

void func(int curr)
{
	if (curr == 5) {
		int temp[5][5][5];
		++seq;
		bool isThereZero{ true };
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				for (int k = 0; k < 5; ++k) {
					temp[i][j][k] = maze[arr[i]][j][k];
					if (temp[i][j][k] == 0) {
						isThereZero = false;
					}
				}
			}
		}

		if (temp[0][0][0] == 0) {
			res = max(-1, res);
			return;
		}

		if (isThereZero == true) {
			res = min(res, 12);
			return;
		}

		DFS(temp);
		return;
	}

	for (int i = 0; i < 5; ++i) {
		if (!isUsed[i]) {	// 판의 순서 정함
			arr[curr] = i;
			isUsed[i] = true;
			for (int j = 0; j < 4; ++j) {
				rotate(i);
				func(curr + 1);
			}
			isUsed[i] = false;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; ++i) {					//z
		for (int ii = 0; ii < 5; ++ii) {			//x
			for (int iii = 0; iii < 5; ++iii) {		//y
				int a;
				cin >> a;

				maze[i][ii][iii] = a;
			}
		}
	}


	func(0);

	if (res == INT_MAX) {
		cout << -1;
		return 0;
	}
	cout << res;
}