#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std; 
int N, M; 
deque<int> row;  
deque<int> col; 
int cur_r, cur_c; 

int Binary_Search(deque<int> line, int val) {
	int st = 0, ed = N - 1, mid;
	while (st < ed) {
		mid = (st + ed) / 2; 
		if (line[mid] <= val) {
			st = mid + 1; 
		}
		else {
			ed = mid - 1; 
		}
	}
	return mid; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input.txt", "r", stdin);
	cin >> N >> M; 
	row = deque<int>(N, 0);
	col = deque<int>(N, 0);
	int dp_r[10000][2] = { {0,0}, }; // 0�� �� : ���ʿ��� �Ÿ�  .  1�� �� : �����ʿ��� �Ÿ� 
//	int dp_c[100000][2] = { {0,0}, };  

	for (int i = 0; i < N; i++) { // ������ �� �Է� ���� 
		cin >> col[i] >> row[i];
	}
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	
	// dp �� ����, ���� �����鿡 �ش��ϴ� �Ÿ� �� ���ϱ� .
	int same_cnt = 1; // ���� ������ ���� 
	for (int i = 1; i < N; i++) {
		if (row[i - 1] == row[i]) {
			dp_r[i][0] = dp_r[i - 1][0];
			same_cnt++;
		}
		else {
			dp_r[i][0] = dp_r[i - 1][0] + same_cnt * (row[i] - row[i-1]);
			same_cnt = 1; 
		}
	}

	for (int i = 0; i < N; i++)
		cout << dp_r[i][0] << " ";



	//for (int i = 0; i < M; i++) { // ��ɼ���ŭ �ݺ� 
	//	char ch; 
	//	cin >> ch;
	//	if (ch == 'S')	cur_r -= 1;  // ������� �κ� �̵� 
	//	else if (ch == 'J') cur_r += 1; 
	//	else if (ch == 'I')	cur_c += 1; 
	//	else if (ch == 'Z') cur_c -= 1; 

	//	// ��� �ε����� ���� �̺�Ž������ ã��.
	//	int r_idx, c_idx, 
	//	r_idx = Binary_Search(row,cur_r);
	//	c_idx = Binary_Search(col,cur_c); 

	//	cout << dp_r[r_idx] + dp_c[c_idx] << "\n";


	//}
}