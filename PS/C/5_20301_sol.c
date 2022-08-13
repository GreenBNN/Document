#include <stdio.h>
#include <stdlib.h>

/*####### ���ڿ� �Է¹ޱ�, ť 
			���� �似Ǫ�� ���� 
				7 3 4 / 7�� �� 3 ��° ���� 
					4��°���� ����#######*/

#define MAX_QUEUE_SIZE 5001
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

void error(char* message) {
	fprintf(stderr, "%s/\n", message);
	exit(1);
}

void initDeque(DequeType* q) {
	q->front = q->rear = 0;
}

int isEmpty(DequeType* q) {
	return (q->front == q->rear);
}

int isFull(DequeType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void dequePrint(DequeType* q) {
	printf("DEQUE(front=%d rear=%d)", q->front, q->rear);
	if (!isEmpty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void addRear(DequeType* q, element item) {
	if (isFull(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element deleteRear(DequeType* q) {
	int prev = q->rear;
	if (isEmpty(q)) {
		error("ť�� ��������Դϴ�.");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element getRear(DequeType* q) {
	if (isEmpty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->rear];
}
void addFront(DequeType* q, element item) {
	if (isFull(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element deleteFront(DequeType* q) {
	int prev = q->front;
	if (isEmpty(q)) {
		error("ť�� ��������Դϴ�.");
	}
	q->front = (q->front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}
element getFront(DequeType* q) {
	if (isEmpty(q)) {
		error("ť�� ��������Դϴ�.");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int N, M, K;
int main(void) {
	DequeType queue;
	initDeque(&queue);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		addRear(&queue, i+1);
	}

	int flag = 1;
	int cnt = 0;
	int flag_cnt = 0;
	element temp;
	while (cnt != N) {
		if (flag) {
			for (int i = 0; i < M - 1; i++) {
				temp = getFront(&queue);
				deleteFront(&queue);
				addRear(&queue, temp);
			}
			temp = getFront(&queue);
			deleteFront(&queue);

			cnt++;
			flag_cnt++;
			if (cnt == N) {
				printf("%d", temp);
			}
			else {
				printf("%d\n", temp);
			}
			
			if (flag_cnt == K) {
				flag = 0;
				flag_cnt = 0;
			}
		}
		else {
			for (int i = 0; i < M - 1; i++) {
				temp = getRear(&queue);
				deleteRear(&queue);
				addFront(&queue, temp);
			}
			temp = getRear(&queue);
			deleteRear(&queue);
			cnt++;
			flag_cnt++;
			if (cnt == N) {
				printf("%d", temp);
			}
			else {
				printf("%d\n", temp);
			}
			if (flag_cnt == M) {
				flag = 1;
				flag_cnt = 0;
			}

		}
	}
	
	return 0;
}
