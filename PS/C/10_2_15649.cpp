// 자연수 N, M 이 주어졌을 때 
// 조건을 만족하는 길이가 M 인 수열 구하기
// 1부터 N 까지 M 개 = 수열 출력 순서O 중복X

// 순열의 모든 경우의 수에서 구해보자
// 4P4 = 4P3 이다
// 4P2 부터 달라지며 (4-2)! 로 나눈 개수이고 
// 순열 전체로 보았을 때 하나 건너띄운 것을 선택한다.

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