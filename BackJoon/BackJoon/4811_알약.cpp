#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std; 
int N; 
long long dp[31][31]; 
long long Eat_Pill(int w, int h) {

	if (w == 0 && h == 0)	return 1;

	if (dp[w][h] != 0) return dp[w][h];

	if (w == 0) return dp[w][h] = 1;
	
	if (h == 0)  return dp[w][h] = Eat_Pill(w - 1, 1) ;

	return dp[w][h] = Eat_Pill(w - 1, h + 1) + Eat_Pill(w, h - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("4811.txt", "r", stdin);

	int tc;

	
	
	for (long long i = 1; i <= 30; i++) {
		Eat_Pill(i, 0);
	}

	while (true) {
		cin >> N; 
		if (N == 0)	break; 
		cout << dp[N][0] << "\n";
	}
}