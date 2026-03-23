#include <iostream>

using namespace std;

struct egg {
	egg() :durab{ 0 }, weight{ 0 } {};
	egg(int a, int b) :durab{ a }, weight{ b } {};
	int durab;
	int weight;
};

int N;
egg eggs[10];
int cnt;
void func(int curr)
{
	if (curr == N) {
		int n{};
		for (int i = 0; i < N; ++i) {
			if (eggs[i].durab <= 0) ++n;
		}

		cnt = max(cnt, n);
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (curr == i) continue;
		if (eggs[i].durab > 0 && eggs[curr].durab > 0) {
			egg curTemp = eggs[curr];
			egg temp = eggs[i];
			
			eggs[i].durab -= eggs[curr].weight;
			eggs[curr].durab -= eggs[i].weight;

			func(curr + 1);
			eggs[i] = temp;
			eggs[curr] = curTemp;
		}
		else {
			func(curr + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;

		eggs[i] = egg(a, b);
	}

	func(0);
	cout << cnt;
}