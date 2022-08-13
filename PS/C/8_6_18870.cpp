#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

    vector<int> copyArr(arr); // ���� ����
    sort(copyArr.begin(), copyArr.end()); 

	// unique �ߺ� �ڷ� ������, erase �ڷ� ���� �� �����
    copyArr.erase(unique(copyArr.begin(), copyArr.end()), copyArr.end());
    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(copyArr.begin(), copyArr.end(), arr[i]);
        cout << it - copyArr.begin() << ' ';
    }

	return 0;
}