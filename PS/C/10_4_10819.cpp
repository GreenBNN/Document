// N 개의 원소인 순열
// 이웃하는 원소의 차 절대값 모두 합한 것의 최대값 구하기
// N! 모든 경우 찾아야함

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N ; // 원소 개수
int temp = 0; // 각 시행 값 저장
int result; // 갱신되는 최대값

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