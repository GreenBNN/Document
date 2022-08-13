#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100001

int main() {

	int num;
	int cnt = 1;
	int temp;
	int arr[MAX_SIZE];

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}                         

	temp = arr[num-1];
	for (int i = num-2 ; i >= 0; i--) {
		if (arr[i] > temp) {
			cnt++;
			temp = arr[i];
		}
	}
	printf("%d", cnt);

	return 0;
}