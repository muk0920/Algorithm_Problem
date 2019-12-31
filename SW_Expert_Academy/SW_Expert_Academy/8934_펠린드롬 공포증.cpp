//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int tc;
//	cin >> tc;
//
//	for (int t = 1; t <= tc; t++) {
//		string input;
//		cin >> input;
//		int arr[3] = { 0, };
//		bool answer = true;
//		int min = 1000000;
//
//		for (int i = 0; i < input.size(); i++)	arr[input[i] - 'a']++; // 'a','b','c' 의 개수 파악
//
//		for (int i = 0; i < 3; i++) if (min > arr[i])	min = arr[i]; // 세 개의 알파벳 중 최소 개수 파악
//
//		for (int i = 0; i < 3; i++)	arr[i] -= min; // 최소 사이클 차감 
//
//		for (int i = 0; i < 3; i++) if (arr[i] >= 2)	answer = false;
//
//		cout << "#" << t << " " << (answer ? "YES\n" : "NO\n");
//	}
//
//}