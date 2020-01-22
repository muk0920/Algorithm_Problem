#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std; 
int n; 
deque<int> grape_juice; 
int dp[10001][3]; // 행-포도주의 위치를 의미. 열-현재 위치에서 포도주를 연속으로 먹은 횟수를 의미

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input.txt", "r", stdin);
	cin >> n; 
	grape_juice = deque<int>(n, 0); 

	for (int i = 0; i < n; i++) {
		cin >> grape_juice[i];
	}
	// dp 초기 설정 
	dp[0][0] = 0, dp[0][1] = grape_juice[0];
	dp[1][0] = max(dp[0][0], dp[0][1]), dp[1][1] = dp[0][0] + grape_juice[1], dp[1][2] = dp[0][1] + grape_juice[1];

	for (int i = 2; i < n; i++) { 
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][0] = max(dp[i][0], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + grape_juice[i];
		dp[i][2] = dp[i - 1][1] + grape_juice[i];
	}

	int answer = max(dp[n - 1][0], dp[n - 1][1]); 
	answer = max(dp[n - 1][2], answer);

	cout << answer << "\n";

}