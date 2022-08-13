// �ڿ��� N, M �� �־����� �� 
// ������ �����ϴ� ���̰� M �� ���� ���ϱ�
// 1���� N ���� M �� = ���� ��� ����O �ߺ�X

// ������ ��� ����� ������ ���غ���
// 4P4 = 4P3 �̴�
// 4P2 ���� �޶����� (4-2)! �� ���� �����̰� 
// ���� ��ü�� ������ �� �ϳ� �ǳʶ�� ���� �����Ѵ�.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int M;
int temp = 1;
int cnt = 0;

void permutation(vector<int>& set, int n, int r) {
	temp = N - M;
	int temp2 = 1;
	for (int i = temp; i > 0; i--) {
		temp2 *= i;
	}

	do {
		if (cnt % temp2 == 0) {
			for (int i = 0; i < r; i++) {
				cout << set[i] << ' ';
			}
			cout << '\n';
		}
		cnt++;
	} while (next_permutation(set.begin(), set.end()));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		A[i] = i + 1;
	}
	
	permutation(A, N, M);
	

	return 0;
}