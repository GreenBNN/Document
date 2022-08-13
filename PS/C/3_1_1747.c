#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*####### 소수 구하기 : 수가 작으면 arr 로 소수 구해놓기
				펠린드롭 수 (101) 찾기 #######*/

int arr[1004001] = { 0 }; // 0 은 소수 1 은 소수X

int reverse(int num) {
	int reverse = 0;
	while (num != 0) {
		reverse = reverse * 10 + num % 10;
		num /= 10;
	}
	return reverse;
}

int main() {
	int num;
	int result;

	arr[1] = 1;
	for (int i = 2; i < 1021; i++) {
		if (arr[i]==0) {
			for (int j = i + i; j < 1004001;) {
				arr[j] = 1;
				j = j + i;
			}
		}
	}
	
	for (int i = 9; i < 1004001; i++) {
		if (arr[i] == 0 ) { // 소수이면서 팰린드롭 찾기
			if (i != reverse(i)) {
				arr[i] = 1;
			}
		}
	}
	
	scanf("%d", &num);

	for (int i = 1; i < 1004001; i++) {
		if ( arr[i] == 0 && i >= num) {
			result = i;
			break;
		}
	}
	

	printf("%d", result);
	return 0;
}