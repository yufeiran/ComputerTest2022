#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 10001;
int DATA[MAX];
int L;

void init(int l)
{
	for (int i = 0; i <= l; i++)
	{
		DATA[i] = 1;
	}
}

void cut(int left, int right)
{
	for (int i = left; i <= right; i++)
	{
		DATA[i] = 0;
	}
}

int main()
{
	int n;
	scanf("%d %d", &L, &n);
	init(L);
	for (int i = 0; i < n; i++)
	{
		int left, right;
		scanf("%d %d", &left, &right);
		cut(left, right);
	}
	int sum = 0;
	for (int i = 0; i <= L; i++)
	{
		if (DATA[i] == 1)sum++;
	}
	printf("%d\n", sum);

	return 0;
}