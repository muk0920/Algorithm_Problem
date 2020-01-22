#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int N, C; 
int answer = 0; 
vector<int> home;

int Find_Center() {

}

int Find_Pos(int st, int md, int ed) {
	
	if (st < ed) {
		// 왼쪽 
		int dist = Find_Centor(st, md - 1);
		// 오른쪽 
		dist = min(dist, Find_Centor(md, ed));
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		home.push_back(input);
	}
	sort(home.begin(), home.end()); // 정렬 

	Find_Pos(home[0], (home[0]+home[N-1])/2, home[N - 1]);
}