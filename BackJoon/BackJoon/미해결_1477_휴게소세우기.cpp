#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int N, M, load, ans;
vector<int> rest, len_vec; 

bool Check_Rest(int dist) {
	int cnt = 0; 
	for (int i = 0; i < len_vec.size(); i++) {
		cnt += len_vec[i] / dist; 
		if (len_vec[i] % dist == 0)	cnt -= 1;
	}
	if (cnt >= M)	return true;
	
	return false; 
}
bool isComp(int a, int b) {
	return a < b; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	freopen("input_1477.txt", "r", stdin);
	int low = 0, high = 1000, mid; 
	cin >> N >> M >> load; 
	rest = vector<int>(N, 0); 
	for (int i = 0; i < N; i++) 	cin >> rest[i];  // 휴게소 위치 입력받기
	rest.push_back(0), rest.push_back(load);
	sort(rest.begin(), rest.end()); 
	for (int i = 0; i < rest.size() - 1; i++)
		len_vec.push_back(rest[i + 1] - rest[i]); 
	sort(len_vec.begin(), len_vec.end(), isComp); 

	while (low < high) {

		mid = (low + high) / 2; 
		if (Check_Rest(mid)) {
			low = mid + 1; 
		}
		else {
			high = mid - 1; 
		}
	}
	cout << mid<<"\n"; 
}