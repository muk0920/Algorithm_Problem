// (0,0) ����. 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std; 

vector<pair<int, int>> Point; 

// ��. ��. �� .��
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

	for (int i = 0; i < N; i++) { // ������ ǥ�� 
		int a, b;
		cin >> a >> b; 	
	}

	for (int i = 0; i < M; i++) { // �κ� �ùķ��̼� 
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