#include <iostream>
#include <string>
#include <set>
using namespace std;

int N; //문자열 개수
int M; // 검사할 문자열 개수
int cnt = 0; // 있는 문자열 count
set<string> s;

string input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		s.insert(input);
	}

	for (int i = 0; i < M; i++) {
		cin >> input;
		if (s.find(input) != s.end()) {
			cnt++;
		}
	}

	cout << cnt;



	return 0;
}
