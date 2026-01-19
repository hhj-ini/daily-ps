#include <iostream>

using namespace std;

class STACK {
public:
	STACK() 
	{
		data = new int[10];	// 초기 10개짜리 배열 만들어놓음
		data_size = 10;
	}

	void push(int x)
	{
		if (data_size <= size) {
			realloc();
		}
		data[++pos_idx] = x;
		++size;
	}

	int pop()
	{
		if (size == 0) {
			return -1;
		}
		int temp = data[pos_idx];
		--pos_idx;
		--size;
		return temp;
	}

	int top()
	{
		if (size == 0)
			return -1;
		return data[pos_idx];
	}

	int get_size()
	{
		return size;
	}

	int empty()
	{
		return size == 0;
	}
private:
	void realloc()
	{
		int* tmp = data;

		data = new int[size * 2];

		for (int i = 0; i < size; ++i) {
			data[i] = tmp[i];
		}

		delete[] tmp;
	}

	int* data;
	int data_size;
	int pos_idx = -1;
	int size = 0;
};

int main()
{
	STACK st;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		
		if ("push" == s) {
			int x;
			cin >> x;
			st.push(x);
		}
		else if ("pop" == s) {
			cout << st.pop() << '\n';
		}
		else if ("size" == s) {
			cout << st.get_size() << '\n';
		}
		else if ("empty" == s) {
			cout << st.empty() << '\n';
		}
		else {	// top
			cout << st.top() << '\n';
		}
	
	}
}

// 이전에 연결리스트로 풀어봤던 문제
// 동적 배열로 다시 풀어봄!