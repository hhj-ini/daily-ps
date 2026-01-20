#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		list<char> input;
		auto cursor = input.begin();
		for (const auto& elem : s) {
			switch (elem) {
			case '<':
				if (cursor != input.begin()) {
					--cursor;
				}
				break;
			case '>':
				if (cursor != input.end()) {
					++cursor;
				}
				break;
			case '-':
				if (cursor != input.begin()) {
					cursor = input.erase(--cursor);
				}
				break;
			default:	// ¾ËÆÄºª ÀÔ·Â
				input.insert(cursor, elem);
				break;
			}
		}

		for (const auto& elem : input) {
			cout << elem;
		}

		cout << '\n';
	}
}