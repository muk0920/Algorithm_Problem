#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>

using namespace std; 
bool number[9][9][10]; 
vector<bool> visited; 
int map[9][9]; 
deque<pair<int, int>> blank; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	freopen("input_2580.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j]; 
			if (map[i][j] == 0) {
				blank.push_back({ i,j }); 
			}
		}
	}

	visited = vector<bool>(blank.size(), false); 
	
	for (int x = 0; x < blank.size(); x++) {
		if (!visited[x]) { // 빈칸이 안채워진 경우에만 
			int cur_r = blank[x].first; 
			int cur_c = blank[x].second; 

			// 해당 칸의 가로줄 검사 
			for (int i = 0; i < 9; i++) {
				if (cur_c == i)	continue;
				int num = map[cur_r][i];
				number[cur_r][cur_c][num] = true;
			}
			// 해당 칸의 세로줄 검사 
			for (int i = 0; i < 9; i++) {
				if (cur_r == i)	continue;
				int num = map[i][cur_c];
				number[cur_r][cur_c][num] = true;
			}
			// 해당 칸의 네모 검사 
			int start_r, start_c;
			if (cur_r < 3)	start_r = 0;
			else if (cur_r < 6)	start_r = 3;
			else start_r = 6;
			if (cur_c < 3)	start_c = 0;
			else if (cur_c < 6)	start_c = 3;
			else start_c = 6;

			for (int i = start_r; i <= start_r + 2; i++) {
				for (int j = start_c; j <= start_c + 2; j++) {
					if (cur_r == i && cur_c == i)	continue;
					int num = map[i][j];
					number[cur_r][cur_c][num] = true;
				}
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " "; 
		}
		cout << "\n";
	}
}