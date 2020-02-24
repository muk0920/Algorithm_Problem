#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <deque>
#include <algorithm>
#include <vector>
#include <set> 
using namespace std;
int N, answer, k_num; 
deque<long long> dq;
vector<long long> not_div; 

long long gcd(long long a, long long b) { // 두 수의 최대공약수 구하는 함수 
	if (a < b)	swap(a, b);
	while (b > 0) {
		long long temp = a; 
		a = b; 
		b = temp %b; 
	}
	return a; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_14476.txt", "r", stdin);
	cin >> N;
	dq = deque<long long>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> dq[i];
	}
	sort(dq.begin(), dq.end()); 
	long long gcd_num = 0; 

	// 0번 제외한 경우 
	gcd_num = gcd(dq[1], dq[2]); 
	for (int i = 1; i < dq.size(); i++) {
		
		if (dq[i] % gcd_num != 0) {
			gcd_num = gcd(gcd_num, dq[i]); 
		}
		if (gcd_num == 1)	break; 
	}
	if (gcd_num != 1 && (dq[0] %gcd_num !=0)) {
		answer = gcd_num;
		k_num = dq[0]; 
	}
	// 1번 제외한 경우 
	gcd_num = gcd(dq[0], dq[2]);
	for (int i = 0; i < dq.size(); i++) {
		if (i == 1) continue; 
		if (dq[i] % gcd_num != 0) {
			gcd_num = gcd(gcd_num, dq[i]);
		}
		if (gcd_num == 1)	break;
		if (gcd_num < answer) break; 
	}
	if (gcd_num != 1 && (dq[1] %gcd_num != 0)) {
		if (gcd_num > answer) {
			answer = gcd_num;
			k_num = dq[1]; 
		}
	}

	// 2번 이후 제외한 경우 
	gcd_num = gcd(dq[0], dq[1]); 
	if (answer < gcd_num) {
		for (int i = 2; i < dq.size(); i++) {
			if (dq[i] % gcd_num != 0) {
				not_div.push_back(dq[i]);
			}
		}
	}
	long long temp = gcd_num; 
	for (int i = 0; i < not_div.size(); i++) {
		// i 는 K의 인덱스 ( 뺀 값 )
		bool fail_flag = false;
		gcd_num = gcd(not_div[i], temp); 
		for (int j = 0; j < not_div.size(); j++) {
			if (i == j)	continue;
			if (gcd_num < answer) break; // 백트래킹 
			if (dq[j] % gcd_num != 0) {
				gcd_num = gcd(gcd_num, dq[j]);
			}
			if (gcd_num == 1) {
				fail_flag = true;
				break;
			}
		}

		if (!fail_flag) {
			if (not_div[i] % gcd_num == 0)	continue;  // 최대공약수는 K 의 약수가 아니어야한다. 

			if (answer < gcd_num) {
				answer = gcd_num;
				k_num = not_div[i];
			}
		}
	}

	if (answer == 0) { // 최대 공약수가 1인 경우 ( 없는 경우) 
		cout << "-1\n";
	}
	else {
		cout << answer << " " << k_num << "\n";
	}
}