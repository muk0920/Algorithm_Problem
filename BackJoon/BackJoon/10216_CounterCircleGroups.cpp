#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;
int T, N;
struct Tower { int r, c, R; };
vector<Tower> tower_list;
int graph[3001][3001];
bool visited[3001];

void DFS(int idx) {

	for (int i = 0; i < N; i++) {
		if (graph[idx][i] == 1 && !visited[i]) {
			visited[i] = true;
			DFS(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_10216.txt", "r", stdin); 

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		tower_list = vector<Tower>(N, { 0,0,0 });
		for (int i = 0; i < N; i++) {
			cin >> tower_list[i].c >> tower_list[i].r >> tower_list[i].R;
		}

		for (int i = 0; i < N - 1; i++) {
			int cur_r = tower_list[i].r;
			int cur_c = tower_list[i].c;
			int cur_dist = tower_list[i].R;

			for (int j = i + 1; j < N; j++) {
				int other_r = tower_list[j].r;
				int other_c = tower_list[j].c;
				int other_dist = tower_list[j].R;

				int x = abs(cur_r - other_r);
				int y = abs(cur_c - other_c);
				int d = cur_dist + other_dist;

				if (x*x + y*y <= d*d) {
					graph[i][j] = 1;
					graph[j][i] = 1;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				DFS(i);
				cnt++;
			}
		}
		memset(visited, false, sizeof(visited));
		memset(graph, 0, sizeof(graph)); 
		cout << cnt << "\n";
	}
}