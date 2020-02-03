#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int graph[10][10];
bool visited[10];
int N, min_money = 200000000;

void Find_Root(int st, int mv, int cnt, int money) {

	if (cnt == N) {
		if (graph[mv][st] != 0) { // ���� ��ġ���� ���������� �� �� �ִ� ��츸 .
			if (min_money > money + graph[mv][st])
				min_money = money + graph[mv][st];
		}
		return;
	}

	if (min_money <= money)  return;

	for (int i = 0; i < N; i++) {
		if (!visited[i] && graph[mv][i] != 0) { // ���� ��ġ���� ���� ��ġ�� �� �� �־�� �ϰ�, �湮���� ���� ��ġ�����Ѵ�. 
			visited[i] = true;
			Find_Root(st, i, cnt + 1, money + graph[mv][i]);
			visited[i] = false;
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		visited[i] = true;
		Find_Root(i, i, 1, 0);
		visited[i] = false;
	}

	cout << min_money << "\n";
}
