#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {
	map<int, int> arr;
	map<int, int>::reverse_iterator it;

	for (int i = 0; i<A.size(); i++) {
		if (arr.find(A[i]) == arr.end()) { // 없을 경우 
			arr[A[i]] = 1;
		}
		else { // 있을 경우
			arr[A[i]]++;
		}
	}

	for (it = arr.rbegin(); it != arr.rend(); it++) {
		if (it->first == it->second) {
			return it->first;
		}	
	}
	return 0;
}

int main() {
	vector<int> A = { 3,8,2,3,3,2 }; 
	cout << solution(A); 

}
