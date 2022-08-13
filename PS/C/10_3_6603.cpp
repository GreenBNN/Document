// K���� ���Ұ� �ִ� ����S
// S �� �����߿��� 6���� ���� ����� �� > ������ ��� X
// next,prev_permutation ���µ� <bool> �Ἥ ���� ��� X ���

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