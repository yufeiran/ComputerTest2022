#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;
const int MAX = 1001;
int height[MAX]; 
int father[MAX];
int n, m;

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		height[i] = 0;
		father[i] = i;
	}
}

int find(int x)
{
	if (x != father[x])
	{
		father[x]= find(father[x]);
	}
	return father[x];
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (height[a] > height[b])
	{
		father[b] = a;
	}
	else if (height[b] > height[a])
	{
		father[a] = b;
	}
	else {
		father[b] = a;
		height[a]++;
	}
}

int main()
{
	while (scanf("%d %d",&n,&m)!=EOF)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			Union(a-1, b-1);
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (father[i] == i)
			{
				count++;
			}
		}
		if (count == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");                                                                   
		}
	}



	return 0;
}