#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	string s;
	cin >> s;

	list<char> editor(s.begin(), s.end());	
	auto cursor = editor.end();

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		char command;
		cin >> command;

		switch (command) {
		case 'L':
			if (cursor == editor.begin()) break;
			--cursor;
			break;

		case 'D':
			if (cursor == editor.end()) break;
			++cursor;
			break;

		case 'B':
			if (cursor == editor.begin()) break;
			--cursor;
			cursor = editor.erase(cursor);
			break;

		case 'P':
			char c;
			cin >> c;

			editor.insert(cursor, c);
			break;
		}
	}

	for (const auto& elem : editor)
		cout << elem;

	// 시간 복잡도 : O(1)
}