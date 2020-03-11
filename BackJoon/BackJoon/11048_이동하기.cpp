#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std; 
int N, M; 
int map[1000][1000]; 
int dp[1000][1000]; 
int dr[3] = { 0,1,1 }; 
int dc[3] = { 1,1,0 };

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_11048.txt", "r", stdin);
	cin >> N >> M; 
	for(int i=0; i<N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j]; 
		}
	}

	// 초기화 
	dp[0][0] = map[0][0];
	for (int i = 1; i < M; i++) dp[0][i] = dp[0][i - 1] + map[0][i];  // 1행
	for (int i = 1; i < N; i++)	dp[i][0] = dp[i - 1][0] + map[i][0];  // 1열 

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j])) + map[i][j];
		}
	}

	cout << dp[N-1][M-1]<<"\n"; 
}	