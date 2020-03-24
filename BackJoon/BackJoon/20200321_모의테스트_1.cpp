#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std; 
int N, M, K, R, C, ans; 
int notebook[40][40]; 

bool isChecked(int r, int c, vector<vector<int>> &vec) {
	
	if (r + vec.size() > N || c + vec[0].size() > M)	return false; 

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[0].size(); j++) {
			if (vec[i][j] + notebook[r+i][c+j] == 2) { // 스티커 부분일때 
					return false;
			}
		}
	}
	return true; 
}

void Attach(int r, int c, vector<vector<int>> &vec) {
	int st_cnt = 0; 

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[0].size(); j++) {	
			if (vec[i][j] == 1) {
				st_cnt++; 
				notebook[r + i][c + j] = 1; // 스티커 붙이기 
			}
		}
	}
	ans += st_cnt; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_1.txt", "r", stdin); 
	cin >> N >> M >> K; 
	for (int st = 0; st < K; st++) {
		cin >> R >> C; 
		vector<vector<int>> sticker(R, vector<int> (C, 0)); 

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> sticker[i][j]; 
			}
		}
		int rot_cnt = 0; 

		while (true) {
			bool attach_flag = false; // 스티커 붙일 수 있는지 여부 확인 
			int start_r=0, start_c=0; 
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (attach_flag) break; // 붙일 수 있으면 탈출 
					if (isChecked(i, j, sticker)) {
						attach_flag = true; 
						start_r = i, start_c = j; 
					}
				}
				if (attach_flag) break; // 붙일 수 있으면 탈출 
			}

			if (attach_flag) { // 스티커 붙일 수 있을 경우 
				// 스티커 붙은 개수 확인하며 맵에 스티커 붙이기 
				Attach(start_r, start_c, sticker);
				break; 
			}
			else { // 못붙일 경우 90도 시계방향 회전 
				// 0 , 90, 180, 270 다 해봐도 안되는 경우 
				if (rot_cnt == 3)	break;

				// 회전
				int temp_r = sticker[0].size();  // 회전하면 직사각형의 크기 달라진다. 
				int temp_c = sticker.size(); 

				vector<vector<int>> temp(temp_r, vector<int>(temp_c, 0));
				for (int i = sticker.size() - 1; i >= 0; i--) {
					for (int j = 0; j < sticker[0].size(); j++) {
						temp[j][sticker.size() - 1 - i] = sticker[i][j]; 
					}
				}
				sticker = temp; 

				// 회전 카운트 증가 
				rot_cnt++; 
			}
		}
	}
	cout << ans << "\n";
}

// 사용시간 40분 
