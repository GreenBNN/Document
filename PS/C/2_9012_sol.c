#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int testNum;
	char temp;
	char arr[51];
	int cnt = 0;
	int len;

	scanf("%d", &testNum);

	for (int i = 0; i < testNum; i++) {
		scanf("%s", &arr);
		len = strlen(arr);
		for (int j = 0; j < len; j++) {
			if (arr[j] == '(') {
				if (cnt <= 0)
					cnt--;
				else
					break;
			}
			else {
					cnt++;
			}
		}

		if (cnt == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		cnt = 0;
		
	}


	return 0;
}