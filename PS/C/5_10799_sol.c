#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*####### ���ڿ� �Է¹ޱ�, ����
			�������� ����� ������ () #######*/


int B = 0; // �����
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
			if (prec == '(') { // ������
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