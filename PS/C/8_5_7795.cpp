#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	int N;
	int M;

	cin >> T ;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		vector<int> arrA(N);
		vector<int> arrB(M);
		for (int j = 0; j < N; j++) {
			cin >> arrA[j];
		}
		for (int j = 0; j < M; j++) {
			cin >> arrB[j];
		}

		sort(arrA.begin(), arrA.end());
		sort(arrB.begin(), arrB.end());

		int cnt = 0;
		for (int k = 0; k < N; k++) {
			for (int l = 0; l < M; l++) {
				if (arrA[k] > arrB[l]) {
					cnt++;
				}
				else 
					break;
			}
		}

		printf("%d\n", cnt);


	}

	

	return 0;
}