#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 
int main() {
	int ans_1 = 0, ans_2 = 0; 
	string input, temp;
	cin >> input; 
	for (int i = 0; i < input.size() - 2; i++) {
		temp = input.substr(i, 3); 
		if (temp == "JOI")	ans_1++; 
		else if (temp == "IOI")	ans_2++; 
	}

	cout << ans_1 << "\n" << ans_2 << "\n";
}