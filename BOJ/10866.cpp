#include <iostream>

using namespace std;

int deque[20001];
int tail{ 20000 / 2 };
int head{ 20000 / 2 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		int a = 0;
		if ("push_back" == s) {
			cin >> a;
			deque[++tail] = a;
		}
		else if ("push_front" == s) {
			cin >> a;
			deque[head] = a;
			--head;
		}
		else if ("pop_back" == s) {
			if (tail != head) {
				cout << deque[tail] << "\n";
				--tail;
			}
			else {
				cout << "-1\n";	
			}
		}
		else if ("pop_front" == s) {
			if (tail != head) {
				cout << deque[++head] << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if ("size" == s) {
			cout << tail - head <<"\n";
		}
		else if ("empty" == s) {
			if (tail!=head) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if ("front" == s) {
			if (tail != head) {
				cout << deque[head+1] << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if ("back" == s) {
			if (tail != head) {
				cout << deque[tail] << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
}