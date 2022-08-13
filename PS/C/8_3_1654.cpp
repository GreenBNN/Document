#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int k;
	long long n;

	cin >> k >> n;

	vector<int> S(k);
	
	for (int i = 0; i < k; i++) {
		cin >> S[i];
	}
	
	sort(S.begin(), S.end());

	long long l = 1;
	long long h = S[k - 1];


	while (l <= h) {
		long long mid = (l + h) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += S[i] / mid;
		}

		if (cnt < n) { // 자른 것이 적으면 더 잘게 잘라야함
			h = mid-1;
		}
		else {
			l = mid+1;
		}

	}

	cout << l-1 << endl;

	return 0;
}