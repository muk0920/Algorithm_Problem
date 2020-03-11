#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main() {
	int N;
	cin >> N;
	vector<int> weight(N, 0);
	for (int i = 0; i < N; i++)
		cin >> weight[i];

	sort(weight.begin(), weight.end());

	long long answer = weight[0];
	if (weight[0] != 1)  
		cout << 1 << "\n";
	else {
		for (int i = 1; i < weight.size(); i++) {
			if (answer + 1 < weight[i]) break;
			else answer += weight[i];
		}

		cout << answer + 1 << "\n";
	}
}