#include<iostream>
#include<vector>
#include<algorithm>

// N ���� ����ǰ
// 2+1 �̶� 3���� �缭 ���� �� �� ��¥�� ����
// �ּ� ������� N ���� ����ǰ ���
// ��� ���� ��¥�� �޾ƾ� ��

using namespace std;



int main() {
	int N;

	cin >> N;
	vector <int> v(N);
	
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v[i] = temp*-1;
	}

	sort(v.begin(), v.end()); // �������� 

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (i % 3 != 2)
			sum += v[i]* -1;
	}

	printf("%d", sum);

	return 0;
}