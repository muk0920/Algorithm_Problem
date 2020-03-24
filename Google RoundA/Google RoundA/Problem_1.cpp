#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
int N, B; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_1.txt", "r", stdin); 
	int tc; 
	cin >> tc; 
	for (int t = 1; t <= tc; t++) {
		cin >> N >> B; 
		vector<int> house(N,0);  
		int count = 0, sum = 0;

		for (int i = 0; i < N; i++) {
			cin >> house[i]; 
		}

		sort(house.begin(), house.end()); 
		for (int i = 0; i < house.size(); i++) {
			if (sum + house[i] <= B) {
				sum += house[i];
				count++; 
			}
			else
				break; 
		}
		cout << "Case #" << t << ": "<<count<<"\n"; 
	}
}