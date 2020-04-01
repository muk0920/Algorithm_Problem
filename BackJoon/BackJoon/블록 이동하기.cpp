#include <string>
#include <vector>
#include <queue> 
#include <set> 
#include <iostream>

using namespace std;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int rot_r[4] = { -1,-1,1,1 }; 
int rot_c[4] = { -1,1,1,-1 }; 

int visited[101][101][4];
struct robot { int r, c, dir; };
int N;

bool isRange(int r,int c){
	return (r >= 0 && r < N && c >= 0 && c < N); 
}

bool isOk(int r, int c, int dir, int m_dir, vector<vector<int>> &board) {
	int move_dir = m_dir == 0 ? 3 : 1; // 시계 방향일 경우 3, 반 시계일 경우 1
	int rr, cc;
	if (dir == 0 || dir == 2) { // 세로방향 
		rr = r + dr[dir];
		cc = c + dc[(dir + move_dir) % 4];
	}
	else {
		rr = r + dr[(dir + move_dir) % 4];
		cc = c + dc[dir];
	}

	if (rr >= 0 && rr<N && cc >= 0 && cc<N) {
		if (board[rr][cc] == 0)    return true;
		return false;
	}
	return false;
}

int BFS(vector<vector<int>> &board) {
	queue<robot> q;
	int time = 0;
	q.push({ 0,0,1 }), q.push({ 0,1,3 }); 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				visited[i][j][k] = 987654321; 
			}
		}
	}
	visited[0][0][1] = 0, visited[0][1][3] = 0; 

	while (!q.empty()) {
		time++;
		int size = q.size(); 

		for (int t = 0; t < size; t++) {
			int one_r = q.front().r;
			int one_c = q.front().c;
			int cur_dir = q.front().dir; // 현재 로봇이 놓인 방향 ( 기준점을 기준으로 )
			int other_r = one_r + dr[cur_dir];
			int other_c = one_c + dc[cur_dir];
			q.pop();

			if ((one_r == N - 1 && one_c == N - 1) || (other_r == N - 1 && other_c == N - 1)) {
				return time-1; 
			}

			// 이동 
			for (int i = 0; i < 4; i++) {
				int one_rr = one_r + dr[i];
				int one_cc = one_c + dc[i];
				int other_rr = other_r + dr[i];
				int other_cc = other_c + dc[i];

				if (isRange(one_rr, one_cc) && isRange(other_rr, other_cc)) { // 범위 안에 있을 경우
					if(board[one_rr][one_cc] == 0 && board[other_rr][other_cc] == 0){
						if (visited[one_rr][one_cc][cur_dir] > time) {
							visited[one_rr][one_cc][cur_dir] = time;
							q.push({ one_rr, one_cc, cur_dir });
						}
					}
				}
			}
			// 반시계 회전
			int check_r = one_r + dr[(cur_dir + 3) % 4]; 
			int check_c = one_c + dc[(cur_dir + 3) % 4]; 
			int next_r = other_r + dr[(cur_dir + 3) % 4]; // 회전할 좌표 
			int next_c = other_c + dc[(cur_dir + 3) % 4];

			if (isRange(check_r, check_c) && isRange(next_r, next_c)) {
				if (board[check_r][check_c] == 0 && board[next_r][next_c] == 0) { 
					if (visited[one_r][one_c][(cur_dir + 3) % 4] > time) {
						visited[one_r][one_c][(cur_dir + 3) % 4] = time; 
						q.push({ one_r,one_c, (cur_dir + 3) % 4 }); 
						q.push({ next_r,next_c,(cur_dir + 1) % 4 }); 
					}
				}
			}

			// 시계 회전 
			check_r = one_r + dr[(cur_dir + 1) % 4];
			check_c = one_c + dc[(cur_dir + 1) % 4];
			next_r = other_r + dr[(cur_dir + 1) % 4]; // 회전할 좌표 
			next_c = other_c + dc[(cur_dir + 1) % 4];

			if (isRange(check_r, check_c) && isRange(next_r, next_c)) {
				if (board[check_r][check_c] == 0 && board[next_r][next_c] == 0) {
					if (visited[one_r][one_c][(cur_dir + 1) % 4] > time) {
						visited[one_r][one_c][(cur_dir + 1) % 4] = time;
						q.push({ one_r,one_c, (cur_dir + 1) % 4 });
						q.push({ next_r,next_c,(cur_dir + 3) % 4 }); 
					}
				}
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	N = board.size();

	answer = BFS(board);
	return answer;
}

int main() {
	vector<vector<int>> board = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} }; 

	cout<<solution(board); 
}