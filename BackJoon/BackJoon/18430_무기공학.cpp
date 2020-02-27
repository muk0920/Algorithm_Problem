#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
int N, M, ans;
int wood[5][5]; 

void DFS(int r, int c, int sum, vector<vector<bool>> & visited) {

	if (sum > ans) 		ans = sum; 
	
	
	for (int i = r; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == r && j < c)	continue; 
			for (int k = 0; k < 4; k++) {
				if (k == 0) { // 왼쪽, 아래 
					if (i == N-1 || j ==  0)	continue; 
					if (!visited[i][j] && !visited[i][j - 1] && !visited[i + 1][j]) {
						visited[i][j] = true;
						visited[i][j - 1] = visited[i + 1][j] = true; 
						int temp_sum = wood[i][j] * 2 + wood[i][j - 1] + wood[i + 1][j];
						DFS(i, j, sum + temp_sum, visited);
						visited[i][j - 1] = visited[i + 1][j] = false;
						visited[i][j] = false;
					}
				}
				else if (k == 1) { // 왼쪽, 위
					if (i == 0 || j == 0)	continue;
					if (!visited[i][j] && !visited[i][j - 1] && !visited[i - 1][j]) {
						visited[i][j] = true;
						visited[i][j - 1] = visited[i - 1][j] = true;
						int temp_sum = wood[i][j] * 2 + wood[i][j - 1] + wood[i - 1][j]; 
						DFS(i, j, sum + temp_sum, visited);
						visited[i][j - 1] = visited[i - 1][j] = false;
						visited[i][j] = false;
					}
				}
				else if (k == 2) { // 위, 오른쪽 
					if (i == 0 || j == M-1)	continue;
					if (!visited[i][j] && !visited[i - 1][j] && !visited[i][j + 1]) {
						visited[i][j] = true;
						visited[i - 1][j] = visited[i][j + 1] = true; 
						int temp_sum = wood[i][j] * 2 + wood[i - 1][j] + wood[i][j + 1];
						DFS(i, j, sum + temp_sum, visited);
						visited[i - 1][j] = visited[i][j + 1] = false;
						visited[i][j] = false;
					}
				}
				else if (k == 3) { // 오른쪽, 아래
					if (i == N-1 || j == M - 1)	continue;
					if (!visited[i][j] && !visited[i][j + 1] && !visited[i + 1][j]) {
						visited[i][j] = true;
						visited[i][j + 1] = visited[i + 1][j] = true; 
						int temp_sum = wood[i][j] * 2 + wood[i][j + 1] + wood[i + 1][j]; 
						DFS(i, j, sum + temp_sum, visited);
						visited[i][j + 1] = visited[i + 1][j] = false;
						visited[i][j] = false;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_18430.txt", "r", stdin); 
	cin >> N >> M; 
	if (N == 1 && M == 1) {
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> wood[i][j]; 
		}
	}
	vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(M, false));

	DFS(0, 0, 0, visited); 

	cout << ans << "\n";
}