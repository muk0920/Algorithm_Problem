// 1�� Ǯ�� - set �� �̿��Ͽ� �ߺ� ó���� Ȱ�� 
#include <string>
#include <vector>
#include <math.h>
#include <set>

using namespace std;
set<long long> check;
vector<long long>num[9];

void Put_Data(int od, int val) { // true �ߺ� �� ���� , false �ߺ� �� x 
	if (check.find(val) == check.end()) {
		num[od].push_back(val);
		check.insert(val);
	}
}

int solution(int N, int number) {
	int answer = 0;
	for (int i = 1; i <= 8; i++) { // ���޾� ���� ����. ex) 22, 222, 
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

					// + ���� 
					Put_Data(i, n1 + n2);
					if (n1 + n2 == number) return i;

					// - ���� 
					Put_Data(i, n2 - n1);
					if (n2 - n1 == number) return i;
					Put_Data(i, n1 - n2);
					if (n1 - n2 == number) return i;

					// ���ϱ� ���� 
					Put_Data(i, n1*n2);
					if (n1*n2 == number) return i;

					// ������ ���� 
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
//// 2�� Ǯ�� - 2���� Set �� �̿��Ͽ� ó��. 
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
					// + ���� 
					check[i].insert(n1 + n2);
					// - ���� 
					check[i].insert(n1 - n2);
					check[i].insert(n2 - n1);
					// ���ϱ� ���� 
					check[i].insert(n1*n2);
					// ������ ���� 
					check[i].insert(n1 / n2);
					check[i].insert(n2 / n1);
				}
				if (check[i].find(number) != check[i].end())    return i;
			}
		}
	}
	return -1;
}