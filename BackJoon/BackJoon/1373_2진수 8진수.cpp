#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std; 

int main() {
	string input; 
	cin >> input; 
	while (input.size() % 3 != 0)	input = "0" + input; 

	for (int i = 0; i < input.size() - 2; i+=3) {
		cout << (input[i] - '0') * 4 + (input[i + 1] - '0') * 2 + (input[i+2] - '0');
	}
	cout << "\n";
}