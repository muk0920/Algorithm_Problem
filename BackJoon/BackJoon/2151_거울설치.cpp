#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N, door_cnt = 0; 
int door_r1, door_c1, door_r2, door_c2;
char map[50][50]; 
int mir_cnt[50][50][4]; 
int dr[4] = { -1,0,1,0 }; 
int dc[4] = { 0,1,0,-1 }; 

struct Light {
	int r, c, cnt, dir; 
};

int BFS() {
	queue<Light> q; 
	int min_cnt = 987654321; 
	for(int i=0; i<4; i++)
		q.push({ door_r1, door_c1, 0, i });  // 4방향 다 넣기 

	while (!q.empty()) {
		int cur_r = q.front().r; 
		int cur_c = q.front().c; 
		int cur_cnt = q.front().cnt; 
		int cur_dir = q.front().dir; 
		q.pop(); 

		if (min_cnt <= cur_cnt)	continue; 

		int rr = cur_r, cc = cur_c; 

		while (true) {
			rr = rr + dr[cur_dir]; 
			cc = cc + dc[cur_dir]; 

			if (rr >= 0 && rr < N && cc >= 0 && cc < N) {
				if (map[rr][cc] == '*') {
					break; 
				}
				else if (map[rr][cc] == '.') {
					continue;
				}
				else if (map[rr][cc] == '!') {
					if (cur_cnt+1 < mir_cnt[rr][cc][cur_dir]) { // 최소 거울 설치 횟수가 아닐경우 패스 
						mir_cnt[rr][cc][cur_dir] = cur_cnt+1;
						if (cur_dir == 0 || cur_dir == 2) { 
							q.push({ rr,cc,cur_cnt + 1, 1 });
							q.push({ rr,cc,cur_cnt + 1, 3 });
						}
						else if (cur_dir == 1 || cur_dir == 3) {
							q.push({ rr,cc,cur_cnt + 1, 0 });
							q.push({ rr,cc,cur_cnt + 1, 2 });
						}
						q.push({ rr,cc,cur_cnt,cur_dir }); // 거울 설치 없이 그냥 지나갈경우 
					}
					break;
				}
				else if(map[rr][cc] == '#'){
					if (rr == door_r2 && cc == door_c2) {
						if (min_cnt > cur_cnt)
							min_cnt = cur_cnt;
						break;
					}
				}
				else
					break;
			}
			else
				break;
		}
	}
	return min_cnt;
}

int main(){
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_2151.txt", "r", stdin);
	cin >> N; 
	string input; 
	for (int i = 0; i < N; i++) {
		cin >> input; 
		for (int j = 0; j < input.size(); j++) {
			map[i][j] = input[j];
			if (map[i][j] == '#' && door_cnt == 0) { // 첫번째 문 일 경우
				door_r1 = i, door_c1 = j; 
				door_cnt++; 
			}
			else if (map[i][j] == '#') {
				door_r2 = i, door_c2 = j;
			}
		}
	}
	
	// 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++)	mir_cnt[i][j][k] = 987654321; 
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				for (int x = 0; x < M; x++) {

				}
			}
		}
	}
	cout<<BFS()<<"\n"; 
}