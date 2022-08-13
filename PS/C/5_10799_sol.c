#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*####### 문자열 입력받기, 스택
			레이저로 막대기 나누기 () #######*/


int B = 0; // 막대기
int answer = 0;

int main() {
	char c = getchar();
	char prec;
	int answer = 0;
	while (c != '\n') {
		if (c == '(') {
			B++;
		}
		else {
			B--;
			if (prec == '(') { // 레이저
				answer += B ;
			}
			else {
				answer++;
			}
		}
		prec = c;
		c = getchar();
	}

	printf("%d\n", answer);
	return 0;
}