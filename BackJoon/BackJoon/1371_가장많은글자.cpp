#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
using namespace std;
int main() {
	freopen("input_1371.txt", "r", stdin);
	string input=" ", answer ="";
	int arr[26] = { 0, };
	int max_cnt = 0;
	while (cin>>input) {
	//while(!cin.eof()){
		//getline(cin, input);
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ' ')	continue; 
			arr[input[i] - 'a']++; 
		}
		//cin.clear();
	}
	for (int i = 0; i < 26; i++) {
		if (max_cnt <= arr[i]) {
			if (max_cnt == arr[i])	answer.push_back('a' + i);
			else {
				answer = "";
				answer.push_back('a' + i);
				max_cnt = arr[i]; 
			}
		}
	}
	cout << answer << "\n"; 
}