#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int dir[3]{ -1, 1, 0 };
int tp[3]{ 1, 1, 2 };

int dist[100'002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	fill(dist, dist + 100'002, INT_MAX);
	
	queue<int> q;
	dist[N] = 0;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front();
		if (K == cur) {
			cout << dist[cur];
			return 0;
		}
		q.pop();

		for (int i = 0; i < 3; ++i) {
			int nx = (cur * tp[i]) + dir[i];

			if (nx < 0 || nx >= 100'001) continue;
			if (INT_MAX != dist[nx]) continue;

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}
}