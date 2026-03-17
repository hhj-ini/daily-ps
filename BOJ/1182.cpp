#include <iostream>
#include <unordered_map>

using namespace std;

int lst[22];

int N, S;
int cnt;

void func(int curr, int sum)
{
	if (N == curr) {	
		if (S == sum) {
			++cnt;
		}
		//cout << curr << ' ' << sum << '\n';
		return;
	}

	func(curr + 1, sum + lst[curr]);	// i번째 수를 더함
	func(curr + 1, sum);			// i번째 수를 더하지 않음
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> S;

	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		
		lst[i] = a;
	}

	func(0, 0);
	if (S == 0) --cnt;
	cout << cnt;
}