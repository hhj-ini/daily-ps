#include <iostream>

using namespace std;

bool isUsed1[62];	// yÁÂÇ¥ ÀúÀå
bool isUsed2[122];	// x+y ÁÂÇ¥ ÀúÀå
bool isUsed3[122];	// x-y+n-1 ÀúÀå

int cnt;
int N;

void func(int curr)
{
	if (N == curr) {
		++cnt;
		return;
	}

	for (int i = 0; i < N; ++i) {
		
	}

	for (int j = 0; j < N; ++j) {
		if (!isUsed1[j] && !isUsed2[curr + j] && !isUsed3[curr - j + N - 1] ) {
			isUsed1[j] = isUsed2[curr + j] = isUsed3[curr - j + N - 1] = true;
			func(curr + 1);
			isUsed1[j] = isUsed2[curr + j] = isUsed3[curr - j + N - 1] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> N;
	func(0);

	cout << cnt;
}