#include <iostream>
#include <queue>
using namespace std;

int wheel[4][8];	// 0, 4 -> 좌 우
int state[4];	// 1-4번의 9시 방향의 index 저장된 array
queue<pair<int, int>> q;

void toLeft(int num, int currdir)	// 기준 바퀴에서 왼쪽으로
{
	if (num - 1 < 0) return;
	int curr = (state[num] - 2 + 8) % 8;	// 현재 바퀴의 9시 방향
	int another = (state[num - 1] + 2 + 8) % 8;	// 맞닿은 부분

	if (wheel[num][curr] == wheel[num - 1][another]) return;	// 같은 극 회전 안함

	int newdir = currdir * -1;	// -1은 1이 되고 1은 -1이 됨.	(회전 반대방향)
	toLeft(num - 1, newdir);	// 왼쪽으로 나아감

	q.push(make_pair(num - 1, newdir));	// 회전 정보 저장
}

void toRight(int num, int currdir)	
{
	if (num + 1 >= 4) return;

	int curr = (state[num] + 2 + 8) % 8;	// 현재 바퀴의 3시 방향
	int another = (state[num + 1] - 2 + 8) % 8;		// 맞닿은 부분

	if (wheel[num][curr] == wheel[num + 1][another]) return;	// 같으면 회전 x
	int newdir = currdir * -1;
	toRight(num + 1, newdir);

	q.push(make_pair(num + 1, newdir));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			char a;
			cin >> a;
			// n극은 0, s극은 1
			wheel[i][j] = static_cast<int>(a-'0');
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; ++i) {
		int n, d;	// 번호, 방향
		cin >> n >> d;
		// 1이면 시계방향, -1이면 반시계방향
			
		toLeft(n-1, d);
		toRight(n-1, d);

		q.push(make_pair(n - 1, d));

		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			state[p.first] = (state[p.first] - p.second + 8) % 8;	// 회전
		}
	}

	int res{};
	for (int i = 0; i < 4; ++i) {
		int score{ 1 };
		for (int j = 0; j < i; ++j) {
			score *= 2;
		}
		
		res += wheel[i][state[i]] * score;
	}

	cout << res;
}