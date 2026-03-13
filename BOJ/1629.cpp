#include <iostream>

using namespace std;

long long func(long long a, long long b, long long c)
{
	if (b == 1) {
		return a % c;
	}
	if (b == 0) {
		return 1;
	}

	long long res{ 1 };

	if (b % 2 == 0) {
		long long temp = func(a, b / 2, c) % c;
		res = (temp * temp) % c;
	}
	else {
		long long temp = func(a, (b - 1) / 2, c) % c;
		res = ((temp * temp) % c * (a % c)) % c;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B, C;
	cin >> A >> B >> C;

	cout << func(A, B, C);
}