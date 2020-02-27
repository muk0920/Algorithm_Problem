#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std; 
int N, K , ans; 
vector<int> babel; 
bool visited[8]; 

void DFS(int cnt, int kg) {
	if (kg < 500)	return; 

	if (cnt == N) {
		ans++; 
		return;
	}

	for (int i = 0; i < babel.size(); i++) {
		if (!visited[i]) {
			visited[i] = true; 
			DFS(cnt + 1, kg - K + babel[i]);
			visited[i] = false; 
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_18429.txt", "r", stdin);
	cin >> N >> K; 

	babel = vector<int>(N, 0); 

	for (int i = 0; i < N; i++) {
		cin >> babel[i]; 
	}

	DFS(0, 500);

	cout << ans << "\n";
}