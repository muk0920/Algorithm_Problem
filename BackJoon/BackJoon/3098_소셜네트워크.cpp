// �ڽ��� ģ���� ģ�� ����� �ڽ��� ģ���� �߰�. 
// ģ�� ����� ������ �����ؾ��Ѵ�. (1�� �ҿ�) 
// ��� ģ������� ��Ī. 
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
			
		// ģ�� ���迡�� ���������� �߰�
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
	
		// �ش� ��¥�� ���� ģ������ �߰�
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

// ���� 6:37
// �߰� : 7�� 10��  --> �ð� �ʰ� ..  ( 3 ������ ) 
// �ٸ� ������� �ٽ�. 

