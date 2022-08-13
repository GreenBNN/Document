#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*####### 최대공약수 유클리드 호제법 / 정수론
			반지름 N 의 원에 N 개의 관중석 #######*/

int arr[2001][2001] = { 0, };

int gcd(int, int);
int main() {
	int D1, D2;
	int cnt = 0;
	scanf("%d %d", &D1, &D2);
	if (D1 > D2) {
		int temp = D1;
		D1 = D2;
		D2 = temp;
	}
	
	int a = 0;
	int b = 0;

	for (int i = D1; i <= D2; i++) {
		for (int j = 1; j <= i; j++) {

			/*if (i % j == 0) { 
				a = 1;
				b = (i / j);
			}
			else {
				for (int k = j / 2; k > 0; k--) {
					if (j % k == 0 && i % k == 0) {
						a = (j / k);
						b = (i / k);
						break;
					}
				}
			}*/
			int N = gcd(j, i);
			a = j / N;
			b = i / N;

			if (arr[a][b] == 0) {
				arr[a][b] = 1;
				cnt++;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	printf("%d", cnt);
	

	return 0;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}