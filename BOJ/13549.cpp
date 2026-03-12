#include <iostream>
#include <queue>

using namespace std;

// 순간이동, 왼쪽, 오른쪽
// 2*x + 0, 1*x -1, 1*x + 1
int dx[3]{ 0, -1, 1 };
int tp[3]{ 2, 1, 1 };

// 순간이동인 경우에는 1을 더하지 않기 위해 초를 배열로 둠
int sec[3]{ 0, 1, 1 };	

int dist[200002];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	deque<int> d;
	d.push_back(N);
	dist[N] = 1;	// 시작을 1로 지정. 결과에는 1을 빼야 함

	while (!d.empty()) {
		int curr = d.front();
		d.pop_front();

		for (int i = 0; i < 3; ++i) {
			int nx = (curr * tp[i]) + dx[i];

			if (nx < 0 || nx >= 200000) continue;
			
			if (0 != dist[nx]) continue;	

			if (i == 0) {
				d.push_front(nx);
			}
			else {
				d.push_back(nx);
			}

			dist[nx] = dist[curr] + (1 * sec[i]);
		}
	}

	cout << dist[K] - 1;

	// 시간 복잡도: O(N);
}