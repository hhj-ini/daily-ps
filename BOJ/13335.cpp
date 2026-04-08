#include <iostream>

using namespace std;

int n, w, L;
int res;
int weight[1002];
int truckState[1002];

int currWeight;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> w >> L;	
	// 트럭수, 다리길이, 최대하중

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		weight[i] = k;
		truckState[i] = -1;
	}

	bool isFinish{ false };

	while (!isFinish) {		
		int curr{ n };
		for (int i = 0; i < n; ++i) {
			if (truckState[i] < 0) { 
				curr = i;
				break; 
			}
			if (++truckState[i] == w) {	// 다리 통과 완료
				currWeight -= weight[i];
				if (i == n - 1) isFinish = true;
			}
		}
		
		if (L >= currWeight + weight[curr]) {	// 최대하중 미만이면 트럭 진입시키기
			truckState[curr] = 0;
			currWeight += weight[curr];
		}
		++res;
	}

	cout << res;
}