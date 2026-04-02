#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int N, M;

vector<pair<int, int>> vh;
vector<pair<int, int>> vc;
vector<pair<int, int>> ec;
int res = numeric_limits<int>::max();

void func(int curr, int num)
{
	if (curr == M) {
		int length{ 0 };

		for (const pair<int, int>& elem : vh) {
			int chicken_way{ numeric_limits<int>::max() };
			
			for (const pair<int, int>& ch : vc) {
				int r = abs(elem.first - ch.first);
				int c = abs(elem.second - ch.second);

				chicken_way = min(chicken_way, r + c);
			}
			length += chicken_way;
		}
		
		res = min(res, length);
		return;		
	}

	for (auto i = num; i < ec.size(); ++i) {
		vc.push_back(ec[i]);
		func(curr + 1, i + 1);
		vc.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int a;
			cin >> a;
			if (a == 1) {
				vh.push_back(make_pair(i, j));
			}
			else if (a == 2) {
				ec.push_back(make_pair(i, j));
			}
		}
	}

	func(0, 0);
	cout << res;
}