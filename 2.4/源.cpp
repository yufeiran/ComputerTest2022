#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int h;
	while (scanf("%d", &h) != EOF)
	{
		//0   �� 2h        ��          h ��
		//i   �� 2h-2(i+1) ��          h+2(i)
		//h-1 �� 0         ��          h+2h-2 ��
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