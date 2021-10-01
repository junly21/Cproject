#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#define QUE_LEN	5
#define NAME_LEN 20


typedef struct _cQueue
{
	int front;
	int rear;
	char queArr[QUE_LEN][NAME_LEN]; 
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);
void Enqueue(Queue* pq);
void Dequeue(Queue* pq);
void QPeek(Queue* pq);



int main(void)
{



	// Queue의 생성 및 초기화 ///////
	Queue* q = (Queue*)malloc(sizeof(Queue));

	QueueInit(q);
	int selctService = 0;
	int waitingList = 0;
	while (1) {
		printf("진료 관리 서비스에 오신 것을 환영합니다. 원하는 기능의 번호를 선택해 주세요.\n");
		printf("1. 병원도착		2. 진료 완료	3. 서비스 종료\n");
		scanf("%d", &selctService);
		switch (selctService) {
		case 1:
			while (1) {
				printf("현재 대기자 수는 %d명입니다. 다음에서 원하는 기능의 번호를 선택해 주세요.\n",/*큐인덱스활용*/);
				printf("1. 대기자 등록 2. 취소\n");
				scanf("%d", &waitingList);

				if (waitingList == 1)
				{
					Enqueue //여기 수정해야됨
						break;
				}
				else if (waitingList == 2)
				{
					printf("취소\n");
					break;
				}
				else {
					printf("다시 입력해주세요\n");

				}

			}
		case 2:
			Dequeue; //여기 수정해야됨

		case 3:{
			printf("서비스를 종료합니다.\n");
			printf("감사합니다.\n");
			break; 
		}

		default:{
			printf("번호를 잘못 입력하셨습니다.\n");
			printf("----------------\n"); 
		}
		


	}


	return 0;
}

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

int NextPosIdx(int pos) 
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) 
{
	if (NextPosIdx(pq->rear) == pq->front)//큐가 꽉찼을때인듯
	{
		printf("새 진료 접수가 불가능합니다.\n");
		printf("감사합니다.\n");
		printf("----------------\n");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	/*if (pos == QUE_LEN - 1) 
		return 0;
	else
		return pos + 1;*/

	//gets_s(pq->a 
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("대기 중인 환자가 없습니다.\n");
		exit(-1);
	}



	pq->front = NextPosIdx(pq->front); 	
	return pq->queArr[pq->front];


	printf("%s 님이 진료 대기입니다.\n", /*어쩌고 저쩌고*/);
	printf("감사합니다\n");
	printf("----------------\n");
}
	

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}


