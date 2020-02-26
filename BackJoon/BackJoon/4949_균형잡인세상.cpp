#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <stack>

using namespace std; 
int main() {
	int small_bracket = 0; 
	int big_bracket = 0; 
	string input; 
	freopen("input_4949.txt", "r", stdin); 
	while (true) {
		getline(cin, input);
		if (input == ".")	break;
		stack<char> bracket; 
		bool fail_flag = false; 
		for (int i = 0; i < input.size(); i++) {
			
			if (input[i] == '(')	bracket.push('('); 
			else if (input[i] == '[') bracket.push('['); 
			else if (input[i] == ']') {
				if(!bracket.empty() && bracket.top() =='[') bracket.pop();
				else {
					fail_flag = true;
					break;
				}
			}
			else if (input[i] == ')') {
				if (!bracket.empty() && bracket.top() == '(') bracket.pop();
				else {
					fail_flag = true;
					break;
				}
			}
		}

		if (fail_flag || !bracket.empty()) cout << "no\n"; 
		else cout << "yes\n"; 
	}

}