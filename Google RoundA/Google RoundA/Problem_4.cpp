#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int N, K;

map<string, int> st_map; 

void Search(string comp, int idx, vector<string> vec) {

	vector<string> alpha[26]; 

	for (int i = 0; i < vec.size(); i++) {
		if (idx >= vec[i].size())	continue; 

		alpha[vec[i][idx] - 'A'].push_back(vec[i]); 
	}
	
	for (int i = 0; i < 26; i++) {
		if (alpha[i].size() >= K) {
			comp = comp + alpha[i][0][idx];
			if (st_map.find(comp) == st_map.end()) {
				st_map[comp] = alpha[i].size(); 
				Search(comp, idx + 1, alpha[i]); 
			}
			comp.pop_back(); 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_4.txt", "r", stdin); 
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> K;
		vector<string> pip;
		int ans = 0;

		for (int i = 0; i < N; i++) {
			string input;
			cin >> input;
			pip.push_back(input);
		}

		Search("", 0, pip); 
		
		map<string, int>::iterator it; 
		for (it = st_map.begin(); it != st_map.end(); it++) {
			ans += (it->second) / K; 
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}
}