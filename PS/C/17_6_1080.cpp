#include<iostream>
#include<vector>
#include<algorithm>

// 행렬의 크기 N M
// a 배열을 3X3 으로 뒤집어서 b 배열과 같아지도록 만들기
// 뒤집는 최소 횟수 출력, 같게 못만들면 -1 출력

using namespace std;


int N, M;
int a[51][51];
int b[51][51];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &b[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (a[i][j] != b[i][j]) { // 다르면 뒤집기
				for (int k = i; k <= i + 2; k++) {
					for (int l = j; l <= j + 2; l++) {
						a[k][l] = 1 - a[k][l]; // swap
					}
				}
				cnt += 1;
			}
			else
				continue;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;


	return 0;
}