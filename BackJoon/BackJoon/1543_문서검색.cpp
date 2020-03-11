#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 
string input, docu;
int ans = 0; 
void DFS(int idx, int cnt) {
	if (ans < cnt)	
		ans = cnt; 
	
	if (idx >= input.size())	return; 

	for(int i = idx; i < input.size()-docu.size()+1;i++){
		if (input[i] != docu[0])	continue; 
		string temp = input.substr(i, docu.size());
		if (temp == docu) {
			DFS(i + docu.size(), cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_1543.txt", "r", stdin);
	 
	getline(cin, input);
	getline(cin, docu);

	DFS(0, 0);
	
	cout << ans << "\n";
}