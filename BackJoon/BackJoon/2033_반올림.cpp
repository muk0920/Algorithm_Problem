//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std; 
//int main() {
//	string input;
//	cin >> input;
//	int num = atoi(input.c_str()), size = input.size(), digit = 1;
//	if (size == 1) {
//		cout << input << "\n";
//	}
//	else {
//		while (true) {
//			if (digit >= size) break;
//			if (input[size - digit] >= '5') { // 반올림을 해야하는 경우 
//				input[size - digit] = '0';
//				digit++;
//				
//				while ( input[size - digit] == '9') { // 반올림 했을 때 1을 증가시켜야 하는 자리 수 찾기
//					input[size - digit] = '0'; 
//					digit++;
//					if (digit == size + 1)	break;
//				}
//				if (digit == size + 1)	input = "1" + input;  // 입력 숫자보다 큰 수로 올림 
//				else input[size - digit] = (input[size - digit] - '0' + 1) + '0'; // 해당 자리 올림
//				continue; 
//			}
//			input[size - digit] = '0'; // 버림
//			digit++;
//		}
//		cout << input << "\n";
//	}
//}