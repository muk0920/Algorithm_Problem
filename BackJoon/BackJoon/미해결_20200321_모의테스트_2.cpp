// �ð��ʰ� �ڵ��Դϴ�.. �Ƹ� DFS �� ���� ����� �������� ��ġ�� �κ� �� ���ؼ� �׷��� ���ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int N, M, G, R, ans; 
int map[50][50]; 
vector<pair<int, int>> ground_pos; 
vector<pair<int, int>> green_pos; 
vector<pair<int, int>> red_pos; 

bool visited[10]; // ������ �Ѹ� �� �ִ� ���� �ִ� 10�� 
struct Liquid {
	int r, c, type; 
};

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 }; 

void BFS() {
	int flower_cnt = 0;
	int time = 0;
	queue<Liquid> q;
	bool checked[50][50] = { false, }; // ���� �ѷ����� üũ 
	bool time_checked[50][50][51][2] = { false, };

	for (int i = 0; i < green_pos.size(); i++) { // ���� �Ѹ��� 
		q.push({ green_pos[i].first, green_pos[i].second, 0 }); // �ʷϻ� 0 
		checked[green_pos[i].first][green_pos[i].second] = true;
		time_checked[green_pos[i].first][green_pos[i].second][0][0] = true;
	}

	for (int i = 0; i < red_pos.size(); i++) { // ���� �Ѹ��� 
		q.push({ red_pos[i].first, red_pos[i].second, 1 }); // ������ 1
		checked[red_pos[i].first][red_pos[i].second] = true;
		time_checked[red_pos[i].first][red_pos[i].second][0][1] = true;
	}

	while (!q.empty()) {
		int size = q.size();
		time++;  // �ð��� �帥�� .
		vector<pair<int, int>> temp;

		for (int t = 0; t < size; t++) { // ������ �ð��� 
			int cur_r = q.front().r;
			int cur_c = q.front().c;
			int cur_type = q.front().type;
			q.pop();

			if (time_checked[cur_r][cur_c][time - 1][0] && time_checked[cur_r][cur_c][time - 1][1])	continue;

			for (int i = 0; i < 4; i++) {
				int rr = cur_r + dr[i];
				int cc = cur_c + dc[i];

				if (rr >= 0 && rr < N && cc >= 0 && cc < M) { // ���� �ȿ� ���� ��� 
					if (!checked[rr][cc] && map[rr][cc] != 0) { // ������ �̹� �����ϴ� ���� �ƴѰ�� && ȣ���� �ƴѰ�� 
						if (!time_checked[rr][cc][time][cur_type]) {
							time_checked[rr][cc][time][cur_type] = true;
							temp.push_back({ rr,cc }); 
							if ( (cur_type == 0 && time_checked[rr][cc][time][1]) || (cur_type == 1 && time_checked[rr][cc][time][0])) { // ���� �Ǵ°�� 
								flower_cnt++;
								continue;
							}
							q.push({ rr,cc, cur_type });
						}
					}
				}
			}
		}
		for (int i = 0; i < temp.size(); i++)
			checked[temp[i].first][temp[i].second] = true; 
	}

	if (ans < flower_cnt)
		ans = flower_cnt;

	return;
}

void Plant(int idx, int cnt, int red, int green) {

	if (red == 0 && green == 0) { // ���� ��� �ɾ��� ��� 
		// BFS 
		BFS(); 
		return; 
	}
	
	if (cnt < (red + green))	return;
	if (idx >= ground_pos.size())	return;


	for (int i = idx; i < ground_pos.size(); i++) {
		if (!visited[i]) {
			visited[i] = true; 
			Plant(i + 1, cnt-1, red, green);
			if (green > 0) {
				green_pos.push_back(ground_pos[i]); 
				Plant(i + 1, cnt-1, red, green - 1);
				green_pos.pop_back(); 
			}
			if (red > 0) {
				red_pos.push_back(ground_pos[i]);
				Plant(i + 1, cnt - 1, red - 1, green);
				red_pos.pop_back();
			}
			visited[i] = false; 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_2.txt", "r", stdin);
	cin >> N >> M >> G >> R; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)	ground_pos.push_back(make_pair(i, j)); 
		}
	}

	Plant(0,ground_pos.size(), R,G); 

	cout << ans << "\n";
}