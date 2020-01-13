// 1번 풀이 - set 을 이용하여 중복 처리만 활용 
#include <string>
#include <vector>
#include <math.h>
#include <set>

using namespace std;
set<long long> check;
vector<long long>num[9];

void Put_Data(int od, int val) { // true 중복 값 존재 , false 중복 값 x 
	if (check.find(val) == check.end()) {
		num[od].push_back(val);
		check.insert(val);
	}
}

int solution(int N, int number) {
	int answer = 0;
	for (int i = 1; i <= 8; i++) { // 연달아 만든 숫자. ex) 22, 222, 
		int x = N;
		for (int k = 1; k<i; k++)
			x += pow(10, k)*N;

		Put_Data(i, x);
		if (x == number) return i;
	}

	for (int i = 2; i <= 8; i++) {
		for (int k = 1; k <= i / 2; k++) {
			if (num[k].empty())  continue;
			if (num[i - k].empty()) continue;

			for (int j = 0; j<num[k].size(); j++) {
				long long n1 = num[k][j];
				if (n1 == 0) continue;
				for (int m = 0; m<num[i - k].size(); m++) {
					long long n2 = num[i - k][m];
					if (n2 == 0) continue;

					// + 연산 
					Put_Data(i, n1 + n2);
					if (n1 + n2 == number) return i;

					// - 연산 
					Put_Data(i, n2 - n1);
					if (n2 - n1 == number) return i;
					Put_Data(i, n1 - n2);
					if (n1 - n2 == number) return i;

					// 곱하기 연산 
					Put_Data(i, n1*n2);
					if (n1*n2 == number) return i;

					// 나누기 연산 
					Put_Data(i, n2 / n1);
					if (n2 / n1 == number) return i;

					Put_Data(i, n1 / n2);
					if (n1 / n2 == number) return i;
				}
			}
		}
	}
	return -1;
}
//// 2번 풀이 - 2차원 Set 을 이용하여 처리. 
#include <string>
#include <vector>
#include <math.h>
#include <set>
#include <algorithm> 

using namespace std;
set<long long> check[9];
set<long long>::iterator it;
set<long long>::iterator it2;

int solution(int N, int number) {
	int answer = 0;
	vector<long long>num[9];

	for (int i = 1; i <= 8; i++) {
		int x = N;
		for (int k = 1; k<i; k++)     x += pow(10, k)*N;
		check[i].insert(x);
	}

	for (int i = 2; i <= 8; i++) {
		for (int k = 1; k <= i / 2; k++) {
			if (check[k].empty())  continue;
			if (check[i - k].empty()) continue;

			for (it = check[k].begin(); it != check[k].end(); it++) {
				long long n1 = *it;
				if (n1 == 0) continue;
				for (it2 = check[i - k].begin(); it2 != check[i - k].end(); it2++) {
					long long n2 = *it2;
					if (n2 == 0) continue;
					// + 연산 
					check[i].insert(n1 + n2);
					// - 연산 
					check[i].insert(n1 - n2);
					check[i].insert(n2 - n1);
					// 곱하기 연산 
					check[i].insert(n1*n2);
					// 나누기 연산 
					check[i].insert(n1 / n2);
					check[i].insert(n2 / n1);
				}
				if (check[i].find(number) != check[i].end())    return i;
			}
		}
	}
	return -1;
}