// 1 번 방법
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	while (!skill_trees.empty()) {
		string str, res = "";
		int cnt = 0;
		bool fail_flag = false;
		str = skill_trees.back();
		skill_trees.pop_back();

		for (int i = 0; i<str.size(); i++) {	// res 에 스킬 순서를 기록 ( 순차적으로 )
			for (int j = 0; j<skill.size(); j++) {
				if (skill[j] == str[i])  res += to_string(j);
			}
		}

		for (int i = 0; i<res.size(); i++) { // cnt 변수는 0부터 시작하고 빠지는 숫자 없이 순차적으로 증가해야함. 
			if (cnt == res[i] - '0')    cnt++;
			else {
				fail_flag = true;
				break;
			}
		}
		if (!fail_flag)  answer++;
	}

	return answer;
}

// 2번 방법. 비슷한 접근이지만 또 다른 방법 ( 살짝 더 빠름 ) 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	vector<int> order(26, 0);
	int flow = 1;

	for (int i = 0; i<skill.size(); i++)
		order[skill[i] - 'A'] = flow++;

	for (int i = 0; i<skill_trees.size(); i++) {
		int flow = 1;
		bool fail_flag = false;

		string str = skill_trees[i];

		for (int j = 0; j<str.size(); j++) {
			if (order[str[j] - 'A'] != 0) {
				if (order[str[j] - 'A'] == flow)
					flow++;
				else {
					fail_flag = true;
					break;
				}
			}
		}
		if (!fail_flag)  answer++;
	}

	return answer;
}