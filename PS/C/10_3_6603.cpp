// K개의 원소가 있는 집합S
// S 의 원소중에서 6개를 뽑은 경우의 수 > 순서는 상관 X
// next,prev_permutation 쓰는데 <bool> 써서 순서 상관 X 사용

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 


int main() {
	while (1) {
		int K;
		cin >> K;
		if (K == 0) {
			return 0;
		}
		vector<int> v(K);
		vector<bool> use(K);

		for (int i = 0; i < 6; i++) {
			use[i] = 1;
		}
		for (int i = 0; i < K; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		do {
			for (int i = 0; i < K; i++) {
				if (use[i]) {
					cout << v[i] << " ";
				}
			}
			cout << "\n";
		} while (prev_permutation(use.begin(), use.end()));
		cout << '\n';
	}

	return 0;
}