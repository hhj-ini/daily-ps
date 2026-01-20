#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	int res = A * B * C;

	string s = to_string(res);

	int arr[10]{ 0, };
	for (const auto& elem : s)
		++arr[elem - '0'];

	for (const auto& elem : arr)
		cout << elem << '\n';
}
