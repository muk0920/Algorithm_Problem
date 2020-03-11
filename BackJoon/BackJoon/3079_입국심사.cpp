#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std; 

#include <string>
#include <vector>
#include <iostream> 

using namespace std;


int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_3079.txt", "r", stdin);
	int N, M; 
	cin >> N >> M; 
	vector<int> time (N, 0);
	long long max = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> time[i];
		if (max < time[i])	max = time[i]; 
	}
	
	long long low = 1, mid = 0, high = max*M;
	long long ans = max*M; 

	while (low <= high) {
		long long cnt = 0;
		mid = low - (low - high) / 2;

		for (int i = 0; i<time.size(); i++) {
			cnt += (mid / time[i]);
		}

		if (cnt < M) {
			low = mid + 1;
		}
		else {
			if (mid < ans)
				ans = mid;
			high = mid - 1;
		}
	}

	cout << ans << "\n";
}