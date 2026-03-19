#include <iostream>

using namespace std;

int N, M;

int arr[9];

void func(int curr)
{
	if (curr == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) {
		arr[curr] = i;
		func(curr + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	func(0);
}