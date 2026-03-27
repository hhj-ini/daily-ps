#include <iostream>

using namespace std;

int N, M, K;
int laptop[42][42];
/*
bool rot[4]{false, true, false, true};
bool reverseR[4]{ false, true, true, false };
bool reverseC[4]{ false, false, true, true };*/

int sticker[12][12];
int temp[42][42];
bool at1(int sr, int sc, int n, int m)
{
	for (int i = 0; i <= N - sr; ++i) {					// 스티커 붙일 위치 결정 (행)
		for (int j = 0; j <= M - sc; ++j) {				// 위치결정 (열)
			bool isDone{ true };

			for (int ii = 0; ii < sr; ++ii) {			// 실질적으로 스티커를 붙이는 코드
				for (int jj = 0; jj < sc; ++jj) {
					int nx = i + ii;
					int ny = j + jj;
					if (sticker[ii][jj] == 0) continue;
					if (laptop[nx][ny] != 1) {
						laptop[nx][ny] = sticker[ii][jj];
					}
					else {
						isDone = false;
						break;
					}
				}
			}
			if (isDone) return true;

			else {
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < M; ++j) {
						laptop[i][j] = temp[i][j];
					}
				}
			}
		}
	}

	return false;
}

bool at2(int sr, int sc, int n, int m)
{
	for (int i = 0; i <= N - sc; ++i) {					// 스티커 붙일 위치 결정 (행)
		for (int j = 0; j <= M - sr; ++j) {				// 위치결정 (열)
			bool isDone{ true };

			for (int ii = sr - 1; ii >= 0; --ii) {			// 실질적으로 스티커를 붙이는 코드
				for (int jj = 0; jj < sc; ++jj) {
					int nx = i + jj;
					int ny = j + (sr - ii - 1);
					if (sticker[ii][jj] == 0) continue;
					if (laptop[nx][ny] != 1) {
						laptop[nx][ny] = sticker[ii][jj];
					}
					else {
						isDone = false;
						break;
					}
				}
			}
			if (isDone) return true;

			else {
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < M; ++j) {
						laptop[i][j] = temp[i][j];
					}
				}
			}
		}
	}

	return false;
}

bool at3(int sr, int sc, int n, int m)
{
	for (int i = 0; i <= N - sr; ++i) {					// 스티커 붙일 위치 결정 (행)
		for (int j = 0; j <= M - sc; ++j) {				// 위치결정 (열)
			bool isDone{ true };

			for (int ii = sr - 1; ii >= 0; --ii) {			// 실질적으로 스티커를 붙이는 코드
				for (int jj = sc - 1; jj >= 0; --jj) {
					int nx = i + (sr - ii - 1);
					int ny = j + (sc - jj - 1);
					if (sticker[ii][jj] == 0) continue;
					if (laptop[nx][ny] != 1) {
						laptop[nx][ny] = sticker[ii][jj];
					}
					else {
						isDone = false;
						break;
					}
				}
			}
			if (isDone) return true;
			
			else {
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < M; ++j) {
						laptop[i][j] = temp[i][j];
					}
				}
			}
		}
	}

	return false;
}

bool at4(int sr, int sc, int n, int m)
{
	for (int i = 0; i <= N- sc; ++i) {					// 스티커 붙일 위치 결정 (행)
		for (int j = 0; j <= M- sr; ++j) {				// 위치결정 (열)
			bool isDone{ true };

			for (int ii = 0; ii < sr; ++ii) {			// 실질적으로 스티커를 붙이는 코드
				for (int jj = sc - 1; jj >= 0; --jj) {
					int nx = i + (sc - jj - 1);
					int ny = j + ii;
					if (sticker[ii][jj] == 0) continue;
					if (laptop[nx][ny] != 1) {
						laptop[nx][ny] = sticker[ii][jj];
					}
					else {
						isDone = false;
						break;
					}
				}
			}
			if (isDone)	return true;
			else {
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < M; ++j) {
						laptop[i][j] = temp[i][j];
					}
				}
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	
	for (int q = 0; q < K; ++q) {
		int r, c;
		cin >> r >> c;

		for (int ii = 0; ii < r; ++ii) {
			for (int iii = 0; iii < c; ++iii) {
				int a;
				cin >> a;
				sticker[ii][iii] = a;
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				temp[i][j] = laptop[i][j];
			}
		}

		if (at1(r, c, N, M)) continue;
		if (at2(r, c, N, M)) continue;
		if (at3(r, c, N, M)) continue;
		if (at4(r, c, N, M)) continue;
		
	}	

	int cnt{0};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (laptop[i][j] == 1) ++cnt;
		}
	}
	cout << cnt;
}