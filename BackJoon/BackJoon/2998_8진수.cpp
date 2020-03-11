#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std; 
map<string, string> octal; 
int main() {
	// ÃÖÀûÈ­
	octal["000"] = "0";
	octal["001"] = "1";
	octal["010"] = "2";
	octal["011"] = "3";
	octal["100"] = "4";
	octal["101"] = "5";
	octal["110"] = "6";
	octal["111"] = "7";

	string input, answer=""; 
	cin >> input; 
	while (input.size() % 3) {
		input = '0' + input; 
	}

	for (int i = 0; i < input.size() - 2; i+=3) {
		string temp = input.substr(i, 3);
		answer = answer + octal[temp];
	}

	cout << answer<<"\n"; 
}