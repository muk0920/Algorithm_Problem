#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std; 
int N; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_1943.txt", "r", stdin); 
	
	while (cin >> N) {
		vector<pair<int, int>> money(N, { 0,0 });
		int sum = 0; 

		for (int i = 0; i < N; i++) {
			cin >> money[i].first >> money[i].second;
			sum += (money[i].first * money[i].second);
		}

		cout << sum << "\n"; 
	}


}