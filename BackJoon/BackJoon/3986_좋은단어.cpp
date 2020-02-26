#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <stack>
using namespace std; 
int main() {
	int N, answer = 0; 
	string input; 
	freopen("input_3986.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		stack<char> st;
		cin >> input; 
		
		for (int j = 0; j < input.size(); j++) {
			if (!st.empty()) {
				if (st.top() == input[j])	st.pop(); 
				else st.push(input[j]);
			}
			else {
				st.push(input[j]); 
			}
		}

		if (st.empty())	answer++; 
	}
	cout << answer << "\n";
}