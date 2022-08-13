#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000001

char input[MAX_SIZE]; // 입력받을 문자열
int len;
int arr[26] = { 0 }; // a to z array A:65, a:97, Z:90, z;128
int answer;
int idx = 0;
int flag = 0;

int main() {

	scanf("%s",&input);
	len = strlen(input);
	for (int i = 0; i < len; i++) {
		if (input[i] > 96) { // 대문자라면
			arr[(input[i] - 32 - 65)]++;
		}
		else { // 소문자라면
			arr[input[i] - 65]++;
		}
	}


	// 가장 큰 개수 구하고 출력 처리

	answer = arr[0];
	for (int i = 1; i < 26; i++) {
		if (answer < arr[i]) {
			answer = arr[i];
			idx = i;
		}
	}

	for (int i = 1; i < 26; i++) {
		if (i != idx &&answer == arr[i]) { // idx 를 제외하고 같은 개수가 존재하면
			flag = 1;
		}
	}

	if (flag) {
		printf("?");
	}
	else {
		printf("%c", idx+65);
	}

	return 0;
}