#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<int> v('z' - 'a' + 1, 0);	// 알파벳 개수만큼 메모리 할당. (초기값 0)
	for (const char& elem : s) 
		++v[elem - 'a'];
	

	for (const int& elem : v)
		cout << elem << ' ';

	// 시간 복잡도 : O(N)
}