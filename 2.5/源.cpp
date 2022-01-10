#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
char Data[80][80] = {};

int w;
char in, out;

void init()
{
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			Data[i][j] = 0;
		}

	}
}

void Draw(int h, int now)
{
	int center = h / 2;
	char nowAscii;
	if (now % 2 == 0) {
		nowAscii = in;
	}
	else nowAscii = out;
	//up down
	for (int i = center - now; i <= center + now; i++)
	{
		Data[center + now][i] = nowAscii;
		Data[center - now][i] = nowAscii;
		Data[i][center - now] = nowAscii; //left;
		Data[i][center + now] = nowAscii; //right
	}
	if (center - now == 0)
	{
		Data[0][0] = ' ';
		Data[center + now][0] = ' ';
		Data[center + now][center + now] = ' ';
		Data[0][center + now] = ' ';
	}
}

void output()
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (Data[i][j] != 0)
			{
				printf("%c", Data[i][j]);
			}
		}
		printf("\n");
	}
}

int main()
{

	bool firstCase = true;
	while (scanf("%d %c %c", &w, &in, &out) != EOF)
	{
		init();
		for (int j = 0; j <= w / 2; j++)
		{
			Draw(w, j);
		}
		if (firstCase == true)
		{
			firstCase = false;
		}
		else {
			printf("\n");
		}
		output();

	}

	return 0;
}