#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std; 
int N, M, ans=987654321;
int all_cnt = 0; 

int map[50][50]; 
//int laboratory[50][50]; 
int dr[4] = { -1,0,1,0 }; 
int dc[4] = { 0,1,0,-1 }; 

bool visited[11]; 
vector<pair<int, int>> start_virus; 
vector<pair<int, int>> able_virus; 

void Make_Virus(int idx, int cnt) {

	if (cnt == M) { // 바이러스 조건 만족 시 
		int temp[50][50] = { 0, }; 
		bool checked[50][50] = { false, }; 
		int time = 0;
		int temp_all_cnt = all_cnt; 
		for (int i = 0; i < N; i++) { // 맵 복사 
			for (int j = 0; j < N; j++) {
				temp[i][j] = map[i][j]; 
			}
		}
		
		queue<pair<int, int>> q; 
		for (int i = 0; i < start_virus.size(); i++) {
			q.push(start_virus[i]);
			temp[start_virus[i].first][start_virus[i].second] = 1; 
			checked[start_virus[i].first][start_virus[i].second] = true; 
		}

		while (!q.empty()) {
			int q_size = q.size(); 
			
			if (temp_all_cnt == 0)	break; 

			for (int i = 0; i < q_size; i++) {
				int cur_r = q.front().first;
				int cur_c = q.front().second;
				q.pop();
			
				for (int k = 0; k < 4; k++) {
					int rr = cur_r + dr[k]; 
					int cc = cur_c + dc[k]; 

					if (rr >= 0 && rr < N && cc >= 0 && cc < N) {
						if (temp[rr][cc] == 0 && !checked[rr][cc]) {
							checked[rr][cc] = true; 
							temp[rr][cc] = 1; 
							q.push({ rr,cc }); 
							temp_all_cnt--;
						}
					}
				}
			}
			time++;
		}
		
		if (ans > time && temp_all_cnt==0)	ans = time; 
		return; 
	}

	for (int i = idx; i < able_virus.size(); i++) {
		if (!visited[i]) {
			visited[i] = true; 
			start_virus.push_back(able_virus[i]); 
			//pair<int,int> pos = able_virus[i]; 
			//map[pos.first][pos.second] = -1; // 바이러스 근원지 
			Make_Virus(i, cnt + 1); 
			start_virus.pop_back(); 
			//map[pos.first][pos.second] = 0; 
			visited[i] = false; 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_17141.txt", "r", stdin);
	cin >> N >> M;
	all_cnt = N*N; 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input; 
			cin >> input;
			//cin >> map[i][j];

			//if (map[i][j] == 2) {
			if(input==2){
				able_virus.push_back(make_pair(i, j)); 
			}
			else if (input == 1) {
				map[i][j] = -2; // 벽 설치  
				all_cnt--; 
			}
		}
	}

	all_cnt -= M; 

	Make_Virus(0, 0); 

	if (ans == 987654321)	cout << "-1\n"; 
	else cout << ans << "\n";
}