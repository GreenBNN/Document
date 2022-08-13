#include <stdio.h>

/*##### 점화식, 재귀함수, 스택 
			이 전에 사용했던 것들 재활용 할 수 있나 확인하기 #####*/

#define MAX_CARD 10001

void findMax(int cardNum);

int price[MAX_CARD];
int dp[MAX_CARD];

int main() {
	int cardNum;

	scanf("%d", &cardNum);
	for (int i = 1; i <= cardNum; i++) { 
		scanf("%d", &price[i]);
		if (i == 1)
			dp[0] = 0;
			dp[1] = price[1];
	}

	findMax(cardNum);
	printf("%d", dp[cardNum]);

	return 0;
 }
void findMax(int cardNum) {

	if (dp[cardNum] == NULL) {
		findMax(cardNum - 1);
	}
	dp[cardNum] = 0;
	for (int i = 1; i <= cardNum; i++) { // 가장 큰 값이 dp 에 저장
		if (dp[cardNum] < dp[cardNum - i] + price[i]) {
			dp[cardNum] = dp[cardNum - i] + price[i];
		}
	}
}