#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*####### 창고 넓이 구하기, 수학 #######*/

int main() {
	int N,L,H;
	int arr[1001] = { 0, };
	int highest = 0;
	int highestPos = 0;
	int left= 1001, right = 0; // 맨 왼쪽, 오른쪽
	int answer = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &L, &H);
		arr[L] = H;
		if (highest < H) {
			highest = H;
			highestPos = L;
		}
		if (left > L) {
			left = L;
		}
		if (right < L) {
			right = L;
		}
	}
	
	int temp = 0;
	int cnt = 0;
	for (int i = left; i <= highestPos; i++) { // 왼쪽 계산
		cnt++;
		if (arr[i] >= temp) {
			answer += cnt * temp;
			cnt = 0;
			temp = arr[i];
		}
	}

	temp = 0;
	cnt = 0;
	for (int i = right; i >= highestPos; i--) { // 오른쪽 계산
		cnt++;
		if (arr[i] >= temp) {
			answer += cnt * temp;
			cnt = 0;
			temp = arr[i];
		}
	}
	answer += highest; // 제일 높은 기준 계산

	printf("%d", answer);
	return 0;
}