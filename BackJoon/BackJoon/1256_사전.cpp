#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> 

using namespace std; 
long long combi_arr[201][201]; 
int N, M, K; 
string answer = "";

void Make_Combi() {
	combi_arr[1][0] = 1; 
	combi_arr[1][1] = 1; 
	for (int i = 2; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				combi_arr[i][j] = 1;
				continue; 
			}

			if (combi_arr[i - 1][j - 1] >= 1000000000 || combi_arr[i - 1][j] >= 1000000000) {
				combi_arr[i][j] = 1000000000;
				continue; 
			}

			combi_arr[i][j] = combi_arr[i - 1][j - 1] + combi_arr[i - 1][j]; 
		}
	}
	return; 
}


void Find_Pos(int a_cnt, int z_cnt, int jump_cnt) {

	if (a_cnt == 0) {
		for (int i = 0; i < z_cnt; i++)
			answer += "z";
		return; 
	}

	if (z_cnt == 0) {
		for (int i = 0; i < a_cnt; i++)
			answer += "a";
		return; 
	}

	long long idx = combi_arr[a_cnt + z_cnt - 1][a_cnt - 1]; 

	if (idx > jump_cnt) { // a 배치한 이후 뒤에 경우의 수 비교 
		answer += "a"; 
		Find_Pos(a_cnt - 1, z_cnt, jump_cnt);
	}
	else if (jump_cnt <= 1000000000) {
		answer += "z";
		Find_Pos(a_cnt, z_cnt-1, jump_cnt - idx);
	}
	else {
		answer = "-1"; 
		return; 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_1256.txt", "r", stdin);
	cin >> N >> M >> K;

	Make_Combi();

	if (combi_arr[N + M][N] < K)	answer = "-1";
	else Find_Pos(N, M, K-1); 

	cout << answer << "\n";
}