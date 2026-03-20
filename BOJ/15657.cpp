#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[10];
int nums[10];

void func(int curr, int mn)
{
	if (curr == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (mn <= nums[i]) {
			arr[curr] = nums[i];
			func(curr + 1, nums[i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		nums[i] = a;
	}

	sort(nums, nums + N);

	func(0, 0);
}