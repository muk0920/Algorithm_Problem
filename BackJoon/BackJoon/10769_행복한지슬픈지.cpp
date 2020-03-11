#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	freopen("input_10769.txt", "r", stdin);
	string input; 
	int smile_cnt = 0, sad_cnt = 0;
	getline(cin, input);
	for (int i = 0; i < input.size()-2; i++) {
		string temp = input.substr(i, 3);
		if (temp == ":-)")	smile_cnt++;
		else if (temp == ":-(")	sad_cnt++; 
	}

	if (smile_cnt == 0 && sad_cnt == 0)	cout << "none\n";
	else if (smile_cnt == sad_cnt)	cout << "unsure\n";
	else if (smile_cnt > sad_cnt)	cout << "happy\n";
	else cout << "sad\n";
}