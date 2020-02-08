#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std; 
int board[15][15];
bool num[15]; // �ش� ���� �ִ��� üũ�ϱ� ���� �迭
bool rd_diagonal[30]; // ���� �밢�� 
bool ru_diagonal[30]; // ������ �밢�� 
int ans, N; 

void Test_Queen(int r) {
	if (r == N) {
		ans++; 
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!num[i] && !rd_diagonal[r + i] && !ru_diagonal[r - i + 14]) {
			num[i] = rd_diagonal[r + i] = ru_diagonal[r - i + 14] = true; 
			Test_Queen(r + 1);
			num[i] = rd_diagonal[r + i] = ru_diagonal[r - i + 14] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N; 
	Test_Queen(0);

	cout << ans << "\n";
}