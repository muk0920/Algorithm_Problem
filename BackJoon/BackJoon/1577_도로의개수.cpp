#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int N, M, K; 
int broken[210][210]; 
long long dp[101][101]; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_1577.txt", "r", stdin);
	cin >> M >> N >> K;
	int r1, c1, r2, c2; 
	for (int i = 0; i < K; i++) {
		cin >> c1 >> r1 >> c2 >> r2; 
		broken[r1+r2][c1+c2] = 1; 
	}
	// dp 초기화 
	for (int i = 1; i <= N; i++) { // 세로 도로 초기화
		if (broken[2 * i - 1][0] == 1)	break; 
		dp[i][0] = 1; 
	}
	for (int j = 1; j <= M; j++) {
		if (broken[0][2*j-1] == 1)	break;
		dp[0][j] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (broken[2 * i][2 * j - 1] != 1)		dp[i][j] += dp[i][j-1];	// 가로도로 
			if (broken[2 * i - 1][2 * j] != 1)		dp[i][j] += dp[i-1][j];  // 세로도로
		}
	}
	cout << dp[N][M]<<"\n";
}