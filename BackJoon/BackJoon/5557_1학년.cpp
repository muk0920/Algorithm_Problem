#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <algorithm>

using namespace std;
int N;
int arr[101]; 
int dp[21][101];
long long ans =-1; 

int Calculator(int idx, int sum) {
	
	if (dp[sum][idx] != 0)	return dp[sum][idx];

	if (idx == N - 1) {
		if (sum == arr[N - 1]) {
			return dp[sum][idx]=1 ;
		}
		return 0;
	}

	if (sum + arr[idx] <= 20) {
		dp[sum][idx] = max(dp[sum][idx], Calculator(idx + 1, sum + arr[idx]));
	}
	if (sum >= arr[idx]) {
		dp[sum][idx] = max(dp[sum][idx], Calculator(idx + 1, sum - arr[idx]));
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	freopen("input_5557.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> arr[i]; 

	Calculator(1, arr[0]);

	cout << dp[arr[0]][0] << "\n"; 
}