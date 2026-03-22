#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int nums[10];
int arr[10];
int numCnt[10002];

void func(int curr, int mn)
{
	if (curr == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < N; ++i) {
		if (mn <= nums[i] && numCnt[nums[i]] > 0) {
			arr[curr] = nums[i];
			--numCnt[nums[i]];
			func(curr + 1, nums[i]);
			++numCnt[nums[i]];
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
		++numCnt[a];
	}

	sort(nums, nums + N);
	N = unique(nums, nums + N) - nums;

	func(0, 0);
}