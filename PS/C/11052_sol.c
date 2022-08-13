#include <stdio.h>

/*##### ��ȭ��, ����Լ�, ���� 
			�� ���� ����ߴ� �͵� ��Ȱ�� �� �� �ֳ� Ȯ���ϱ� #####*/

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
	for (int i = 1; i <= cardNum; i++) { // ���� ū ���� dp �� ����
		if (dp[cardNum] < dp[cardNum - i] + price[i]) {
			dp[cardNum] = dp[cardNum - i] + price[i];
		}
	}
}