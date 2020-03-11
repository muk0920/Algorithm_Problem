#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 
int main() {
	freopen("input_1718.txt", "r", stdin);
	string input, key; 
	int idx = 0;
	getline(cin, input);
	cin >> key; 
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			cout << " ";
			continue; 
		}
		int dif = input[i] - key[i%key.size()];
		if (dif <= 0) {
			dif = 25 + dif;
			cout << (char)(dif + 'a');
		}
		else {
			cout << (char)(dif + 96);
		}
		
	}
	cout << "\n";
}