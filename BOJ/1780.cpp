#include <iostream>

using namespace std;

int arr[3000][3000];
int cnt[3];

void func(int n, int r, int c)
{
	int curr = arr[r][c];
	bool isSame{ true };
	for (int i = r; i < r + n; ++i) {
		for (int j = c; j < c + n; ++j) {
			if (curr != arr[i][j]) {
				isSame = false;
			}
		}
	}

	if (isSame) {
		++cnt[curr + 1];
		return;
	}
	else {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				func(n / 3, r + (i * (n / 3)), c + (j * (n / 3)));
			}
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
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}

	func(N, 0, 0);

	cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2];
}