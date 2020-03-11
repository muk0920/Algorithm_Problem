#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std; 
int N; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_2075.txt", "r", stdin); 
	cin >> N; 
	priority_queue<long long> pq;
	int x; 
	for (int i = 0; i < N*N; i++) {
		cin >> x;
		if (pq.size() < N) {
			pq.push(-x); 
		}
		else {
			if (-pq.top() < x) {
				pq.pop(); 
				pq.push(-x);
			}
		}
	}

	cout << -pq.top() << "\n";
}