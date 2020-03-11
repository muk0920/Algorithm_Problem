// ���ڰ� �����ؼ� ������ ������ �� ���� �� -> ERROR 
// 0���� ������ ��, (DIV, MOD ) -> ERROR 
// ���밪�� 10^9 �� �Ѿ�� -> ERROR 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
#include <memory.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input_3425.txt", "r", stdin);
	string input;
	int N, num;
	deque<string> op;
	deque<long long> num_dq;  // NUM ��ɾ� ���ڸ� ������ ��ɾ�. 

	while (true) {
		cin >> input;
		if (input == "QUIT") break;
		else if (input == "NUM") {
			long long temp;
			cin >> temp;
			op.push_back(input);
			num_dq.push_back(temp);
		}
		else if (input == "END") {
			cin >> N;
			for (int i = 0; i < N; i++) { // ���� ó�� 
				cin >> num;
				stack<long long> gostack;
				int num_idx = 0;
				bool error_flag = false;
				gostack.push(num);

				for (int j = 0; j < op.size(); j++) {
					if (op[j] == "NUM") {
						if (num_idx >= num_dq.size())
							error_flag = true;
						else
							gostack.push(num_dq[num_idx++]);
					}
					else if (op[j] == "POP") {
						if (gostack.empty())
							error_flag = true;
						else
							gostack.pop();
					}
					else if (op[j] == "INV") {
						if (gostack.empty()) {
							error_flag = true;
						}
						else {
							long long temp = gostack.top();
							gostack.pop();
							gostack.push(temp*-1);
						}
					}
					else if (op[j] == "DUP") {
						if (gostack.empty()) {
							error_flag = true;
						}
						else
							gostack.push(gostack.top());
					}
					else if (op[j] == "SWP") {
						if (gostack.size() < 2)
							error_flag = true;
						else {
							long long temp = gostack.top();
							gostack.pop();
							long long temp2 = gostack.top();
							gostack.pop();
							gostack.push(temp);
							gostack.push(temp2);
						}
					}
					else if (op[j] == "ADD") {
						if (gostack.size() < 2)
							error_flag = true;
						else {
							long long sum = gostack.top();
							gostack.pop();
							sum += gostack.top();
							gostack.pop();
							if (abs(sum) > 1000000000)	error_flag = true;
							gostack.push(sum);
						}
					}
					else if (op[j] == "SUB") {
						if (gostack.size() < 2)
							error_flag = true;
						else {
							long long sub = gostack.top();
							gostack.pop();
							sub = sub - gostack.top();
							gostack.pop();
							if (abs(sub) > 1000000000)	error_flag = true;
							gostack.push(sub);
						}
					}
					else if (op[j] == "MUL") {
						if (gostack.size() < 2)
							error_flag = true;
						else {
							int mul = gostack.top();
							gostack.pop();
							int mul2 = gostack.top(); 
							if (abs(mul) > 100000 && abs(mul2) > 100000) {
								error_flag = true;
								break;
							}
							gostack.pop();
							if (abs(mul) > 1000000000) {
								error_flag = true;
								break;
							}
							gostack.push(mul);
						}
					}
					else if (op[j] == "DIV") {
						if (gostack.size() < 2)
							error_flag = true;
						else {
							int plus_cnt = 0;
							long long temp = gostack.top();
							gostack.pop();
							if (temp < 0) {
								plus_cnt++;
								temp *= -1;
							}
							long long div = gostack.top();
							gostack.pop();
							if (div < 0) {
								plus_cnt++;
								div *= -1;
							}
							if (temp == 0) {
								error_flag = true;
								break;
							}
							div = div / temp;
							if (plus_cnt == 1)	div *= -1;
							gostack.push(div);
						}
					}
					else if (op[j] == "MOD") {
						if (gostack.size() < 2)
							error_flag = true;
						else {
							long long temp = gostack.top();
							bool div_plus = true; 
							gostack.pop();
							if (temp < 0) {
								temp *= -1;
							}
							long long div = gostack.top();
							gostack.pop();
							if (div < 0) {
								div *= -1;
								div_plus = false; 
							}
							if (temp == 0) {
								error_flag = true;
								break;
							}
							div = div % temp;
							if (!div_plus) div *= -1; // �����ϰ�� �������� ��ȣ�� ������ 
							gostack.push(div);
						}
					}

					if (error_flag)	break;
				}

				if (gostack.size() != 1 || error_flag)	cout << "ERROR\n";
				else cout << gostack.top() << "\n";
			}
			// �ʱ�ȭ
			op.clear();
			num_dq.clear();
			cout << "\n";
		}
		else {
			op.push_back(input);
		}
	}


}