#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100001

/*####### 단위시간마다 한칸씩 변화가 일어나는데
			그 변화를 어떻게 해야 쉽게 풀 지 생각해야 한다. #######*/
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
		error("큐가 포화상태입니다.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element deleteRear(DequeType* q) {
	int prev = q->rear;
	if (isEmpty(q)) {
		error("큐가 공백상태입니다.");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element getRear(DequeType* q) {
	if (isEmpty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}
void addFront(DequeType* q, element item) {
	if (isFull(q)) {
		error("큐가 포화상태입니다.");
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element deleteFront(DequeType* q) {
	int prev = q->front;
	if (isEmpty(q)) {
		error("큐가 공백상태입니다.");
	}
	q->front = (q->front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}
element getFront(DequeType* q) {
	if (isEmpty(q)) {
		error("큐가 공백상태입니다.");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
int main() {

	int N, W, L;
	int arr[1001];

	DequeType queue;
	initDeque(&queue);

	int time = 0;
	int sum = 0;
	scanf("%d %d %d", &N, &W, &L);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	
	for (int i = 0; i < N; i++) {
		while (1) {
			if (queue.rear - queue.front == W) {
				sum -= getFront(&queue);
				deleteFront(&queue);
			}
			if (sum + arr[i] <= L) break;
			addRear(&queue,0);
			time++;
		}
		addRear(&queue,arr[i]);
		sum += arr[i];
		time++;
	}
	time += W;
	printf("%d", time);


}