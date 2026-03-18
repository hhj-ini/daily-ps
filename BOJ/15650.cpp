#include <iostream>

using namespace std;

int N, M;

int arr[10];
bool isUsed[10];
bool com[40];

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
		if (!isUsed[i] && nm < i) {
			arr[curr] = i;
			isUsed[i] = true;
			func(curr + 1, i);
			isUsed[i] = false;
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