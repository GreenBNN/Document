#include<iostream>
#include<vector>
#include<algorithm>

// N 개의 유제품
// 2+1 이라 3개씩 사서 가장 싼 것 공짜로 받음
// 최소 비용으로 N 개의 유제품 사기
// 비싼 것을 공짜로 받아야 함

using namespace std;



int main() {
	int N;

	cin >> N;
	vector <int> v(N);
	
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v[i] = temp*-1;
	}

	sort(v.begin(), v.end()); // 오름차순 

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (i % 3 != 2)
			sum += v[i]* -1;
	}

	printf("%d", sum);

	return 0;
}