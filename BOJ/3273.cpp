#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n; 
	cin >> n;	// 수열의 크기

	vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	// 요소의 크기 1 <= a <= 1,000,000

	// 들어온 x크기만큼의 배열?
	int x;
	cin >> x;
	vector<bool> v(x);
	int res{};
	for (const auto& elem : arr) {
		if (elem >= x) continue;	// a가 x보다 항상 작거나 같다는 조건은 없음. 예외 처리
		if (v[x - elem - 1] == true) {
			res++; 
			continue;
		}

		v[elem- 1] = true;	// 인덱싱은 요소에 -1 해서 접근.
	}

	cout << res;
}