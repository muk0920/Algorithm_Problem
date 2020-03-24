#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
int N, K, P; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_2.txt", "r", stdin);
	int tc; 
	cin >> tc; 
	for (int t = 1; t <= tc; t++) {
		cin >> N >> K >> P; 
		vector<vector<int>> vec(K, vector<int>(N, 0)); 
		vector<vector<int>> dp(K, vector<int>(N, 0)); 
		vector<pair<int,int>> max_vec[31];

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < K; i++) {
				cin >> vec[i][j]; 
			}
		}

		for (int i = 0; i < N; i++)	{
			dp[0][i] = vec[0][i]; 
			max_vec[0].push_back({ dp[0][i], i });
			}

		for (int i = 1; i < K; i++) { // 행 높이 천천히 올라가기 


		}
		

		cout << "!"; 
	}
	
}