#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
int N, K; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_3.txt", "r", stdin);
	int tc; 
	cin >> tc; 
	for (int t = 1; t <= tc; t++) {
		cin >> N >> K; 
		vector<int> session(N, 0); 
		vector<int> diff(N - 1, 0); 
		int low = 1, high = 1000000000, mid =0; 

		for (int i = 0; i < N; i++) {
			cin >> session[i]; 
		}

		for (int i = 1; i < N; i++) {
			diff[i-1] = session[i] - session[i - 1]; 
		}
		vector<int> temp; 

		while (low <= high) { // bineary_search
			mid = (low + high) / 2;
			int cnt = 0;
			for (int i = 0; i < diff.size(); i++) {
				cnt += (diff[i] / mid);
				if (diff[i] % mid == 0) cnt -= 1;
			}

			if (cnt <= K) {
				high = mid - 1;
				temp.push_back(mid);
			}
			else {
				low = mid + 1;
				
			}
		}

		cout << "Case #"<<t<<": "<<temp.back() << "\n"; 
	}

}