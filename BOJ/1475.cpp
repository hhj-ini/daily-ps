#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;	// 방번호	(N <= 1,000,000)

	// 필요한 세트는 가장 많은 숫자가 나온 횟수
	// 그러나 6이나 9는 서로가 될 수 있음

	int arr[10]{};

	while (N > 0) {
		++arr[N % 10];
		N /= 10;
	}

	int max{};
	double six_and_nine = (arr[6] + arr[9]) / 2.0;
	int s_a_n_integer = (arr[6] + arr[9]) / 2;
	arr[6] = six_and_nine > s_a_n_integer ? s_a_n_integer + 1: s_a_n_integer;
	for (int i = 0; i < 9; ++i) {
		if (arr[i] > max)
			max = arr[i];
	}

	cout << max;
}
