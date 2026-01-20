#include <iostream>
#include <stack>

using namespace std;

int main()
{
	
	stack<int> st;

	int K;
	cin >> K;

	for (int i = 0; i < K; ++i) {
		int num; 
		cin >> num;

		switch (num) {
		case 0 :
			st.pop();
			break;
		default:
			st.push(num);
			break;
		}
	}
	int sum{};
	while (st.empty() == false) {
		sum += st.top();
		st.pop();
	}

	cout << sum;
}