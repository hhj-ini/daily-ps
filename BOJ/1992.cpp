#include <iostream>

using namespace std;

int arr[66][66];

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
		cout << curr;
		return;
	}
	else {
		cout << "(";
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				func(n / 2, r + (n / 2) * i, c + (n / 2) * j);
			}
		}
		cout << ")";
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
			char c;
			cin >> c;

			arr[i][j] = c - '0';
		}
	}

	func(N, 0, 0);
}