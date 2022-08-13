#include<iostream>
#include<vector>
#include<algorithm>

// ȸ���Ǽ� N ��
// ���۽ð�, ����ð� �־���
// ���� ���� ȸ�Ǹ� �� �� �ֵ��� ��ġ
// ȸ���� ������?

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
	sort(v.begin(), v.end(), cmp); // ������ �ð����� ��������
	

	int cnt = 1;
	int pre = v[0].second;
	for (int i = 1; i < N; i++) {
		if (pre <= v[i].first) { // ȸ�� ���� �����ϸ� ����
			cnt++;
			pre = v[i].second;
		}
	}

	printf("%d", cnt);

	return 0;
}