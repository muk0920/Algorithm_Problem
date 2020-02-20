#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std; 
int a, b, c, d; 

// �ִ� ����� ���ϴ� ���� - ��Ŭ���� ȣ����  
int gcd(long long a, long long b) {
	while (b > 0) {
		long long temp = a; 
		a = b; 
		b = temp%b; 
	}
	return a; 

}
// �ּ� ����� ���ϴ� ���� - ��Ŭ���� ȣ���� 
long long lcm(long long a, long long b) {
	return (a*b) / gcd(a, b); 
}

int main() {
	cin >> a >> b >> c >> d; 
	long long denominator; //  �и� 
	long long numerator; // ���� 
	int gcd_num; 

	if (b != d) {
		denominator = b*d;
		numerator = a*d + b*c;
	}
	else {
		denominator = b; 
		numerator = a + c; 
	}

	gcd_num = gcd(denominator, numerator); 

	cout << numerator/gcd_num << " " << denominator/gcd_num << "\n";
}