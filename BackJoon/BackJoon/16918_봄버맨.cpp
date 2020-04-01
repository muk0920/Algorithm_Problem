#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std; 
int map[200][200]; 
int R, C, T; 
int dr[4] = { -1,0,1,0 }; 
int dc[4] = { 0,1,0,-1 }; 

void Next_Time() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1) { // ÆøÅºÀÌ ¼³Ä¡µÈ °÷ 
				map[i][j]++;
			}
		}
	}
}

void Bomb() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 3) {
				map[i][j] = -1; 
				for (int k = 0; k < 4; k++) {
					int rr = i + dr[k]; 
					int cc = j + dc[k]; 
					if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
						if(map[rr][cc] != 3)
							map[rr][cc] = -1;
					}
				}
			}
		}
	}
}

void Install_Bomb() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1)	map[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_16918.txt", "r", stdin);
	cin >> R >> C >> T; 
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char input; 
			cin >> input; 
			if (input == '.')	map[i][j] = -1; 
			else map[i][j] = 0; 
		}
	}

	for (int t = 1; t <= T; t++) {
		
		// ½Ã°£ °æ°ú  
		Next_Time();
		
		if (t % 2 == 0) { // ÆøÅº ¼³Ä¡ 
			Install_Bomb(); 
		}

		// ÆøÅº ÆøÆÄ
		Bomb(); 
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1) cout << "."; 
			else cout << "O"; 
		}
		cout << "\n";
	}
}