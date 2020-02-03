#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int N; 
bool check[504]; 
string num[504]; 

void Make_Num() {

	int idx = 0; 
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || i == k || j == k)	continue; 
				num[idx++] = to_string(100 * i + 10 * j + k);
			}
		}
	}
}
bool Check(string str1, string str2, int ball, int strike) {
	int strike_cnt = 0;
	int ball_cnt = 0; 

	// 스트라이크 확인 
	if (str1[0] == str2[0]) {
		strike_cnt++;
	}
	if (str1[1] == str2[1]) {
		strike_cnt++;
	}
	if (str1[2] == str2[2]) {
		strike_cnt++;
	}

	if (str1[0] == str2[1] || str1[0] == str2[2])	ball_cnt++;
	if (str1[1] == str2[0] || str1[1] == str2[2])	ball_cnt++;
	if (str1[2] == str2[0] || str1[2] == str2[1])	ball_cnt++;

	if (ball == ball_cnt && strike == strike_cnt) 		
		return false; 
	else 
		return true; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N; 
	Make_Num();

	for (int i = 0; i < N; i++) {
		string input;
		int ball, strike;
		cin >> input >> strike >> ball; 

		for (int j = 0; j < 504; j++) {
			if (!check[j]) 
				check[j] = Check(num[j],input, ball, strike);
		}
	}

	int ans = 0;
	for (int i = 0; i < 504; i++) {
		if (!check[i])	ans++;
	}

	cout << ans<<"\n"; 
}