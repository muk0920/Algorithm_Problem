#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std; 
int N, S, M; 
vector<int> vol; 
vector<int>dp; 
int ans = 0; 

void DFS(int idx, int sum) {
	if (idx == N) {
		if (sum > ans) {
			ans = sum; 
		}
		return; 
	}

	if (sum + (dp[N - 1] - dp[idx] + vol[idx]) < ans)
		return;

	for (int i = idx; i < vol.size(); i++) {
		if (sum + vol[i] <= M)	DFS(i + 1, sum + vol[i]); 
		if (sum - vol[i] >= 0)	DFS(i + 1, sum - vol[i]); 
	}	
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_1495.txt", "r", stdin); 
	cin >> N >> S >> M; 
	vol = vector<int>(N,0); 
	dp = vector<int>(N, 0); 
	for (int i = 0; i < N; i++) {
		cin >> vol[i]; 
	}
	dp[0] = vol[0]; 
	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1] + vol[i]; 
	}
	DFS(0, S); 

	if (ans == 0) cout << "-1\n"; 
	else cout << ans<<"\n"; 
}