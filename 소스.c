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
		printf("새 진료 접수가 불가능합니다\n");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue* pq)
{
	if (pq->front == pq->rear)
	{
		printf("대기중인 환자가 없습니다\n");
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

int main(void)
{
	
	// Queue의 생성 및 초기화 ///////
	Queue q;
	QueueInit(&q);

	// 데이터 넣기 ///////
	Enqueue(&q, 1);
	printf("%d\n", q);
	Enqueue(&q, 2);
	printf("%d\n", q);
	Enqueue(&q, 3);  Enqueue(&q, 4);
	Enqueue(&q, 5);

	// 데이터 꺼내기 ///////
	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	return 0;
}