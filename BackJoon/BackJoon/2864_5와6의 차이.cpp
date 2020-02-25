#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
using namespace std;

int main() {
	string a, b, max_a, max_b, min_a, min_b; 
	cin >> a >> b; 
	max_a = a, min_a = a; 
	max_b = b, min_b = b; 

	for (int i = 0; i<a.size(); i++) {
		if (max_a[i] == '5')
			max_a[i] = '6';
	}

	for (int i = 0; i<a.size(); i++) {
		if (max_b[i] == '5')
			max_b[i] = '6';
	}

	for (int i = 0; i<b.size(); i++) {
		if (min_a[i] == '6')
			min_a[i] = '5';
	}

	for (int i = 0; i<b.size(); i++) {
		if (min_b[i] == '6')
			min_b[i] = '5';
	}

	int max_num = atoi(max_a.c_str()) + atoi(max_b.c_str()); 
	int min_num = atoi(min_a.c_str()) + atoi(min_b.c_str()); 

	cout << min_num << " " << max_num << "\n"; 
}