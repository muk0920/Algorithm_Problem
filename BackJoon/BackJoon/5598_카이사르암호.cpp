#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 
int main() {
	string input; 
	cin >> input; 
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'A')	input[i] = 'X'; 
		else if (input[i] == 'B') input[i] = 'Y'; 
		else if (input[i] == 'C') input[i] = 'Z'; 
		else input[i] -= 3;
	}
	
	cout << input << "\n"; 

}