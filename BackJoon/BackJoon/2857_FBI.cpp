#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std; 
int main() {
	freopen("input_2857.txt", "r", stdin); 
	bool fbi_flag = false; 
	for (int i = 1; i <= 5; i++) {
		string input;
		cin >> input; 
		for (int j = 0; j < input.size()-2; j++) {
			if (input[j] == 'F' && input[j + 1] == 'B' && input[j + 2] == 'I') {
				cout << i << " ";
				fbi_flag = true; 
				break; 
			}
		}
	}
	if (!fbi_flag) cout << "HE GOT AWAY!\n";
	else cout << "\n";
}