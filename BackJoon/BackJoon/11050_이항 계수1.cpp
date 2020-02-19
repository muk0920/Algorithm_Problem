#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
using namespace std; 
int dp[11][11]; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	
	int N, K; 
	cin >> N >> K; 
	dp[1][0] = 1, dp[1][1] = 1; 
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0 || i == j) {
				dp[i][j] = 1; 
				continue; 
			}
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; 
		}
	}
	
	cout << dp[N][K] << "\n";
	
}