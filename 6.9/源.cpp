#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

const int MAX = 1001;
bool isPrime[MAX];

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < MAX; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = i * i; j < MAX; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	int n;
	init();
	while (scanf("%d", &n) != EOF)
	{
		int now = n;
		int count = 0;
		int index = 2;
		while (1)
		{
			if (isPrime[index] == true)
			{
				if (now % index == 0)
				{
					while (now % index == 0)
					{
						count++;
						now /= index;
						printf("now is %d\n", now);
					}
				}
			}
			index++;
			if (index > n || index > MAX)break;
		}
		if (n > 1) {
			count++;
		}
		printf("%d\n", count);
	}
	
	return 0;
}