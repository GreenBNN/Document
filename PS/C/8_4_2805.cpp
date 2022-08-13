#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long N;
	long long M;

	cin >> N >> M;

	vector<long long> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	long long L = 1;
	long long H = arr[N - 1];
	long long sum = 0;
	while (L <= H) {
		long long midValue = (L + H) / 2;
		sum = 0;
		for (int i = 0; i < N; i++) { // sum 으로 자른 부분 구하기
			if (midValue < arr[i]) {
				sum += arr[i] - midValue;
			}
		}
		if (sum < M) {
			H = midValue - 1;
		}
		else {
			L = midValue + 1;
		}
	}

	cout << L - 1 <<endl;


	return 0;
}