#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[10];
int nums[10];
int numsCnt[10002];

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
		if (0 < numsCnt[nums[i]]) {
			--numsCnt[nums[i]];
			arr[curr] = nums[i];
			func(curr + 1);
			++numsCnt[nums[i]];
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
		++numsCnt[a];
	}

	sort(nums, nums + N);
	
	N = unique(nums, nums + N) - nums;


	func(0);
}