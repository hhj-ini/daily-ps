#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string p;
		cin >> p;	// 수행할 함수

		int N;
		cin >> N;	// num of array

		char c;
		cin >> c;	// "["

		deque<int> d;
		while (true) {
			int num;
			if (cin >> num)
				d.push_back(num);
			else
				cin.clear();
		
			cin >> c;
			if (',' != c)
				break;
		}

		bool dir = false;	// false 면 front.
		bool error = false;	// true 면 error 출력
		for (const auto& elem : p) {
			if ('R' == elem) {
				dir = !dir;
			}
			else if ('D' == elem) {
				if (d.empty()) {
					error = true;
					break;
				}
					
				if (dir)
					d.pop_back();
				else
					d.pop_front();
			}
		}
	
		if (error) {
			cout << "error\n";
			continue;
		}
		
		cout << "[";
		if (!d.empty()) {
			if (dir) {	// 역방향
				for (int i = d.size() - 1; i > 0; --i) {
					cout << d[i] << ",";
				}
				cout << d.front();
			}
			else {	// 정방향
				for (int i = 0; i < d.size() - 1; ++i) {
					cout << d[i] << ",";
				}
				cout << d.back();
			}
		}
		cout << "]\n";
	}
}