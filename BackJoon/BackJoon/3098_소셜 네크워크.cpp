#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int N, M; 
int graph[51][51]; 
vector<int> ans; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_3098.txt", "r", stdin); 
	cin >> N >> M; 
	int time = 0;
	int all_cnt = (N*(N - 1)) / 2 - M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1; 
		graph[b][a] = 1; 
	}
	
	
	while (true) {
		
		if (all_cnt == 0)	break; 

		int cnt = 0; 
		vector<pair<int, int>> new_friend; 

		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (graph[i][j] == 1)	continue;  // �̹� i�� ����� j �� ����� �̹� ģ���ϰ�� 

				for (int k = 1; k <= N; k++) {
					if (graph[i][k] == 1 && graph[k][j] == 1) { // j �� ����� i�� ����� ģ���� ģ���ϰ�� 
						new_friend.push_back({ i,j }); 
						all_cnt--; 
						cnt++; 
						break;
					}
				}
			}
		}

		for (int i = 0; i < new_friend.size(); i++) { // ���� ���� ģ�� ������� �׷����� ǥ�� 
			graph[new_friend[i].first][new_friend[i].second] = 1;
			graph[new_friend[i].second][new_friend[i].first] = 1;
		}

		time++;
		ans.push_back(cnt); // ���� ���� ģ�� �� ���Ϳ� ���� 
	}

	cout << time << "\n"; 
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}