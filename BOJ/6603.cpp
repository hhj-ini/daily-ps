#include <iostream>

using namespace std;

int K;
int nums[15];
int arr[7];
bool isUsed[15];

void func(int curr, int mn)
{
	if (curr == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < K; ++i) {
		if (!isUsed[i] && mn < nums[i]) {
			isUsed[i] = true;
			arr[curr] = nums[i];
			func(curr + 1, nums[i]);
			isUsed[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> K) {
		if (K == 0) break;
		
		for (int i = 0; i < K; ++i) {
			int a;
			cin >> a;
			nums[i] = a;
		}

		func(0, 0);

		cout << '\n';
	}
}