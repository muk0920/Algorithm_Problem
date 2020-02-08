#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std; 
int N, top_idx=0; 
int stack_arr[100001];

int isEmpty() {
	if (top_idx == 0)	return 1;
	else return 0; 
}

void Push(int num) {
	stack_arr[++top_idx] = num;
}

int Pop() {
	int num; 
	if (top_idx == 0)	return -1; 
	num = stack_arr[top_idx--];
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input.txt", "r", stdin);
	cin >> N; 
	for (int i = 0; i < N; i++) {
		string str;
		int number; 
		cin >> str; 
		if (str == "push") {
			cin >> number;
			Push(number);
		}
		else if (str == "top") {
			if (top_idx == 0)	cout << "-1\n";
			else cout << stack_arr[top_idx] << "\n";
		}
		else if (str == "pop") {
			cout<<Pop()<<"\n";
		}
		else if (str == "empty") {
			cout << isEmpty() << "\n";
		}
		else if (str == "size") {
			cout << top_idx <<"\n";
		}
	}
}