#include <iostream>
#include <queue>
using namespace std;

int N; // 연산 개수
int input; // 자연수면 추가 0 이면 min 값 출력, 제거


// ------------- set으로 해보기 -> 중복 허용 안되니까 안됨 
//set<int> s;


// ------------- 우선순위 queue 로 구현 원래는 내림차순
priority_queue<int, vector<int>, greater<int>> s; // 올림차순으로

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 0 ) {
			if (s.size() == 0) { // 비었으면
				cout << 0;
				cout << '\n';
			}
			else {
				cout << s.top();
				cout << '\n';
				s.pop();
			}
			
		}
		else {
			s.push(input);
		}
	}

	return 0;
}