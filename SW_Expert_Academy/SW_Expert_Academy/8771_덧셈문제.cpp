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
//		long long N, A, B, min_num, max_num; // �� long long ���� �ؾ��Ѵ� !! 
//		cin >> N >> A >> B;
//		cout << "#" << t << " ";
//		if (A > B)	cout << "0\n"; // ���� ���� ū������ Ŭ ��� ( �Ұ����� ��� )
//		else if (A == B)	cout << "1\n"; // ���� N ���� ��� A �� ��� �� ���ϸ� 1���� ����� �� 
//		else {
//			if (N == 1) { // A �� B �� �ٸ��Ƿ� �ּ� N �� 2 �̻��̾�� �� 
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