#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int input;
int find;
int temp;
int cnt=0;
int a, b; // ab
int flag = 0;

int main() {
	
	scanf("%d", &input);
	if (input == 0)
		cnt = 1;
	while (find != input)
	{
		if (!flag) {
			a = input / 10; // 10�� �ڸ� ��
			b = input % 10; // 1�� �ڸ� ��

			temp = a + b;
			flag = 1;

		}
		else {
			find = b * 10 + temp % 10;

			a = find / 10; // 10�� �ڸ� ��
			b = find % 10; // 1�� �ڸ� ��

			temp = a + b;
			cnt++;
		}
	}
	printf("%d", cnt);
	

	return 0;
}