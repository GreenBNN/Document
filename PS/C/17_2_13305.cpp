#include<iostream>
#include<vector>
#include<algorithm>

// N ���� ���ð� ���������� �ִ�
// ���� ���ʿ��� ���������� �̵�
// ���� ���ڸ� ���ʹ� �⸧ �����̸�
// 1km ���� 1 �⸧ �Ҹ�
// ���ʿ��� ���������� ���µ� ��� �⸧�� �ּ� ��� ��� 

using namespace std;

int main() {
	int N;

	cin >> N;
	
	vector<long long> d(N); // �Ÿ� ����
	vector<long long> v(N); // �⸧ ����
	for (int i = 0; i < N-1; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	long long sum = v[0]*d[0]; // ù��° ����ƮQ
	long long pre = v[0];
	for (int i = 1; i < N; i++) {
		if (v[i] < pre) { // ������ �� �θ� ���ݲ���
			sum += v[i] * d[i];
			pre = v[i];
		}
		else {
			sum += pre * d[i];
		}
	}

	cout << sum;

	return 0;
}