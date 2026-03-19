#include <iostream>

using namespace std;

int N, M;

int arr[10];

void func(int curr, int mn)
{
	if (curr == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (mn <= i) {
			arr[curr] = i;
			func(curr + 1, i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	func(0, 0);
}