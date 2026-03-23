#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[9];
int nums[9];

void func(int curr)
{
	if (curr == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i) {
		arr[curr] = nums[i];
		func(curr + 1);
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
	N = unique(nums, nums + N) - nums;

	func(0);
}