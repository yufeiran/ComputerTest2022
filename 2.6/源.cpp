#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

bool isBIGYear(int year)
{

	//闰年：z 能被400整除 或者 能被4整除且不能被100整除 
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			return true;
		}
	}
	else {
		if (year % 4 == 0) {
			return true;
		}
	}
	return false;
}

int len[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int cal(int year,int month, int day)
{
	int sum = 0;
	sum += day;
	bool isBig = isBIGYear(year);
	for (int i = 1; i < month; i++)
	{
		sum += len[i];
		if (i == 2 && isBig == true)sum += 1;
	}
	return sum;
}

int main()
{
	int year, month, day;
	while (scanf("%d %d %d", &year, &month, &day) != EOF)
	{
		int sum = cal(year, month, day);
		printf("%d\n", sum);
	}
	

	return 0;
}