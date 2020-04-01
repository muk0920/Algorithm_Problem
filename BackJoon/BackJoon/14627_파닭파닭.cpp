#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int S, C; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_14627.txt", "r", stdin); 
	cin >> S >> C; 
	vector<long long> vec(S,0); 
	vector<long long> candidate; 

	long long low=1, mid, high=0;
	long long sum = 0; 

	for (int i = 0; i < S; i++) {
		cin >> vec[i]; 
		if (vec[i] > high)	high = vec[i]; 
		sum += vec[i]; 
	}

	while (low <= high) {
		
		mid = (low + high) / 2; 
		long long cnt = 0; 

		for (int i = 0; i < S; i++) {
			cnt += (vec[i] / mid); 
		}

		if (cnt >= C) {
			low = mid + 1; 
			candidate.push_back(mid); 
		}
		else {
			high = mid -1 ; 
		}
	}

	cout << (sum- C*candidate.back())<<"\n"; 
}