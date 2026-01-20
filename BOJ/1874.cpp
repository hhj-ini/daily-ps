#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	// 알고리즘 설명
	// 스택에 오름차순으로 넣다가 top이 수열의 현재 위치와 값이 같다면 pop
	// 그렇게 반복해서 수열을 만들어서 마지막에 비교

	// 모든 수가 한번씩은 들어갔다 나와야하기때문에
	// 연산 횟수는 무조건 2* N 이 될것임.



	int N;
	cin >> N;

	vector<int> v;
	
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	vector<char> commandVector;
	int currIdx = 0;
	stack<int> st;
	vector<int> res(N);
	int num = 1;
	for (int i = 0; i < 2*N; ++i) {
		if (!st.empty()) {
			if (v[currIdx] == st.top()) {
				res[currIdx] = st.top();
				st.pop();
				commandVector.push_back('-');
				++currIdx;
				continue;
			}
		}
		st.push(num);
		commandVector.push_back('+');
		++num;
	}

	for (int i = 0; i < N; ++i) {
		if (res[i] != v[i]) {
			cout << "NO";
			return 0;
		}
	}

	for (const auto& elem : commandVector) {
		cout << elem << '\n';
	}
	// 시간 복잡도 : O(2n);
	// 공간 복잡도 : O(2n);
}