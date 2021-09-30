#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_LEN 20
#define QUEUE_LEN 5


typedef int Data;

typedef struct Queue {
	int front;
	int rear;
	Data queArr[QUEUE_LEN];
}CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
		return 1;
	else
		return 0;
}


int NextPosIdx(int pos) {
	if (pos == QUEUE_LEN-1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front) //Queue is full
	{
		printf("�� ���� ������ �Ұ����մϴ�\n");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue* pq)
{
	if (pq->front == pq->rear)
	{
		printf("������� ȯ�ڰ� �����ϴ�\n");
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

int main(void)
{
	
	// Queue�� ���� �� �ʱ�ȭ ///////
	Queue q;
	QueueInit(&q);

	// ������ �ֱ� ///////
	Enqueue(&q, 1);
	printf("%d\n", q);
	Enqueue(&q, 2);
	printf("%d\n", q);
	Enqueue(&q, 3);  Enqueue(&q, 4);
	Enqueue(&q, 5);

	// ������ ������ ///////
	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	return 0;
}