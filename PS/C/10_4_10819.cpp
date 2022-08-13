// N ���� ������ ����
// �̿��ϴ� ������ �� ���밪 ��� ���� ���� �ִ밪 ���ϱ�
// N! ��� ��� ã�ƾ���

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N ; // ���� ����
int temp = 0; // �� ���� �� ����
int result; // ���ŵǴ� �ִ밪

int main() {
	cin >> N;

	vector<int> A(N);
	// vector<int> A;
	// A.push_back();


	for (int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	do {
		temp = 0;
		for (int i = 0; i < N-1; i++) {
			temp += abs(A[i + 1] - A[i]);
		}
		result = max(result, temp);

	} while (next_permutation(A.begin(), A.end()));

	printf("%d\n", result);

	return 0;
}