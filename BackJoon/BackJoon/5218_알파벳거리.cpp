#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 
int main() {
	int N; 
	freopen("input_5218.txt", "r", stdin); 
	cin >> N; 
	for (int i = 0; i < N; i++) {
		string input1, input2; 
		cin >> input1 >> input2; 
		cout << "Distances:"; 
		for (int j = 0; j < input1.size(); j++) {
			if (input1[j] <= input2[j])	cout <<" "<< input2[j] - input1[j];
			else cout << " " << input2[j] + 26 - input1[j];
		}
		cout << "\n";
	}
}