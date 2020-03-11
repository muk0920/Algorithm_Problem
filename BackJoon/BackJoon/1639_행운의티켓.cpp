#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>

using namespace std; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	string input; 
	int ans = 0; 

	cin >> input; 

	for (int len = (input.size() + 1) / 2; len >= 0; len--) {
		
		if (len < ans)	break; 

		for (int i = 0; i < input.size(); i++) { // 시작점 
			if (2 * len + i > input.size())	break; 
			int left_sum = 0, right_sum = 0;
			for (int j = i; j < i + len; j++) { // 왼쪽 
				left_sum += (input[j] - '0');
			}
			for (int j = i + len; j < i + 2 * len; j++){ // 오른쪽
				right_sum += (input[j] - '0'); 
			}
			if (left_sum == right_sum) {
				ans = 2*len; 
				break; 
			}
		}	

	}

	cout << ans << "\n";

}