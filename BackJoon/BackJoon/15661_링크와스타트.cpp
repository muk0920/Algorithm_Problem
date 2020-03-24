#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;
int N, ans = 987654321; 
bool team_arr[21]; 
bool visited[21]; 
int graph[21][21]; 

vector<int> vec; 

int Team_Sum(vector<int> &vec) {
	int sum = 0; 
	for (int i = 0; i < vec.size()-1; i++) {
		for (int j = i+1; j < vec.size(); j++) {
			sum += graph[vec[i]][vec[j]]; 
			sum += graph[vec[j]][vec[i]]; 
		}
	}
	return sum; 
}
void DFS(int idx, int cnt, int team) {
	if (cnt == team) {
		vector<int> team_1, team_2; 
		int team_1_sum = 0, team_2_sum = 0; 

		for (int i = 1; i <= N; i++) {
			if (team_arr[i]) team_1.push_back(i); 
			else team_2.push_back(i); 
		}

		team_1_sum = Team_Sum(team_1); 
		team_2_sum = Team_Sum(team_2); 
		 
		if (ans > abs(team_1_sum - team_2_sum))
			ans = abs(team_1_sum - team_2_sum); 

		return; 
	}

	for (int i = idx; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true; 
			team_arr[i] = true; 
			DFS(i + 1, cnt + 1, team);
			team_arr[i] = false; 
			visited[i] = false; 
		}
	}

}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_15661.txt", "r", stdin); 
	cin >> N; 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j]; 
		}
	}
	
	// ÆÀ »ý¼º 
	for (int i = 1; i <= (N+1)/2; i++) {
		DFS(1, 0, i); 
		memset(visited, false, sizeof(visited)); 
	}

	cout << ans << "\n";
}