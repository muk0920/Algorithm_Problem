#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, M, K; 
int ans = 0;
int map[50][50]; 


void Search(int col, vector<int> &vec, int cnt) {
	
	if (cnt > K)	return; 
	if (col > M)	return; 
	if (vec.size() < ans)	return; 

	if (cnt == K && col == M) {
		if (ans < vec.size())
			ans = vec.size(); 
		return; 
	}

	vector<int> temp1, temp2;  

	// 해당 열 스위치 안누를 경우 
	for (int i = 0; i < vec.size(); i++) {
		if (map[vec[i]][col] == 1)	temp1.push_back(vec[i]);
	}
	Search(col + 1, temp1, cnt);
	// 해당 열 스위치 누를 경우 
	for (int i = 0; i < vec.size(); i++) {
		if (map[vec[i]][col] == 0)	temp2.push_back(vec[i]); 
	}
	Search(col + 1, temp2, cnt + 1); 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_1034.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			map[i][j] = input[j] - '0';
		}
	}
	cin >> K;

	vector<int> temp1, temp2;
	for (int i = 0; i < N; i++) {
		if (map[i][0] == 1)	temp1.push_back(i);
		else temp2.push_back(i);
	}

	if (M == 1) {
		if (K % 2 == 0)	ans = temp1.size();
		else ans = temp2.size();
	}
	else {
		Search(1, temp1, 0);
		Search(1, temp2, 1);
	}
	cout << ans << "\n";
}