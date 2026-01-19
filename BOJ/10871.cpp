#include <iostream>

using namespace std;

int main()
{
	// 정수 N개로 이루어진 수열 A와 정수 X가 주어짐
	// A에서 X보다 작은 수를 모두 출력하는 프로그램 작성

	int N, X;

	cin >> N >> X;

	int a;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		if (a < X) cout << a << ' ';
	}
	// 시간 복잡도 : O(N)
}