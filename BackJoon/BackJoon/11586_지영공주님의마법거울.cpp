#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 
int N, mode; 
vector<string>  vec; 
int main() {
	freopen("input_11586.txt", "r", stdin);
	cin >> N; 
	vec = vector<string>(N, "");
	for (int i = 0; i < N; i++) {
		cin >> vec[i]; 
	}
	cin >> mode; 

	if (mode == 1) {
		for (int i = 0; i < N; i++)
			cout << vec[i] << "\n";
	}
	else if (mode == 2) {
		for (int i = 0; i < N; i++) {
			reverse(vec[i].begin(), vec[i].end());
			cout << vec[i] << "\n";
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			cout << vec[N - i - 1] << "\n";
		}
	}
}