#include <iostream>
#include <queue>
using namespace std;

int N; // ���� ����
int input; // �ڿ����� �߰� 0 �̸� min �� ���, ����


// ------------- set���� �غ��� -> �ߺ� ��� �ȵǴϱ� �ȵ� 
//set<int> s;


// ------------- �켱���� queue �� ���� ������ ��������
priority_queue<int, vector<int>, greater<int>> s; // �ø���������

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 0 ) {
			if (s.size() == 0) { // �������
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