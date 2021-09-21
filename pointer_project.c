#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>
/*6������ ����Ⱑ�ִ�.
���׿� ����ִµ�, ������ ���� ���� �����Ѵ�
���� �����ϱ� ���� ��� ���� ����Ѵ�
*/

int level;
int arrayFish[6]; //������ ��Ÿ��
int* cursor; // 1���� ����Ű���� 2���� ����Ű���� �̷���..

void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();
int main()
{
	long startTime = 0; //���� ���� �ð�
	long totalElapsedTime = 0;//�� ��� �ð�
	long prevElapsedTime = 0; //���� ��� �ð� (�ֱٿ� ���� �� �ð� ����)

	int num; // �� �� ���׿� ���� �ٰ����� �Է¹ޱ�
	
	initData();

	cursor = arrayFish; //cursor[0], cursor[1] �̷������� ��� ����

	startTime = clock(); //���� �ð��� millisecond������ ��ȯ��
	while (1)
	{
		printFishes();
		printf("��� ���׿� ���� �ٰǰ���\n");
		scanf_s("%d", &num);

		//�Է°� üũ
		if (num < 1 || num >6)
		{
			printf("\n�Է°��� �߸��Ǿ����ϴ�\n");
			continue;
		}
	
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ����ð� :%Id �� \n", totalElapsedTime);

		//������ �� �� �ð� ���ķ� �帥 �ð�
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ����ð� :%Id �� \n", prevElapsedTime);

		//������ ���� ����
		decreaseWater(prevElapsedTime);

		//����ڰ� �Է��� ���׿� ���� �ش�
		//1. ������ ���� 0�̸� ���� �ִ°� ������
		if (cursor[num - 1] <= 0)
		{
			printf(" %d �� ������ �̹� �׾ ���� ���ݴϴ�.\n, (num-1)");
		}
		//������ ���� 0�� �ƴѰ�� ���� �ִµ� 100�� ���� �ʾƾ���
		else if (cursor[num - 1] + 1 <= 100)
		{
			//���� �ָ� ��
			printf("%d �� ���׿� ���� �ݴϴ�.\n", num);
			cursor[num - 1] = cursor[num - 1] + 1;
		}
		//�������� 20�ʸ��� �Ǵµ� �Ұ��� Ȯ��
		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf("������~ %d����\n", level);

			if (level == 5)
			{
				printf("\n\n�ְ����Դϴ�. ���� ����.");
				exit(0);
			}
		}
		//����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			printf("����Ⱑ ��� �׾��׿� \n");
			exit(0);
		}
		else
		{
			printf("����Ⱑ ����־��\n");
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
		arrayFish[i] = 100; //������ �� ������ 0~100
	}
}

void printFishes()
{
	printf("%3d��  %3d��  %3d��  %3d��  %3d��  %3d��\n", 1, 2, 3, 4, 5, 6);
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