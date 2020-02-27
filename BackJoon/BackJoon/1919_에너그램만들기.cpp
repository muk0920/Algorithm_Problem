#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <math.h>
using namespace std; 
int main() {
	string input1, input2; 
	int arr1[26] = { 0, }; 
	int arr2[26] = { 0, }; 
	int ans = 0; 
	cin >> input1 >> input2;
	for (int i = 0; i < input1.size(); i++)
		arr1[input1[i] - 'a']++; 
	for (int i = 0; i < input2.size(); i++)
		arr2[input2[i] - 'a']++;

	for (int i = 0; i < 26; i++) {
		if (arr1[i] != arr2[i]) {
			ans += abs(arr1[i] - arr2[i]); 
		}
	}
	cout << ans << "\n"; 

}