#include <iostream>

using namespace std;

int N, M;

int arr[10];

void func(int curr, int nm)
{
	if (M == curr ) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = curr + 1; i <= N; ++i) {
		if (nm < i) {
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