#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int arr[51]; 
bool able_arr[51]; 
int N, M, K; 

int main() {
	freopen("input_13251.txt", "r", stdin);
	double sum = 0, numerator = 0, denominator = 1; 
	cin >> M; 
	for (int i = 1; i <= M; i++) {
		cin >> arr[i]; // 색상별 조약돌의 수 저장 
		sum += arr[i]; // 전체 조약돌의 개수 구하기
	}
	cin >> K; 

	for (int i = 1; i <= M; i++) {
		if (arr[i] >= K) able_arr[i] = true; // 동일한 색을 K 개 뽑을 수 있는 색상들만 체크 
	}


	for (int i = 1; i <= M; i++) {
		if (able_arr[i]) {
			double temp = 1; 
			for (int j = 0; j < K; j++) {	// 분자 구하기 
				temp *= (arr[i] - (double)j);
			}
			numerator += temp;
		}
	}

	for (int i = 0; i < K; i++)			// 분모 구하기 
		denominator *= (double)(sum - i);

	cout<<fixed;
	cout.precision(16);
	cout << (double)(numerator / denominator) << "\n";
}