#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std; 
int N, M, ans; 
char alpha[10] = { '0', '1', '2','3','4','5','6','7','8','9' };
bool visited[10]; 

void DFS(string res, int cnt, int size) {
	if (cnt == size) {
		int num = atoi(res.c_str()); 
		if (ans > size + abs(N - num)) {
			ans = size + abs(N - num);
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		
		if (cnt == 0 && i == 0 && size!= 1)	continue; 
		if (!visited[i]) {
			DFS(res + alpha[i], cnt + 1, size); 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_1107.txt", "r", stdin);
	cin >> N >> M;
	ans = abs(N - 100);
	for (int i = 0; i < M; i++) {
		int input; 
		cin >> input; 
		visited[input] = true; 
	}
	
	for (int len = 1; len <= 6; len++) {
		if(len < ans)
			DFS("",0, len);
	}

	cout << ans << "\n"; 

}