#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
#define endl "\n"
#define MAX 1000
using namespace std;
int t;
int w, h;
int result; // 정답
bool visit[MAX][MAX];
char map[MAX][MAX];
deque<pair<int, int>>sang;// 상근이의 위치
queue<pair<int, int>>fire;// 불의 위치
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void bfs() {
	while (!sang.empty()) {
		// 불 확산, 위치 저장
		bool is_move = false;
		int fire_size = fire.size();
		for (int i = 0; i < fire_size; i++) {
			int fire_y = fire.front().first;
			int fire_x = fire.front().second;
			fire.pop();
			for (int k = 0; k < 4; k++) {
				int fire_ny = fire_y + dy[k];
				int fire_nx = fire_x + dx[k];
				if (0 > fire_ny || fire_ny >= h || 0 > fire_nx || fire_nx >= w) continue;
				if (map[fire_ny][fire_nx] != '#' && map[fire_ny][fire_nx] != '*') { // 벽이 아니라면 불이 붙는다
					map[fire_ny][fire_nx] = '*';
					fire.push({ fire_ny,fire_nx }); // 새롭게 확산된 불의 위치 저장
				}
			}
		}
		// 상근이 이동, 위치 저장
		int sang_size = sang.size();
		for (int i = 0; i < sang_size; i++) {
			int y = sang.front().first;
			int x = sang.front().second;
			visit[y][x] = true;
			sang.pop_front();
			if (y == 0 || y == h - 1 || x == 0 || x == w - 1) {
				cout << result + 1 << endl;
				return;
			}
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 > ny || ny >= h || 0 > nx || nx >= w) continue; // 진행방향이 범위 초과
				if (map[ny][nx] == '#' || map[ny][nx] == '*' || visit[ny][nx] == true) continue; // 진행방향이 벽, 불, 방문했던 위치			
				map[ny][nx] = '@';
				visit[ny][nx] = true;
				sang.push_back({ ny,nx });
				is_move = true;
			}
		}
		result++;
		if (!is_move) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input_5427.txt", "r", stdin);
	cin >> t;
	while (t--) {
		result = 0;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < w; j++) {
				map[i][j] = str[j];
				if (str[j] == '@') {
					sang.push_back({ i,j });
				}
				else if (str[j] == '*') {
					fire.push({ i,j });
				}
			}
		}
		bfs();
		// 초기화
		while (!sang.empty())sang.pop_front();
		while (!fire.empty())fire.pop();
		memset(visit, false, sizeof(visit));
		memset(map, '#', sizeof(map));
	}
}