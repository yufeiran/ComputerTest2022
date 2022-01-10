#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int h;
	while (scanf("%d", &h) != EOF)
	{
		//0   ÐÐ 2h        ¿Õ          h ÐÇ
		//i   ÐÐ 2h-2(i+1) ¿Õ          h+2(i)
		//h-1 ÐÐ 0         ¿Õ          h+2h-2 ÐÇ
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < 2 * h - 2 * (i + 1); j++)
			{
				printf(" ");
			}
			for (int j = 0; j < h + 2 * i; j++)
			{
				printf("*");
			}
			printf("\n");
		}

	}


	return 0;
}