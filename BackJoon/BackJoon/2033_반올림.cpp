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
//			if (input[size - digit] >= '5') { // �ݿø��� �ؾ��ϴ� ��� 
//				input[size - digit] = '0';
//				digit++;
//				
//				while ( input[size - digit] == '9') { // �ݿø� ���� �� 1�� �������Ѿ� �ϴ� �ڸ� �� ã��
//					input[size - digit] = '0'; 
//					digit++;
//					if (digit == size + 1)	break;
//				}
//				if (digit == size + 1)	input = "1" + input;  // �Է� ���ں��� ū ���� �ø� 
//				else input[size - digit] = (input[size - digit] - '0' + 1) + '0'; // �ش� �ڸ� �ø�
//				continue; 
//			}
//			input[size - digit] = '0'; // ����
//			digit++;
//		}
//		cout << input << "\n";
//	}
//}