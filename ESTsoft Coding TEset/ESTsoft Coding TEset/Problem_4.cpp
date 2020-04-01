#include <string>
#include <vector>
#include <iostream>
#include <map> 

using namespace std; 



string solution(string &S, string &C) {
	map<string,int> check; 
	vector<string> full_name_list; 
	vector<pair<string, int>> person;
	string temp="";
	string full_name = "";
	string answer = ""; 
	int space_cnt = 0;
	for (int i = 0; i < C.size(); i++) { // ȸ�� �̸��� �빮�� ���� ��� �ҹ��ڷ� ��ü 
		if (C[i] >= 'A' && C[i] <= 'Z')	C[i] += 32;
	}

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ';') {
			person.push_back(make_pair(temp, space_cnt));
			full_name_list.push_back(full_name); 
			space_cnt = 0; 
			temp = "";
			full_name = ""; 
			i++; // ; �ڿ� space �ִ�. 
		}
		else {
			if (S[i] == ' ') {
				space_cnt++;
			}
			if (S[i] >= 'A' && S[i] <= 'Z') { 
				full_name += S[i]; 
				temp += (S[i] + 32);
				continue; 
			}
			if (S[i] == '-') {
				full_name += S[i]; 
				continue;
			}
			
			temp += S[i];
			full_name += S[i]; 
		}
	}
	full_name_list.push_back(full_name);
	person.push_back(make_pair(temp, space_cnt)); // ������ �ο��� ; ����. 


	for (int i = 0; i < person.size(); i++) {
		string first_name = ""; 
		string last_name = ""; 
		int idx = 0;

		if (person[i].second == 2) { // middle name �ִ� ��� 
			while (person[i].first[idx] != ' ')	first_name += person[i].first[idx++];
			idx++; 
			while (person[i].first[idx] != ' ') idx++; 
			idx++; 
			while (person[i].first[idx] != ' ') {
				last_name += person[i].first[idx++];
				if (idx >= person[i].first.size()) break;
			}
		}
		else {
			while (person[i].first[idx] != ' ')	first_name += person[i].first[idx++];
			idx++; 
			while (person[i].first[idx] != ' ') {
				last_name += person[i].first[idx++];
				if (idx >= person[i].first.size()) break; 
			}
		}
		string check_name = last_name + '_' + first_name;
		string num = ""; 
		if (check.find(check_name) == check.end()) {
			check[check_name] = 1;
		}
		else {
			check[check_name]++;
			num = check[check_name] + '0'; 
		}

		answer += (full_name_list[i] + " <" + check_name + num + "@" + C + ".com>; "); 
	}
	answer.pop_back(); // �� ������ �����ּҿ��� ; �� �����̽� �����̱⿡ ���� 
	answer.pop_back();
	return answer; 

}

int main() {
	string S = "J Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter Brian Parker"; 
	string C = "Example"; 

	string temp = solution(S, C); 

	cout << temp;
}