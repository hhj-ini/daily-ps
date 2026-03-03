#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

void setNewPair(pair<int, int>& p, int N, int M, 
	const vector<vector<int>>& pic, const vector<vector<bool>>& vis)
{
	for (int i = p.first; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (1 == pic[i][j] && false == vis[i][j]) {	// 그림부분이면서 아직 방문하지 않았을 것(동시만족)
				p = make_pair(i, j);
				return;
			}
		}
	}
	p =  make_pair(-1, -1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;

	vector<vector<int>> picture;

	
	for (int i = 0; i < N; ++i) {
		vector<int> temp;
		for (int j = 0; j < M; ++j) {
			int n;
			cin >> n;
			temp.push_back(n);
		}
		picture.push_back(temp);
	}

	int maxSize{ 0 };	// 가장 넓은 그림의 넓이	(그림이 없는 경우 가장 넓은 그림의 넓이 0.)
	int numOfPic{ 0 };	// 그림의 개수

	vector<vector<bool>> vis(N, vector<bool>(M, false));
	
	pair<int, int> p{ 0,0 };
		
	setNewPair(p, N, M, picture, vis);
	
	while (p.first >= 0 && p.first < N && p.second >= 0 && p.second < M) {
		++numOfPic;	// 그림수 증가
		
		vis[p.first][p.second] = true;
		//picture[p.first][p.second] = 0;

		queue<pair<int, int>> q;
		q.push(p);

		int size{ 1 };
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	// 범위를 넘어가면 continue
				if (true == vis[nx][ny] || 1 != picture[nx][ny]) continue;	// 이미 방문했거나 칠해져있지 않으면 continue

				vis[nx][ny] = true;
				//picture[nx][ny] = 0;	// find 알고리즘에서 오류 생기지 않게 찾은 곳은 그림 지우기.
				q.push(make_pair(nx, ny));
				++size;	// 현재 그림의 넓이
			}

		}

		if (size > maxSize) {
			maxSize = size;
		}

		setNewPair(p, N, M, picture, vis);
	}

	cout << numOfPic << "\n" << maxSize;

	// 시간 복잡도: O(N*M)

}