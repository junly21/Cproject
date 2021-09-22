#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>
/*6마리의 물고기가있다.
어항에 살고있는데, 어항의 물이 빨리 증발한다
물이 증발하기 전에 계속 물을 줘야한다
*/

int level;
int arrayFish[6]; //어항을 나타냄
int* cursor; // 1번을 가리키는지 2번을 가리키는지 이런거..

void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();
int main()
{
	long startTime = 0; //게임 시작 시간
	long totalElapsedTime = 0;//총 경과 시간
	long prevElapsedTime = 0; //직전 경과 시간 (최근에 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄것인지 입력받기
	
	initData();

	cursor = arrayFish; //cursor[0], cursor[1] 이런식으로 사용 가능

	startTime = clock(); //현재 시간을 millisecond단위로 반환함
	while (1)
	{
		printFishes();
		printf("몇번 어항에 물을 줄건가요\n");
		scanf_s("%d", &num);

		//입력값 체크
		if (num < 1 || num >6)
		{
			printf("\n입력값이 잘못되었습니다\n");
			continue;
		}
	
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과시간 :%Id 초 \n", totalElapsedTime);

		//직전에 물 준 시간 이후로 흐른 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과시간 :%Id 초 \n", prevElapsedTime);

		//어항의 물을 증발
		decreaseWater(prevElapsedTime);

		//사용자가 입력한 어항에 물을 준다
		//1. 어항의 물이 0이면 물을 주는걸 포기함
		if (cursor[num - 1] <= 0)
		{
			printf(" %d 번 물고기는 이미 죽어서 물을 안줍니다.\n, (num-1)");
		}
		//어항의 물이 0이 아닌경우 물을 주는데 100을 넘지 않아야함
		else if (cursor[num - 1] + 1 <= 100)
		{
			//물을 주면 됨
			printf("%d 번 어항에 물을 줍니다.\n", num);
			cursor[num - 1] = cursor[num - 1] + 1;
		}
		//레벨업은 20초마다 되는데 할건지 확인
		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf("레벨업~ %d레벨\n", level);

			if (level == 5)
			{
				printf("\n\n최고레벨입니다. 게임 종료.");
				exit(0);
			}
		}
		//물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			printf("물고기가 모두 죽었네요 \n");
			exit(0);
		}
		else
		{
			printf("물고기가 살아있어용\n");
		}
		prevElapsedTime = totalElapsedTime;

	}
	return 0;
}
void initData()
{
	level = 1;
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; //어항의 물 수위는 0~100
	}
}

void printFishes()
{
	printf("%3d번  %3d번  %3d번  %3d번  %3d번  %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("  %3d  ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = arrayFish[i] - (level * 3 * (int)elapsedTime);
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1;
		else
		{
			return 0;
		}

	}
}
