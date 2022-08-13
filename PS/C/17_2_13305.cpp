#include<iostream>
#include<vector>
#include<algorithm>

// N 개의 도시가 일직선으로 있다
// 가장 왼쪽에서 오른쪽으로 이동
// 원의 숫자를 리터당 기름 가격이며
// 1km 마다 1 기름 소모
// 왼쪽에서 오른쪽으로 가는데 드는 기름의 최소 비용 계산 

using namespace std;

int main() {
	int N;

	cin >> N;
	
	vector<long long> d(N); // 거리 저장
	vector<long long> v(N); // 기름 저장
	for (int i = 0; i < N-1; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	long long sum = v[0]*d[0]; // 첫번째 디폴트Q
	long long pre = v[0];
	for (int i = 1; i < N; i++) {
		if (v[i] < pre) { // 지금이 더 싸면 지금꺼로
			sum += v[i] * d[i];
			pre = v[i];
		}
		else {
			sum += pre * d[i];
		}
	}

	cout << sum;

	return 0;
}