#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

int timeTable[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31} };

bool isBigYear(int year)
{
	if (year % 400 == 0)return true;
	if (year % 4 == 0 && year % 100 != 0)return true;
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int year, month, day, nextday;
		scanf("%d %d %d %d", &year, &month, &day, &nextday);
		while (nextday > (365 + isBigYear(year)))
		{
			nextday -= 365 + isBigYear(year);
			year++;
		}
		while (nextday > timeTable[isBigYear(year)][month])
		{
			nextday -= timeTable[isBigYear(year)][month];
			month++;
		}
		day += nextday;
		if (day > timeTable[isBigYear(year)][month])
		{
			day -= timeTable[isBigYear(year)][month];
			month++;
		}
		printf("%04d-%02d-%02d\n", year, month, day);
	}

	return 0;
}