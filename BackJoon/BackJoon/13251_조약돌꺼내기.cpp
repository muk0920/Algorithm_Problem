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
		cin >> arr[i]; // ���� ���൹�� �� ���� 
		sum += arr[i]; // ��ü ���൹�� ���� ���ϱ�
	}
	cin >> K; 

	for (int i = 1; i <= M; i++) {
		if (arr[i] >= K) able_arr[i] = true; // ������ ���� K �� ���� �� �ִ� ����鸸 üũ 
	}


	for (int i = 1; i <= M; i++) {
		if (able_arr[i]) {
			double temp = 1; 
			for (int j = 0; j < K; j++) {	// ���� ���ϱ� 
				temp *= (arr[i] - (double)j);
			}
			numerator += temp;
		}
	}

	for (int i = 0; i < K; i++)			// �и� ���ϱ� 
		denominator *= (double)(sum - i);

	cout<<fixed;
	cout.precision(16);
	cout << (double)(numerator / denominator) << "\n";
}