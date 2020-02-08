#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>

using namespace std;
int N;
int ans = 987654321;
int min_pin = 8;

// 상.우.하.좌
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

struct Pin {
	int r, c, dir;
};


vector<Pin> Find_Move_Pin(vector<vector<char>> &board) {

	vector<Pin> mv_temp;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != 'o')	continue;
			for (int k = 0; k < 4; k++) {
				int rr = i + dr[k];
				int cc = j + dc[k];
				int mv_r = i + 2 * dr[k];
				int mv_c = j + 2 * dc[k];
				if ((rr >= 0 && rr<5 && cc >= 0 && cc<9) && (mv_r >= 0 && mv_r<5 && mv_c >= 0 && mv_c <9)) { // 게임판 범위 
					if (board[rr][cc] == 'o' && board[mv_r][mv_c] == '.')	mv_temp.push_back({ i,j,k });
				}
			}
		}
	}

	return mv_temp;
}

void Simul(int r, int c, int dir, int cnt, vector<vector<char>> &board) {


	
	vector<Pin> mv_temp;
	vector<vector<char>> temp = board;

	// 핀 이동 
	temp[r][c] = '.';
	temp[r + dr[dir]][c + dc[dir]] = '.';	// 인접 핀 제거
	temp[r + 2 * dr[dir]][c + 2 * dc[dir]] = 'o';

	// 이동 가능한 핀 확인. 
	mv_temp = Find_Move_Pin(temp);

	if (mv_temp.empty()) {

		int pin_cnt = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (temp[i][j] == 'o')	pin_cnt++;
			}
		}

		if (min_pin > pin_cnt) {
			min_pin = pin_cnt;
			ans = cnt;
		}
		else if (min_pin == pin_cnt) {
			if (ans > cnt)	ans = cnt;
		}
		return;
	}

	for (int i = 0; i < mv_temp.size(); i++) {
		Simul(mv_temp[i].r, mv_temp[i].c, mv_temp[i].dir, cnt + 1, temp);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int t = 1; t <= N; t++) {

		vector<vector<char>> board(5, vector<char>(9, ' '));
		vector<Pin> mv_able_dq;

		mv_able_dq.clear();

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
			}
		}

		mv_able_dq = Find_Move_Pin(board);



		for (int i = 0; i < mv_able_dq.size(); i++) {
			Simul(mv_able_dq[i].r, mv_able_dq[i].c, mv_able_dq[i].dir, 1, board);
		}
		if (mv_able_dq.empty()) {
			min_pin = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++)
					if (board[i][j] == 'o')	min_pin++;
			}
			ans = 0;
		}
		cout << min_pin << " " << ans << "\n";
		min_pin = 8;
		ans = 987654321;
	}


}