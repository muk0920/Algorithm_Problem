//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int tc;
//	cin >> tc;
//	for (int t = 1; t <= tc; t++) {
//		long long N, A, B, min_num, max_num; // 꼭 long long 으로 해야한다 !! 
//		cin >> N >> A >> B;
//		cout << "#" << t << " ";
//		if (A > B)	cout << "0\n"; // 작은 수가 큰수보다 클 경우 ( 불가능한 경우 )
//		else if (A == B)	cout << "1\n"; // 숫자 N 개가 모두 A 일 경우 다 더하면 1가지 경우의 수 
//		else {
//			if (N == 1) { // A 와 B 가 다르므로 최소 N 은 2 이상이어야 함 
//				cout << "0\n";
//			}
//			else if (N == 2)	cout << "1\n";
//			else {
//				if (A == B)	cout << "1\n";
//				else {
//					min_num = A*(N - 1) + B;
//					max_num = A + B*(N - 1);
//					cout << max_num - min_num + 1 << "\n";
//				}
//			}
//		}
//	}
//}