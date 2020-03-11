#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue> 
#include <set>
using namespace std;
int N, M, coin;
char map[21][21];
pair<int, int> coin_pos1, coin_pos2;
struct cur { int r1, c1, r2, c2, cnt; };
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int bt_cnt[20][20][20][20];

int BFS() {
	queue<cur> q;
	int min_cnt = 987654321;
	q.push({ coin_pos1.first, coin_pos1.second, coin_pos2.first, coin_pos2.second, 0 });

	while (!q.empty()) {
		int cur_r1 = q.front().r1;
		int cur_c1 = q.front().c1;
		int cur_r2 = q.front().r2;
		int cur_c2 = q.front().c2;
		int cur_cnt = q.front().cnt;
		q.pop();

		if (cur_cnt >= 10)	continue;
		if (cur_cnt > min_cnt)	continue;

		for (int i = 0; i < 4; i++) {
			int rr1 = cur_r1 + dr[i];
			int cc1 = cur_c1 + dc[i];
			int rr2 = cur_r2 + dr[i];
			int cc2 = cur_c2 + dc[i];
			int out_cnt = 0;

			if (rr1 >= 0 && rr1 < N && cc1 >= 0 && cc1 < M) {
				if (map[rr1][cc1] == '#') {
					rr1 = cur_r1;
					cc1 = cur_c1;
				}
			}
			else {
				out_cnt++;
			}

			if (rr2 >= 0 && rr2 < N && cc2 >= 0 && cc2 < M) {
				if (map[rr2][cc2] == '#') {
					rr2 = cur_r2;
					cc2 = cur_c2;
				}
			}
			else {
				out_cnt++;
			}

			if (out_cnt == 0) {
				if (bt_cnt[rr1][cc1][rr2][cc2] > cur_cnt + 1) {
					bt_cnt[rr1][cc1][rr2][cc2] = cur_cnt + 1;
					q.push({ rr1,cc1,rr2,cc2,cur_cnt + 1 });
				}
			}
			else if (out_cnt == 1) {
				if (min_cnt > cur_cnt + 1)
					min_cnt = cur_cnt + 1;
			}
		}
	}
	if (min_cnt == 987654321)	return -1;
	else return min_cnt;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_16197.txt", "r", stdin); 
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			map[i][j] = input[j];
			if (map[i][j] == 'o') {
				if (coin == 0) { // 첫번째 동전 
					map[i][j] = '.';
					coin_pos1 = make_pair(i, j);
					coin++;
				}
				else { // 두번째 동전 
					map[i][j] = '.';
					coin_pos2 = make_pair(i, j);
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				for (int x = 0; x < M; x++) {
					bt_cnt[i][j][k][x] = 987654321;
				}
			}
		}
	}

	cout << BFS() << "\n";
}