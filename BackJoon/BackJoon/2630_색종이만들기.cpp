#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std; 
int N;
int map[129][129]; 
bool visited[129][129]; 
int blue_cnt, white_cnt; 

bool isTrue(int r, int c, int size) { // �ش� ũ���� �����̰� �������� Ȯ���ϴ� �Լ� 
	int prev = map[r][c]; 
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (prev != map[i][j])	return false; // ������ �Ұ��� 
		}
	}
	return true;  // �ش� ũ���� ������ ���� 
}

void Check(int r, int c, int size) { // �ϼ��� ������ �κ� �湮 ó���ϴ� �Լ� 
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			visited[i][j] = true; 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_2630.txt", "r", stdin); 
	cin >> N; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j]; 
		}
	}

	for (int i = N; i >= 1; i/=2) { // �������� ũ�� 
		for (int j = 0; j < N; j += i) {
			for (int k = 0; k < N; k += i) {
				if (!visited[j][k]&&isTrue(j, k, i)) {
					Check(j, k, i); // �����̷� �и��� �κ� �湮 ó���ϱ� 
					if (map[j][k] == 1)	blue_cnt++; 
					else if (map[j][k] == 0)	white_cnt++;
				}
			}
		}
	}

	cout<< white_cnt << "\n" << blue_cnt << "\n";
}