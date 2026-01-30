#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	while (getline(cin, s)) {
		if (s[0] == '.' && s.length() < 2) {	// 온점만 들어온 경우
			break;
		}

		stack<char> st;
		bool isBalanced{ true };

		for (const auto& elem : s) {
			switch (elem) {
			case '(':
			{
				st.push('(');
				break;
			}
			case '[':
			{
				st.push('[');
				break;
			}
			case ')':
			{
				if (st.empty()) {
					isBalanced = false;
					break;
				}					
				
				if ('(' == st.top()) {
					st.pop();
				}
				else {
					isBalanced = false;
				}
				break;
			}
			case ']':
			{
				if (st.empty()) {
					isBalanced = false;
					break;
				}
				
				if ('[' == st.top()) {
					st.pop();
				}
				else {
					isBalanced = false;
				}
				break;
			}
			}
		}

		if (st.size() > 0) {	// 괄호가 하나라도 남아있으면 균형잡히지 않은 쌍
			isBalanced = false;
		}

		if (isBalanced) {
			cout << "yes\n";
			continue;
		}
		cout << "no\n";
	}

	// 시간복잡도 O(N)
	
}