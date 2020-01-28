// (0,0) 시작. 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std; 

vector<pair<int, int>> Point; 

// 상. 우. 하 .좌
int dy[4] = { -1,0,1,0 }; 
int dx[4] = { 0,1,0,-1 }; 
char dir[4] = { 'S','I','J','Z' };
int N, M; 
int cur_x, cur_y; 
int 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < N; i++) { // 조사점 표시 
		int a, b;
		cin >> a >> b; 	
	}

	for (int i = 0; i < M; i++) { // 로봇 시뮬레이션 
		char ch;
		int distance = 0; 
		cin >> ch; 
		for (int j = 0; j < 4; j++) {
			if (dir[j] == ch) {
				cur_x += dx[j]; 
				cur_y += dy[j]; 
				break; 
			}
		}
		
		for()
		cout << distance << "\n"; 

	}
}