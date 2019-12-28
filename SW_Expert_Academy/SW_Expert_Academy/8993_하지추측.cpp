#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Check(long long num) {
	while (num > 1) {
		if (num % 2 == 0)	num /= 2;
		else	return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		long long input;
		bool answer;
		cin >> input;
		answer = Check(input);
		cout << "#" << t << " " << (answer ? "YES" : "NO") << "\n";
	}
}