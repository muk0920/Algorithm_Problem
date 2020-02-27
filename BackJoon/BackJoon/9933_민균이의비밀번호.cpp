#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {
	freopen("input_9933.txt", "r", stdin);
	int N; 
	bool finish_flag = false; 
	cin >> N; 
	vector<string> vec(N, ""); 
	for (int i = 0; i < N; i++) {
		string input;
		cin >> vec[i]; 
	}
	
	for (int i = 0; i < vec.size(); i++) {
		string temp = vec[i]; 
		reverse(temp.begin(), temp.end());
		
		for (int j = i; j < vec.size(); j++) {
			if (vec[j] == temp) {
				int idx = temp.size() / 2;
				cout << temp.size() << " " << temp[idx] << "\n";
				finish_flag = true; 
				break; 
			}
		}
		if (finish_flag) break; 
	}
}