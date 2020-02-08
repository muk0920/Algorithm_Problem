#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int N , head=1, tail=0;
int queue_arr[10001]; 

void Push(int num) {
	queue_arr[++tail] = num; 
}

bool isEmpty() {
	if (head == tail + 1) return true;
	else return false;
}


int Pop() {
	int temp;
	if (isEmpty())	return -1; 
	temp = queue_arr[head++];
	return temp;
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
		else if (str == "pop") {
			cout << Pop() << "\n";
		}
		else if (str == "empty") {
			cout << isEmpty() << "\n";
		}
		else if (str == "size") {
			cout << tail-head+1 << "\n";
		}
		else if (str == "front"){
			if(head == tail+1)
				cout << "-1\n";
			else 
				cout << queue_arr[head] << "\n";
		}
		else if (str == "back") {
			if (isEmpty())	
				cout << "-1\n";
			else
				cout << queue_arr[tail] << "\n";
		}
	}
}