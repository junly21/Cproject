#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 구조체 및 공용체
typedef struct _user
{
	char name[20];
	char type;
	char phone[20];

	union {
		int buy;
		int sell;
	}u;

}User;

int main()
{
	User user[100]; // 최대 100명
	char buffer[100];
	char* ptr; // 토큰분리 결과 저장

	int bmin = -1; //최저구매자
	int bmax = -1;
	int smin = -1; //최대판매자
	int smax = -1;
	int i;
	int total = 0;
	int count = 0;
	int count = 0;
	char a = 'none';
	double Bavg = 0; // buyaverage
	double Savg = 0; // sellaverage


	printf("고객 정보를 입력해 주십시오 (<이름> <고객 유형> <전화번호> <금액>):\n");
	while (1)
	{
		gets_s(buffer, 100);
		ptr = strtok(buffer, " ");

		if (strcmp(ptr, "--") == 0)
			break;
		else
		{
			strcpy(user[count].name, ptr);

			ptr = strtok(NULL, " ");
			user[count].type = ptr[0];

			ptr = strtok(NULL, " ");
			strcpy(user[count].phone, ptr);
			ptr = strtok(NULL, " ");

			if (user[count].type == 'C')
				user[count].u.buy = atoi(ptr);
			else
				user[count].u.sell = atoi(ptr);
		}
		count++;
	}

	//buymin
	for (i = 0; i < count; i++)
	{
		if (user[i].type == 'S')
			continue;

		if (bmin == -1)
			bmin = i;
		else
		{
			if (user[i].u.buy <= user[bmin].u.buy)
				bmin = i;
		}
	}
	//buymax
	for (i = 0; i < count; i++)
	{
		if (user[i].type == 'S')
			continue;

		if (bmax == -1)
			bmax = i;
		else
		{
			if (user[i].u.buy >= user[bmax].u.buy)
				bmax = i;
		}
	}
	//Buy average
	for (i = 0; i < count; i++)
	{
		if (user[i].type == 'S')
			continue;

		total = total+ user[i].u.buy;
		count++;
	}
	Bavg = total / (double)count;

	

	//sell min
	for (i = 0; i < count; i++)
	{
		if (user[i].type == 'C')
			continue;

		if (smin == -1)
			smin = i;
		else
		{
			if (user[i].u.sell <= user[smin].u.sell)
				smin = i;
		}
	}

	// sell max
	for (i = 0; i < count; i++)
	{
		if (user[i].type == 'C')
			continue;

		if (smax == -1)
			smax = i;
		else
		{
			if (user[i].u.sell >= user[smax].u.sell)
				smax = i;
		}
	}

	// sell average
	total = 0;
	count = 0;
	for (i = 0; i < count; i++)
	{
		if (user[i].type == 'C')
			continue;

		total += user[i].u.sell;
		count++;
	}
	Savg = total / (double)count;

	


	if (bmax == -1)
	{
		printf("최저 구매자 : %(c)\n", a);
		printf("최고 구매자 : %(c)\n", a);
		printf("평균 구매액 : 0.0\n");
	}
	else {
		printf("최저 구매자 : %s %d\n", user[bmin].name, user[bmin].u.buy);
		printf("최고 구매자 : %s %d\n", user[bmax].name, user[bmax].u.buy);
		printf("평균 구매액 : %.1lf\n", Bavg);
	}
	if (smax == -1)
	{
		printf("최저 판매자 : %(c)\n", a);
		printf("최고 판매자 : %(c)\n", a);
		printf("평균 판매액 : 0.0\n");
	}
	else {
		printf("최저 판매자 : %s %d\n", user[smin].name, user[smin].u.sell);
		printf("최고 판매자 : %s %d\n", user[smax].name, user[smax].u.sell);
		printf("평균 판매액 : %.1lf\n", Savg);
	}

	return 0;
}





