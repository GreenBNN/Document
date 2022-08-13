#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 50

int main() {
	int h, w;
	char arr[MAX_SIZE][MAX_SIZE];
	char temp;
	int cnt = 0;
	int cnt2 = 0;
	int answer = 999;

	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; i++) {
			scanf("%s", &arr[i]);
	}
	
	for (int i = 0; i < h - 7; i++) {
		for (int j = 0; j < w - 7; j++) {
			cnt = 0;
			cnt2 = 0;
			for (int a = i; a < i + 8; a++) {
				for (int b = j; b < j + 8; b++) {
					if ((a + b) % 2 == 0) { // Â¦¼ö
						if (arr[a][b] == 'B')
							cnt++;
						else
							cnt2++;
					}
					else { // È¦¼ö
						if (arr[a][b] == 'B')
							cnt2++;
						else
							cnt++;
					}
				}
			}
			if (answer > cnt)
				answer = cnt;
			if (answer > cnt2)
				answer = cnt2;	
		}
	}

	printf("%d\n", answer);
	return 0;
}