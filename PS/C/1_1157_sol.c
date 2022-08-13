#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000001

char input[MAX_SIZE]; // �Է¹��� ���ڿ�
int len;
int arr[26] = { 0 }; // a to z array A:65, a:97, Z:90, z;128
int answer;
int idx = 0;
int flag = 0;

int main() {

	scanf("%s",&input);
	len = strlen(input);
	for (int i = 0; i < len; i++) {
		if (input[i] > 96) { // �빮�ڶ��
			arr[(input[i] - 32 - 65)]++;
		}
		else { // �ҹ��ڶ��
			arr[input[i] - 65]++;
		}
	}


	// ���� ū ���� ���ϰ� ��� ó��

	answer = arr[0];
	for (int i = 1; i < 26; i++) {
		if (answer < arr[i]) {
			answer = arr[i];
			idx = i;
		}
	}

	for (int i = 1; i < 26; i++) {
		if (i != idx &&answer == arr[i]) { // idx �� �����ϰ� ���� ������ �����ϸ�
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