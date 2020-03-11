#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_1365.txt", "r", stdin);
	int N;
	int prev, cnt=0, ans=0; 
	cin >> N; 
	vector<int> line(N, 0);
	vector<int> lis; 

	for (int i = 0; i < N; i++)
		cin >> line[i]; 

	lis.push_back(line[0]); 

	for (int i = 1; i < line.size(); i++) {
		if (lis.back() < line[i])
			lis.push_back(line[i]); 
		else {
			vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), line[i]);
			(*it) = line[i]; 
		}
	}

	cout << N - lis.size() <<"\n"; 

	
}