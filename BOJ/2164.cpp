#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 2초, N <= 500,000
	// 시간복잡도 O(NlgN) 이하 요구
	 
	int N;

	cin >> N;

	vector<int> v(N);

	v.reserve(N * 2);	// 미리 N*2 만큼의 사이즈 할당. 공간복잡도 O(2N)

	iota(v.begin(), v.end(), 1);

	// 알고리즘
	// 벡터를쓰고 팝만 안하고 그냥 인덱스만 뒤로 넘기면 되지 않을라나?

	// 1. 제일 위에 있는 카드를 바닥에 버림

	auto it = v.begin();
	int idx = 0;
	while (true) {
		if (idx == v.size() -1) {
			break;
		}
		++idx;
		if (idx % 2 != 0) {
			v.push_back(v[idx]);
		}
	}
	cout << v[idx];
}