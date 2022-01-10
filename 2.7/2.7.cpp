#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
bool isBIGYear(int year)
{
	if (year % 100 != 0 && year % 4 == 0)return true;
	if (year % 100 == 0 && year % 400 == 0)return true;
	return false;
}

int len[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31} };

int main()
{
	int year, day;
	while (scanf("%d %d", &year, &day) != EOF)
	{
		int index = isBIGYear(year);
		int nowMonth = 1;
		while (day > len[index][nowMonth])
		{
			day -= len[index][nowMonth];
			nowMonth++;
		}
		printf("%04d-%02d-%02d\n", year, nowMonth, day);//注意输出格式 %04d 代表输出4位整数 不够补0 %4d输出4位整数 不够补空格
	}


	return 0;
}