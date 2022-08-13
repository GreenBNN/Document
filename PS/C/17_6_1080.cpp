#include<iostream>
#include<vector>
#include<algorithm>

// ����� ũ�� N M
// a �迭�� 3X3 ���� ����� b �迭�� ���������� �����
// ������ �ּ� Ƚ�� ���, ���� ������� -1 ���

using namespace std;


int N, M;
int a[51][51];
int b[51][51];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &b[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (a[i][j] != b[i][j]) { // �ٸ��� ������
				for (int k = i; k <= i + 2; k++) {
					for (int l = j; l <= j + 2; l++) {
						a[k][l] = 1 - a[k][l]; // swap
					}
				}
				cnt += 1;
			}
			else
				continue;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;


	return 0;
}