#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isComp(int a, int b) {
	return a > b; 
}

int Check_Digit(int num) {
	int sum = 0; 
	while (num > 0) {
		sum += num % 10; 
		num /= 10; 
	}
	return sum; 
}

int solution(vector<int> &A) {
	vector<int> vec[82]; // 각 자리 숫자의 합 범위 1~81 (각 자리 숫자의 합)
	int ans = -1; 

	for (int i = 0; i < A.size(); i++) {
		int digit = Check_Digit(A[i]); 
		vec[digit].push_back(A[i]); 
	}

	for (int i = 1; i < 82; i++) {
		if (vec[i].empty())	continue; 
		sort(vec[i].begin(), vec[i].end(), isComp); // 오름차순으로 정렬 
	}

	for (int i = 1; i < 82; i++) {
		if (vec[i].size() < 2)	continue;
		if (ans < vec[i][0] + vec[i][1]) {
			ans = vec[i][0] + vec[i][1]; 
		}
	}

	cout << "!"; 
	return ans; 
}

int main() {
	vector<int> A = { 51,32,43 }; 
	cout<<solution(A); 
}

//
//int main() {
//	vector<int> A = { 51,32,43 }; 
//
//	cout << solution(A); 
//}