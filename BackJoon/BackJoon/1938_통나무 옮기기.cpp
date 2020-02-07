#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
int dr[4] = { -1,0,1,0 }; // 상.우.하.좌
int dc[4] = { 0,1,0,-1 };
int N;
char map[50][50];
bool visited[50][50][2];

bool Able_Rot(int r, int c) {
	if (r >= 1 && r < N - 1 && c >= 1 && c < N - 1) {
		for (int i = r - 1; i <= r + 1; i++) {
			for (int j = c - 1; j <= c + 1; j++) {
				if (map[i][j] == '1')	return false; // 빈 공간 x 
			}
		}
		return true;
	}
	return false; // 애당초 회전 불가. 
}

bool Able_Move(int r, int c, int dir) {
	if (dir == 0) { // 가로방향
		if (map[r][c - 1] != '1' && map[r][c + 1] != '1' && map[r][c] != '1')	return true;
		else return false;
	}
	else { // 세로방향
		if (map[r - 1][c] != '1' && map[r + 1][c] != '1' && map[r][c] != '1')	return true;
		else return false;
	}
}

int BFS(pair<int,int> b_mid, pair<int,int> e_mid, int b_dir, int e_dir) {
	queue<pair<pair<int, int>, pair<int,int>>> q; 
	int min_cnt = 987654321; 
	q.push({ b_mid, {b_dir,0} });
	visited[b_mid.first][b_mid.second][b_dir] = true; 

	while (!q.empty()) {
		int cur_r= q.front().first.first;
		int cur_c = q.front().first.second;
		int cur_dir = q.front().second.first;
		int cur_cnt = q.front().second.second;
		q.pop();

		if (cur_r == e_mid.first && cur_c == e_mid.second && cur_dir == e_dir) { // 목적지 도착 시 . 
			if (cur_cnt < min_cnt)
				min_cnt = cur_cnt; 
			continue; 
		}

		for (int i = 0; i < 4; i++) {
			int rr = cur_r + dr[i]; 
			int cc = cur_c + dc[i];

			if(cur_dir == 0){ // 현재 가로방향일 경우.
				if (rr >= 0 && rr < N && cc >= 1 && cc < N-1) { // 범위 내에 존재 시 
					if (!visited[rr][cc][cur_dir] ) {
						visited[rr][cc][cur_dir] = true;
						if (Able_Move(rr, cc, cur_dir)) {
							q.push({ {rr,cc}, {cur_dir, cur_cnt + 1} });
						}
					}
				}
			}
			else { // 현재 세로방향일 경우. 
				if (rr >= 1 && rr < N - 1 && cc >= 0 && cc < N) { // 범위 내 존재 시 
					if (!visited[rr][cc][cur_dir]) {
						visited[rr][cc][cur_dir] = true;
						if (Able_Move(rr, cc, cur_dir)) {
							q.push({ { rr,cc }, {cur_dir, cur_cnt + 1} });
						}
					}
				}
			}
		}

		if (Able_Rot(cur_r, cur_c)) { // 회전이 가능하다면. 
			int next_dir = -1; 
			if (cur_dir == 0)	next_dir = 1; 
			else	next_dir = 0; 

			if (!visited[cur_r][cur_c][next_dir]) {
				visited[cur_r][cur_c][next_dir] = true; 
				q.push({ {cur_r,cur_c}, {next_dir, cur_cnt + 1} });
			}
		}
	}

	if (min_cnt == 987654321)	min_cnt = 0;

	return min_cnt; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string input;
	cin >> N; 
	int b_cnt = 0, e_cnt = 0;
	pair<int, int> b_mid, e_mid; 
	int b_dir = -1, e_dir = -1; // dir - 0 가로.  dir - 1 세로 

	for (int i = 0; i < N; i++) {
		cin >> input; 
		for (int j = 0; j < input.size(); j++) {
			map[i][j] = input[j];
			if (map[i][j] == 'B') {
				b_cnt++;
				if (b_cnt == 2) { 
					b_mid = make_pair(i, j);
					if (j - 1 >= 0) {
						if (map[i][j - 1] == 'B')	b_dir = 0; // 가로방향 
					}
					if (i - 1 >= 0) {
						if (map[i - 1][j] == 'B')	b_dir = 1; // 세로방향
					}
				}
			}
			else if (map[i][j] == 'E') {
				e_cnt++;
				if (e_cnt == 2) {
					e_mid = make_pair(i, j);
					if (j - 1 >= 0) {
						if (map[i][j - 1] == 'E')	e_dir = 0; // 가로방향
					}
					if (i - 1 >= 0) {
						if (map[i - 1][j] == 'E')	e_dir = 1; // 세로방향
					}
				}
			}
		}
	}
	cout << BFS(b_mid, e_mid, b_dir, e_dir)<<"\n";
}