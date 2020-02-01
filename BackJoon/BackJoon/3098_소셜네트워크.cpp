// 자신의 친구의 친구 목록을 자신의 친구로 추가. 
// 친구 관계는 상대방이 수락해야한다. (1일 소요) 
// 모든 친구관계는 대칭. 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
using namespace std; 

int net[51][51];
int temp[51][51]; 
vector<int> ans; 
deque<pair<int, int>> network;

int N, M, all_fr_cnt; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input.txt", "r", stdin);
	cin >> N >> M; 
	for (int i = 0; i < M; i++) {
		int input1, input2; 
		cin >> input1 >> input2; 
		net[input1][input2] = 1; 
		net[input2][input1] = 1;
		temp[input1][input2] = 1;
		temp[input2][input1] = 1;
		network.push_back({ input1,input2 });
	}
	all_fr_cnt = (N*(N-1)) / 2 - M ; 

	while (all_fr_cnt > 0) {
			
		// 친구 관계에서 꼬리꼬리로 추가
		int size = network.size(); 
		int new_cnt = 0;
		for (int i = 0; i < size; i++) {
			int me = network.front().first, fr = network.front().second;
			for (int j = 1; j <= N; j++) {
				if (me == j)	continue; 
				if (fr == j)	continue;
				if (net[fr][j] == 1 && temp[me][j] != 1) {
					temp[me][j] = 1; 
					temp[j][me] = 1; 
					network.push_back({ me,j });
				}
			}
			network.pop_front();
		}
	
		// 해당 날짜에 생성 친구관계 추가
		for (int i = 1; i <= N; i++) {
			for (int j = i+1; j <= N; j++) {
				if (net[i][j] != temp[i][j]) {
					net[i][j] = temp[i][j]; 
					net[j][i] = temp[i][j];
					new_cnt++;
				}
			}
		}
		ans.push_back(new_cnt);
		all_fr_cnt -= new_cnt;
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

}

// 시작 6:37
// 중간 : 7시 10분  --> 시간 초과 ..  ( 3 번실패 ) 
// 다른 방법으로 다시. 

