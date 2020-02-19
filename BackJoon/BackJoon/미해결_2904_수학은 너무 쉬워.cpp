#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
int N; 
int max_score = 0, min_cnt = 987654321;
deque<int> s_num; 
bool check[500000]; 
int arr[500000]; 

void Find_Sosu() {
	for (int i = 2; i < 500000; i++) {
		if (!check[i]) { 
			for (int j = i + i; j < 500000; j += i)
				check[j] = true; 
		}
	}

	for (int i = 2; i < 500000; i++)
		if (!check[i])	s_num.push_back(i);
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N;
	int answer = 1, cnt = 0;
	deque<int> paper = deque<int>(N, 0);
	map<int, int> element_map[100];
	map<int,int> mok_map;
	map<int, int>::iterator it;
	map<int, int>::iterator it2;

	for(int i = 0; i < N; i++) {
		cin >> paper[i];
	}
	
	Find_Sosu();
	for (int i = 0; i < paper.size(); i++) {

		for (int j = 0; j < s_num.size(); j++) {
			if (s_num[j] > paper[i])	break;
			if (paper[i] % s_num[j] == 0) {
				paper[i] /= s_num[j];
				it = element_map[i].find(s_num[j]);
				if (it == element_map[i].end()) { // 해당 소수가 없을 경우 
					element_map[i].insert(make_pair(s_num[j], 1));
				}
				else {
					it->second++;
				}
				j = -1;
			}
		}
		

	}
	
	for (int i = 0; i < N; i++) {
		for (it = element_map[i].begin(); it != element_map[i].end(); it++) {
		//	cout << it->second << " ";
			it2 = mok_map.find(it->first);
			if (it2 == mok_map.end()) {
				mok_map.insert(make_pair(it->first, it->second));
			}
			else {
				it2->second += it->second;
			}
		}
		//cout << endl;
	}

	vector<pair<int, int>> v; 

	for (it2 = mok_map.begin(); it2 != mok_map.end(); it2++) {
		if (it2->second % N == 0) {
			answer = answer * (it2->second) / N * it2->first;
			v.push_back({ it2->first, it2->second/N });
		}
	}
	


	for (int i = 0; i < N; i++) {
		
		for (it = element_map[i].begin(); it != element_map[i].end(); it++) {

			for (int j = 0; j < v.size(); j++) {
				if (v[j].first == it->first) {
					if (v[j].second < it->second)
						cnt += (it->second - v[j].second);
					break; 
				}
			}
		}

	}
	cout << answer<<" "<<cnt << "\n";
	
}