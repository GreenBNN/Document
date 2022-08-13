#include <stdio.h>
#include <math.h>

int main() {
	int up, down, height;
	int result = 0;
	int temp;
	scanf("%d %d %d", &up, &down, &height);

	/*if (height <= up) {
		result = 1;
	}
	else {
		if ((height - up) % (up - down) == 0) {
			temp = (height - up) / (up - down);
		}
		else {
			temp = (height - up) / (up - down) + 1;
		}
		result = temp + 1;
		
	}*/

	
	result = ceil((double)(height - down) / (double)(up-down));

	printf("%d", result);
	return 0;
}