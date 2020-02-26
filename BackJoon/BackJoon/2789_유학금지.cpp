#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string> 
using namespace std;
char check[9] = { 'C', 'A', 'M', 'B','R','I','D','G','E' };
int main() {
	string input, answer =""; 
	cin >> input; 
	for (int i = 0; i < input.size(); i++) {
		bool check_flag = false; 
		for (int j = 0; j < 9; j++) {
			if (input[i] == check[j]) {
				check_flag = true;
				break; 
			}
		}
		if (!check_flag) answer = answer + input[i]; 
	}

	cout << answer << "\n";
}