#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set> 
#include <string>
#include <vector>
using namespace std;
int N, K; 
int card_arr[11]; 
bool visited[11]; 

set<string> card_set; 

void DFS( string num, int cnt) {
	
	if (cnt == K) {
		card_set.insert(num);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true; 
			DFS(num + to_string(card_arr[i]), cnt+1);
			visited[i] = false; 
		}
	}
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_5568.txt", "r", stdin);
	cin >> N >> K; 
	for (int i = 0; i < N; i++) {
		cin >> card_arr[i]; 
	}

	DFS("", 0); 

	cout << card_set.size() << "\n";
	
}