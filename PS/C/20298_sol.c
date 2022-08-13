#include <stdio.h>

#define MAX_PIZZA 1000001

struct Node{
	int data;
	struct Node* link;
};
typedef struct Node Node;
Node *topping[MAX_PIZZA];
Node* first;

int age[MAX_PIZZA];
int person[MAX_PIZZA];

int pizzaNum = 1;
int personNum;

int count = 0;

int main() {

	 scanf("%d %d", &pizzaNum, &personNum);
	for (int i = 0; i < pizzaNum; i++) {
		topping[i] = (Node*)malloc(sizeof(first));
		topping[i]->link = NULL;
		scanf("%d", &topping[i]->data);
		if (i > 0) {
			topping[i]->link = topping[i - 1];
		}
	}
	topping[0]->link = topping[pizzaNum - 1];

	for (int i = 0; i < personNum; i++) {
		scanf("%d", &age[i]);
	}

	first = topping[0];
	for (int i = 0; i < pizzaNum; i++) {
		for (int j = 0; j < personNum; j++) {
			person[j] = first->data;
			first = first->link;
		}
		for (int m = 0; m < personNum; m++) {
			for (int n = 0; n < personNum - m; n++) {
				if (age[m] > age[m + n] && person[m] <= person[m + n])
					break;
				else if (age[m] < age[m + n] && person[m] >= person[m + n])
					break;
				else if (age[m] == age[m + n] && person[m] != person[m + n])
					break;
				count++;
			}
		}
	}


	printf("%d",count);



	for (int i = 0; i < pizzaNum; i++) {
		free(topping[i]);
	}
	return 0;
}