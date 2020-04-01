#include <vector>
#include <iostream>

using namespace std; 

int Inc_Count(int left, int mid, int right, vector<int>&A) {
	int cnt = 0; 

	// 첫번째꺼 지운경우 
	if (left - 1 >= 0) {
		if (right + 1 < A.size()) {
			if (A[left - 1] > A[mid] && A[right] > A[right + 1])	cnt++; 
		}
		else {
			if (A[left - 1] > A[mid])	cnt++; 
		}
	}
	else {
		if (right + 1 < A.size()) {
			if (A[right] > A[right + 1])	cnt++;
		}
		else {
			cnt++; 
		}
	}
	// 두번째꺼 지운경우 
	if (left - 1 >= 0) {
		if (right + 1 < A.size()) {
			if (A[left - 1] > A[left] && A[right] > A[right + 1])	cnt++;
		}
		else {
			if (A[left - 1] > A[left])	cnt++;
		}
	}
	else {
		if (right + 1 < A.size()) {
			if (A[right] > A[right + 1])	cnt++;
		}
		else {
			cnt++;
		}
	}
	// 세번째꺼 지운경우 
	if (left - 1 >= 0) {
		if (right + 1 < A.size()) {
			if (A[left - 1] > A[left] && A[mid] > A[right + 1])	cnt++;
		}
		else {
			if (A[left - 1] > A[left])	cnt++;
		}
	}
	else {
		if (right + 1 < A.size()) {
			if (A[mid] > A[right + 1])	cnt++;
		}
		else {
			cnt++;
		}
	}
	return cnt; 
}

int Dec_Count(int left, int mid, int right, vector<int>&A) {
	int cnt = 0;

	// 첫번째꺼 지운경우 
	if (left - 1 >= 0) {
		if (right + 1 < A.size()) {
			if (A[left - 1] < A[mid] && A[right] < A[right + 1])	cnt++;
		}
		else {
			if (A[left - 1] < A[mid])	cnt++;
		}
	}
	else {
		if (right + 1 < A.size()) {
			if (A[right] < A[right + 1])	cnt++;
		}
		else {
			cnt++;
		}
	}
	// 두번째꺼 지운경우 
	if (left - 1 >= 0) {
		if (right + 1 < A.size()) {
			if (A[left - 1] < A[left] && A[right] < A[right + 1])	cnt++;
		}
		else {
			if (A[left - 1] < A[left])	cnt++;
		}
	}
	else {
		if (right + 1 < A.size()) {
			if (A[right] < A[right + 1])	cnt++;
		}
		else {
			cnt++;
		}
	}
	// 세번째꺼 지운경우 
	if (left - 1 >= 0) {
		if (right + 1 < A.size()) {
			if (A[left - 1] < A[left] && A[mid] < A[right + 1])	cnt++;
		}
		else {
			if (A[left - 1] < A[left])	cnt++;
		}
	}
	else {
		if (right + 1 < A.size()) {
			if (A[mid] < A[right + 1])	cnt++;
		}
		else {
			cnt++;
		}
	}
	return cnt; 
}

int solution(vector<int> &A) {
	bool inc_flag = false; 
	bool dec_flag = false; 
	bool remove_flag = false; 

	int same_cnt = 0; 
	int ans = 0; 
	// 같은 경우 먼저 제거 
	for (int i = 1; i < A.size(); i++) {
		if (A[i - 1] == A[i]) {
			same_cnt++; 
			A.erase(A.begin() + i); 
			i--; 
			remove_flag = true; 
		}
	}

	if (same_cnt >= 2)	return -1; 
	
	if (same_cnt == 1)	ans = 2; 

	for (int i = 1; i < A.size(); i++) {
		if (A[i - 1] < A[i]) {
			if (inc_flag) {
				if (remove_flag)	return -1;  // 이미 다른 곳에서 나무를 제거한 경우 
				else { // 경우의 수 체크 
					if (i + 1 < A.size()) {
						if (A[i] < A[i + 1])	return -1; // 3개 이상 연달아 증가하는 경우 
					}

					ans += Inc_Count(i - 2, i - 1, i, A); 
					remove_flag = true; 
				}
			}
			else {
				inc_flag = true; 
			}
			dec_flag = false;
		}
		else if (A[i - 1] > A[i]) {
			if (dec_flag) {
				if (remove_flag)	return -1; 
				else {
					if (i + 1 < A.size()) {
						if (A[i] > A[i + 1])	return -1; // 3개 이상 연달아 감소하는 경우 
					}
					ans += Dec_Count(i - 2, i - 1, i, A); 
					remove_flag = true; 
				}
			}
			else {
				dec_flag = true; 
			}
			inc_flag = false; 
		}
	}

	return ans; 
}

int main() {
	vector<int> A = {1,3,1,2 }; 
	cout << solution(A) << " ";

}