#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std; 
int N, M, all_cheese,remain_cheese, time; 
int map[100][100];
int dr[4] = { -1,0,1,0 }; 
int dc[4] = { 0,1,0,-1 }; 

vector<pair<int, int>> melt_cheese;

bool Check_Air(int r, int c) {
	int rr, cc; 
	for (int i = 0; i < 4; i++) {
		rr = r + dr[i];
		cc = c + dc[i]; 

		if (rr >= 0 && rr < N && cc >= 0 && cc < M) {
			if (map[rr][cc] == 2)	return false; 
		}
	}
	return true; 
}

void Spread_Air(int r, int c) {
	queue<pair<int, int>> q; 
	q.push({ r,c });
	map[r][c] = 2; 

	while (!q.empty()) {
		int cur_r = q.front().first;
		int cur_c = q.front().second; 
		q.pop(); 

		for (int i = 0; i < 4; i++) {
			int rr = cur_r + dr[i]; 
			int cc = cur_c + dc[i]; 

			if (rr >= 0 && rr < N && cc >= 0 && cc < M) {
				if (map[rr][cc] == 0) {
					map[rr][cc] = 2;
					q.push({ rr,cc });
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_2636.txt", "r", stdin);
	cin >> N >> M; 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j]; 
			if (map[i][j] == 1)	all_cheese++;
		}
	}

	// 외부 공기 확산 
	for (int i = 0; i < N; i++) if (map[i][0] == 0)	Spread_Air(i, 0);
	for (int i = 0; i < M; i++) if (map[0][i] == 0)	Spread_Air(0, i);
	for (int i = 0; i < N; i++) if (map[i][M - 1] == 0)	Spread_Air(i, M - 1);
	for (int i = 0; i < M; i++) if (map[N - 1][i] == 0)	Spread_Air(N - 1, i);

	while (true) {
		
		if (all_cheese == 0)	break; 
		remain_cheese = all_cheese;

		// 공기 확산 
		bool air_flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 2) {
					Spread_Air(i,j);
				}
			}
		}

		// 녹는 치즈 찾기 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 2)	continue;
				if (!Check_Air(i, j)) { // 공기중에 닿은 치즈 일 경우 
					melt_cheese.push_back(make_pair(i, j));
				}
			}
		}

		// 치즈 녹기 
		for (int i = 0; i < melt_cheese.size(); i++) {
			int rr = melt_cheese[i].first;
			int cc = melt_cheese[i].second;
			map[rr][cc] = 0; 
			all_cheese--; 
		}

		// 초기화
		melt_cheese.clear(); 
		time++; 
	}

	cout << time<<"\n"<< remain_cheese << "\n";
}