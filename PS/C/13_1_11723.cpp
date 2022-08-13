#include <iostream>
#include <string>
#include <set>
using namespace std;


set<int> allSet = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M; // 연산 개수
	string op; // 명령어
	int num; // 숫자

	set<int> s; // 집합

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> op;
		if(op == "add") {
			cin >> num;
			s.insert(num);
		}
		else if (op == "remove") {
			cin >> num;
			s.erase(num);
		}
		else if (op == "check") {
			cin >> num;
			if (s.find(num) != s.end()) { // 존재
				cout << 1;
				cout << '\n';
			}
			else {
				cout << 0;
				cout << '\n';
			}
		}
		else if (op == "toggle") {
			cin >> num;
			if (s.find(num) != s.end()) {
				s.erase(num);
			}
			else {
				s.insert(num);
			}
		}
		else if (op == "all") {
			s = allSet;
		}
		else { // empty
			s.clear();
		}
			
	}

	return 0;
}