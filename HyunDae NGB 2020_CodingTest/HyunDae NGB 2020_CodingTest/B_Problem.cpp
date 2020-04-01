#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int N, M; 

vector<int> parent;
vector<int> child_num; 

bool Check(int a, int target) {
	if (parent[a] == target)	return true; 
	else if (parent[a] == a)	return false; 
	else return Check(parent[a], target); 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_b.txt", "r", stdin);
	cin >> N >> M; 
	parent = vector<int>(N+1,  0); 
	child_num = vector<int>(N+1, 0); 

	int ans = 0; 

	for (int i = 1; i <= N; i++) {
		cin >> parent[i]; 
		
		child_num[parent[i]]++;
		if (parent[i] == 0)	parent[i] = i; 
	}

	for (int i = 1; i <= N; i++) { // �ش� ����� �ڽ��� ����� �����ϴ� �Լ� .
		if (i == parent[i])	continue; 

		child_num[parent[i]] += child_num[i]; 
	}

	for (int i = 0; i < M; i++) { // ���� �ݺ� 
		int a, b; 
		cin >> a >> b; 

		if (Check(b, a)) { // b �� �Ž��� �ö󰡸� a �� �������� Ȯ��  
			ans += (child_num[a] - child_num[b]);  // �����ٸ� a �� �ڼտ���  b �� �ڼ��� �ƴѰ� ���� 
		}
		else {
			ans += child_num[a];  // a �� b �� ���� ���� ���� 
		}
		
	}

	cout << ans << "\n"; 
}
