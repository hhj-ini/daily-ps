#include <iostream>
#include <list>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	list<int> lst(N);
	
	int num = 1;
	for (auto i = lst.begin(); i != lst.end(); ++i) {
		*i = num;
		++num;
	}

	auto it = lst.begin();

	cout << "<";
	while (lst.size() > 1) {
		for (int i = 0; i < K - 1; ++i) {
			++it;
			if (it == lst.end())
				it = lst.begin();
		}
		
		cout << *it << ", ";
		it = lst.erase(it);
		if (it == lst.end())
			it = lst.begin();
	}

	cout << *lst.begin() << ">";
}