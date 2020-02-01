#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
deque<string> voca[26];
int N;
bool isComp(string str, string str2) {
	return str.length() < str2.length();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		voca[input[0] - 'a'].push_back(input);
	}

	for (int i = 0; i < 26; i++) {
		if (voca[i].empty())   continue;
		sort(voca[i].begin(), voca[i].end(), isComp);
	}

	for (int i = 0; i < 26; i++) {
		if (voca[i].size() < 2)   continue;
		for (int j = 0; j < voca[i].size(); j++) { // 단어 선택 
			for (int k = j + 1; k < voca[i].size(); k++) { // 접두어로 쓰이는지 체크
				bool dif_flag = true;
				if (voca[i][j] == voca[i][k].substr(0,voca[i][j].size())) {
					dif_flag = false;
				}
				if (!dif_flag) { // 접두어로 쓰일경우 
					N--;
					break;
				}
			}
		}
	}
	cout << N << "\n";
}

// 시작 7시 52분 . 