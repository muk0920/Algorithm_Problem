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
			if (vec[i][j] + notebook[r+i][c+j] == 2) { // ��ƼĿ �κ��϶� 
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
				notebook[r + i][c + j] = 1; // ��ƼĿ ���̱� 
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
			bool attach_flag = false; // ��ƼĿ ���� �� �ִ��� ���� Ȯ�� 
			int start_r=0, start_c=0; 
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (attach_flag) break; // ���� �� ������ Ż�� 
					if (isChecked(i, j, sticker)) {
						attach_flag = true; 
						start_r = i, start_c = j; 
					}
				}
				if (attach_flag) break; // ���� �� ������ Ż�� 
			}

			if (attach_flag) { // ��ƼĿ ���� �� ���� ��� 
				// ��ƼĿ ���� ���� Ȯ���ϸ� �ʿ� ��ƼĿ ���̱� 
				Attach(start_r, start_c, sticker);
				break; 
			}
			else { // ������ ��� 90�� �ð���� ȸ�� 
				// 0 , 90, 180, 270 �� �غ��� �ȵǴ� ��� 
				if (rot_cnt == 3)	break;

				// ȸ��
				int temp_r = sticker[0].size();  // ȸ���ϸ� ���簢���� ũ�� �޶�����. 
				int temp_c = sticker.size(); 

				vector<vector<int>> temp(temp_r, vector<int>(temp_c, 0));
				for (int i = sticker.size() - 1; i >= 0; i--) {
					for (int j = 0; j < sticker[0].size(); j++) {
						temp[j][sticker.size() - 1 - i] = sticker[i][j]; 
					}
				}
				sticker = temp; 

				// ȸ�� ī��Ʈ ���� 
				rot_cnt++; 
			}
		}
	}
	cout << ans << "\n";
}

// ���ð� 40�� 
