#include<iostream>
#include<vector>
#include<algorithm>

// 회의의수 N 개
// 시작시간, 종료시간 주어짐
// 가장 많은 회의를 할 수 있도록 배치
// 회의의 개수는?

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}


int main() {
	int N;

	cin >> N;
	vector<pair<long, long>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp); // 끝나는 시간으로 오름차순
	

	int cnt = 1;
	int pre = v[0].second;
	for (int i = 1; i < N; i++) {
		if (pre <= v[i].first) { // 회의 시작 가능하면 ㄱㄱ
			cnt++;
			pre = v[i].second;
		}
	}

	printf("%d", cnt);

	return 0;
}