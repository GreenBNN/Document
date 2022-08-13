#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int num;
	char name[10];
	char cmd[10];
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s %s", &name, &cmd);
		printf("%s %s\n", name, cmd);
	}

	return 0;
}