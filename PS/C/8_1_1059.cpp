#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int L;
	int n;
	int result = 0;

	cin >> L;
	vector<int> S(L);

	// vector<int> vec; 
	// ¿Ã»ƒ vec.push_back(a);
	

	for (int i = 0; i < L; i++) {
		cin >> S[i];
	}
	sort(S.begin(), S.end());

	cin >> n;

	int l;
	int h;
	for (int i = 0; i < L; i++) {
		if (S[i] >= n) {
			l = S[i - 1];
			h = S[i];
			break;
		}
	}
	if (n == h) {
		cout << result;
	}
	else {
		int left_num = (n - l - 1) * (h - n);
		result += left_num;
		result += h - n - 1;
		cout << result;
	}
	return 0;
}