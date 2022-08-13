#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*####### â�� ���� ���ϱ�, ���� #######*/

int main() {
	int N,L,H;
	int arr[1001] = { 0, };
	int highest = 0;
	int highestPos = 0;
	int left= 1001, right = 0; // �� ����, ������
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
	for (int i = left; i <= highestPos; i++) { // ���� ���
		cnt++;
		if (arr[i] >= temp) {
			answer += cnt * temp;
			cnt = 0;
			temp = arr[i];
		}
	}

	temp = 0;
	cnt = 0;
	for (int i = right; i >= highestPos; i--) { // ������ ���
		cnt++;
		if (arr[i] >= temp) {
			answer += cnt * temp;
			cnt = 0;
			temp = arr[i];
		}
	}
	answer += highest; // ���� ���� ���� ���

	printf("%d", answer);
	return 0;
}