#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_a.txt", "r", stdin); 
	string input; 
	int N, K, ans =0; 
	cin>>N>>K>>input; 
	for (int i = 0; i <= N - K; i++) {
		if (ans < atoi(input.substr(i, K).c_str())) {
			ans = atoi(input.substr(i, K).c_str()); 
		}
	}
	cout << ans << "\n";
}