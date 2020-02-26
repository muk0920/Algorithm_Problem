#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <stack> 
#include <vector>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_9935.txt", "r", stdin); 
	string str, bomb_str, answer="";
	cin >> str >> bomb_str;
	vector<char> st_str; 
	
	for (int i = 0; i < str.size(); i++) {

		if (str[i] == bomb_str[bomb_str.size() - 1]) { // 마지막이랑 같을 경우 .
			string temp = "";
			bool bomb_flag = true; 
			for (int k = 0; k < bomb_str.size() - 1; k++) {
				if (st_str.size() - bomb_str.size() + 1 < 0) {
					bomb_flag = false;
					break;
				}
				if (st_str[st_str.size() - bomb_str.size() + 1 + k] != bomb_str[k]) {
					bomb_flag = false;
					break;
				}
				if (!bomb_flag) break;
			}

			if (bomb_flag) { // 폭발 문자열인 경우 
				for (int j = 0; j < bomb_str.size() - 1; j++)
					st_str.pop_back();
			}
			else {
				st_str.push_back(str[i]); 
			}
		}
		else {
			st_str.push_back(str[i]); 
		}
	}

	if (st_str.empty())	cout << "FRULA\n";
	else {
		for (int i = 0; i < st_str.size(); i++)
			cout << st_str[i]; 
		cout << "\n";
	}
}