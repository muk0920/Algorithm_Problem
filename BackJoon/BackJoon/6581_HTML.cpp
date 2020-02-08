#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input.txt", "r", stdin);
	bool newline = true; 
	string str; 
	int voca_cnt = 0; 
	while (cin>>str) {
		
		if (str == "<br>") {
			cout << "\n";
			newline = true; 
			continue;
		}
		else if (str == "<hr>") {
			if (!newline) {
				cout << "\n";
				newline = true;
				voca_cnt = 0;
			}
			for (int i = 0; i < 80; i++)
				cout << "-";
			voca_cnt = 0;
			newline = true; 
			cout << "\n";
			continue;
		}
		else {
			if (voca_cnt + str.size() > 80) {
				cout << "\n";
				newline = true; 
				voca_cnt = 0;
			}
			voca_cnt += (str.size()+1); 
			if (!newline)	cout << " ";
			cout <<str;
			newline = false; 
		}
	}
	cout << "\n";
	return 0;
}