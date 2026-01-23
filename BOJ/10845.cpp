#include <iostream>
#include <queue>

using namespace std;

// head(보초노드) -> a -> b -> tail
// head->

class NODE {
public:
	NODE(int a) : x(a)
	{
		next = nullptr;
	}
	int x;
	NODE* next;
};

class QUEUE {
public:
	QUEUE()
	{
		head = new NODE(-1);

		tail = head;
		// 초기에는 tail 이 head 를 가리키게 함
	}

	inline int empty()
	{
		return tail == head;	// tail과 head가 같으면 비어있는 상태
	}

	void push(int x)
	{
		NODE* n = new NODE(x);
		tail->next = n;	// 연결
		tail = n;	// n을 tail 로 설정

		++size;
	}

	int pop()
	{
		int res = -1;
		if (head!= tail) 	{// 비어있지 않을떄
			NODE* temp = head;
			
			res = head->next->x;

			head = head->next;

			delete temp;
			--size;
		}
		return res;
	}

	int front()
	{
		if (!empty()) {
			return head->next->x;
		}
		return -1;
	}

	int back()
	{
		if (!empty()) {
			return tail->x;
		}
		return -1;
	}
	
	int size = 0;
private:
	NODE* tail, *head;
	
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;

	cin >> N;

	QUEUE q;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		if ("push" == s) {
			int a;
			cin >> a;
			q.push(a);
		}
		else if ("pop" == s) {
			cout << q.pop() << "\n";
		}
		else if ("size" == s) {
			cout << q.size << "\n";
		}
		else if ("front" == s) {
			cout << q.front() << "\n";
		}
		else if ("back" == s) {
			cout << q.back() << "\n";
		}
		else if ("empty" == s) {
			cout << q.empty() << "\n";
		}
	}
}