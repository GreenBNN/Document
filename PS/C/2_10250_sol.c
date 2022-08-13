#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*####### 문자열 입력받기, 스택 #######*/

int main() {
	int testNum;
	int h, w, n;
	int num1 = 0;
	int num2 = 1;
	int sum = 0;
	scanf("%d", &testNum);
	
	for (int i = 0; i < testNum; i++) {
		scanf("%d %d %d", &h, &w, &n);

		for (int i = 0; i < n; i++) {
			num1 += 100;
			if (num1 > 100 * h) {
				num1 = 100;
				num2 += 1;
			}
		}

		printf("%d\n", num1 + num2);
		num1 = 0;
		num2 = 1;

	}
	
	

	return 0;
}
