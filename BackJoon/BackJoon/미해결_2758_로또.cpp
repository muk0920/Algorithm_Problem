#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std; 
int dp[12][11]; 
int N, M; 

int DFS(int cur, int cnt) {

	if (dp[cur][cnt] != 0)
		return dp[cur][cnt];

	if (cnt == N) {
		if (M >= cur) {
			dp[cur][cnt] = (M - cur + 1); 
		}
		else {
			dp[cur][cnt] = 0; 
		}
		return dp[cur][cnt]; 
	}

	if (cnt > N) return 0; 

	int temp = (M / pow(2, N - cnt - 1)); 
	for (int i = 2*cur; i <= temp; i++) {
		dp[i][cnt+1] = max(dp[i][cnt+1], DFS(i, cnt+1)); 
	}
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_2758.txt", "r", stdin); 
	int tc; 
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M; 


		for (int i = 1; i <= (M / pow(2, N - 1)); i++)
			dp[i][1] = max(dp[i][1], DFS(i, 1)); 

		cout << 1;
	}
}