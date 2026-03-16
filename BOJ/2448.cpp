#include <iostream>

using namespace std;

char star[3100][6200];

void func(int n, int r, int c)
{
	if (n == 3) {
		star[r][c] = '*';
		star[r + 1][c - 1] = star[r + 1][c + 1] = '*';
		
		for (int i = c - 2; i <= c + 2; ++i) {
			star[r + 2][i] = '*';
		}
		return;
	}

	func(n / 2, r, c);
	func(n / 2, r + (n / 2), c + n/2);
	func(n / 2, r + (n / 2), c - n/2);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;	// 출력 길이

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2 * N; ++j) {
			star[i][j] = ' ';
		}
	}

	func(N, 0, N-1);


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2 * N; ++j) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}