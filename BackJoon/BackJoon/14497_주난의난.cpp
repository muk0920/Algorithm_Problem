#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
using namespace std; 
int N, M;
char map[301][301]; 
int dp[301][301]; 

int start_r, start_c, end_r, end_c; 
int dr[4] = { -1,0,1,0 }; 
int dc[4] = { 0,1,0,-1 }; 
struct pos { int r, c, dist; };

int BFS() {
	queue<pos> q;
	int ans = 987654321; 
	q.push({ start_r, start_c, 0 });  
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = 987654321; 
		}
	}
	dp[start_r][start_c] = 0; 

	while (!q.empty()) {
		int cur_r = q.front().r;
		int cur_c = q.front().c;
		int cur_dist = q.front().dist;
		q.pop();

		if (cur_r == end_r && cur_c == end_c) {
			if (ans > cur_dist)
				ans = cur_dist;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int rr = cur_r + dr[i]; 
			int cc = cur_c + dc[i]; 

			if (rr > 0 && rr <= N && cc > 0 && cc <= M) {
				if (map[rr][cc] == '0' && dp[rr][cc] > cur_dist) {
					dp[rr][cc] = cur_dist; 
					q.push({ rr,cc,cur_dist }); 
				}else if(map[rr][cc] == '1' && dp[rr][cc] > cur_dist + 1){
					dp[rr][cc] = cur_dist + 1; 
					q.push({ rr,cc,cur_dist + 1 }); 
				}
			}
		}
	}

	return ans; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_14497.txt", "r", stdin); 
	cin >> N >> M; 
	cin >> start_r >> start_c >> end_r >> end_c; 
	for (int i = 1; i <= N; i++) {
		string input; 
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			map[i][j+1] = input[j];
			if (map[i][j + 1] == '#')	map[i][j + 1] = '1'; 
		}
	}

	cout << BFS()<<"\n"; 
}