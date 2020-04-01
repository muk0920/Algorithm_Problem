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

	for (int i = 1; i <= N; i++) { // 해당 노드의 자식이 몇개인지 저장하는 함수 .
		if (i == parent[i])	continue; 

		child_num[parent[i]] += child_num[i]; 
	}

	for (int i = 0; i < M; i++) { // 질문 반복 
		int a, b; 
		cin >> a >> b; 

		if (Check(b, a)) { // b 를 거슬러 올라가면 a 를 만나는지 확인  
			ans += (child_num[a] - child_num[b]);  // 만난다면 a 의 자손에서  b 의 자손이 아닌거 빼기 
		}
		else {
			ans += child_num[a];  // a 와 b 는 서로 독립 관계 
		}
		
	}

	cout << ans << "\n"; 
}
