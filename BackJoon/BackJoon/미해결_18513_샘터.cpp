#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>

using namespace std; 
int N, K, answer, dist=1; 
vector<int> water; 
set<int> home; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_18513.txt", "r", stdin);
	cin >> N >> K; 
	water = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> water[i];
		home.insert(water[i]);
	}
	
	while (true) {
		if (K == 0)	break; 

		for (int i = 0; i < N; i++) {
			if (home.find(water[i]-dist) == home.end()) { // ÁÂÃø
				K--; 
				home.insert(water[i]-dist);
				answer += dist; 
			}
			if (K == 0)break;
			
			if (home.find(water[i] + dist) == home.end()) { // ¿ìÃø 
				K--;
				home.insert(water[i] + dist);
				answer += dist; 
			}
		}
		dist++; 
	}

	cout << answer << "\n";
}