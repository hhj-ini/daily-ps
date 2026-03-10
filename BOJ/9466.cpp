#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int student[100002];
int vis[100002];
int team[100002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int n = 1; n <= N; ++n) {
			int num;
			cin >> num;
			student[n] = num;
		}

		for (int i = 1; i <= N; ++i) {
			if (0 != vis[i]) continue;	// 이전 방문 사이클에 포함된 학생, 경로에 포함된 학생
			int curr = i;

			while (0 == vis[curr]) {
				vis[curr] = i;
				curr = student[curr];
			}
			
			if (i == vis[curr]) {	// 사이클 발견
				while (0 == team[curr]) {
					team[curr] = 1;
					curr = student[curr];
				}
			}
		}

		int solo = count(&team[1], &team[N] + 1, 0);	// 팀이 아닌 수 세기
		cout << solo << '\n';

		fill(&team[1], &team[N] + 1, 0);	// 팀 정보 배열 초기화
		fill(&vis[1], &vis[N] + 1, 0);	// 방문 정보 배열 초기화
	}

	// 시간 복잡도:O(2*N);
}