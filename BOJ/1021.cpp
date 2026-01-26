#include <iostream>
#include <deque>
#include <numeric>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	deque<int> d(N);

	iota(d.begin(), d.end(), 1);
	int res = 0;
	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;	// 뽑아야 할 원소
		
		auto it = find(d.begin(), d.end(), num);
		int frtDis = it - d.begin();
		int backDis = d.end() - it;
		while (d.front() != num) {
			// 2번 연산
			if (frtDis <= backDis)
			{
				d.push_back(d.front());
				d.pop_front();
			}
			else
			// 3번 연산
			{
				d.push_front(d.back());
				d.pop_back();
			}
			++res;
		}
		d.pop_front();
	}

	cout << res;
}