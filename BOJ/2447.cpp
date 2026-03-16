#include <iostream>

using namespace std;

char star[3000][3000];

void func(int n, int r, int c)
{
	if (n == 3) {
		for (int i = r; i < r + 3; ++i) {
			for (int j = c; j < c + 3; ++j) {
				if (r + 1 == i && c + 1 == j) continue;
				star[i][j] = '*';
			}
		}
		return;
	}


	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (1 == i && 1 == j) continue;
			func(n / 3, r +(i*(n/3)), c +( j*(n/3)));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			star[i][j] = ' ';
		}
	}
	func(N, 0, 0);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}