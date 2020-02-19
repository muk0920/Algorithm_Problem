#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc; 
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int denominator=2, numerator=1, input_num;
		string input="", tmp;
		cin >> tmp; 
		for (int i = 2; i < tmp.size(); i++)
			if (tmp[i] >= '0' && tmp[i] <= '9')	input += tmp[i];
		
		cout.precision(7);
	

		cout << 43.0 / 70.0 << "\n";

		cout << input << "\n";
	}
}