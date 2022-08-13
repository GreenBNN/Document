#include <iostream>
#include <string>
#include <set>
using namespace std;

int N; //���ڿ� ����
int M; // �˻��� ���ڿ� ����
int cnt = 0; // �ִ� ���ڿ� count
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
