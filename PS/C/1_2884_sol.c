#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int h;
	int m;

	scanf("%d %d", &h, &m);

	if (m >= 45) {
		m -= 45;
	}
	else {
		h -= 1;
		m = 60 - (45 - m);

		if (h == -1) {
			h = 23;
		}
	}

	printf("%d %d", h, m);

	return 0;
}