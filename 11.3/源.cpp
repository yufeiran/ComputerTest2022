#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;
const int MAX = 10001;
int height[MAX];
int father[MAX];
int inEdge[MAX];
bool visited[MAX];

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		height[i] = 0;
		father[i] = i;
		inEdge[i] = 0;
		visited[i] = false;
	}
}

int find(int x)
{
	if (x != father[x])
	{
		return find(father[x]);
	}
	else return x;
	
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (height[a] > height[b])
	{
		father[b] = a;
	}
	else if (height[a] < height[b])
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
	bool finalFlag = false;
	int caseCount = 0;
	while (true)
	{
		init();
		caseCount++;
		while (true)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (a <0 && b <0)
			{
				finalFlag = true;
				break;
			}
			else if (a == 0 && b == 0)
			{
				break;
			}
			a--;
			b--;
			Union(a, b);
			inEdge[b]++;
			visited[a] = true;
			visited[b] = true;
		}
		if (finalFlag == true)break;
		//判断根节点

		int rootIndex = -1;
		int rootCount = 0;
		bool  EdgeOver = false;
		for (int i = 0; i < MAX; i++)
		{
			if (visited[i] == true && inEdge[i] == 0)
			{
				rootIndex = i;
				rootCount++;
			}
			else if (visited[i] == true && inEdge[i] > 1)
			{
				EdgeOver = true;
			}
		}
		if (rootCount != 1||EdgeOver==true)
		{
			printf("Case %d is not a tree.\n", caseCount);
		}
		//判断每个节点的根节点
		else {
			int Count = 0;
			for (int i = 0; i < MAX; i++)
			{
				if (visited[i] == true)
				{
					if (father[i] == i)
					{
						Count++;
					}
				}
			}
			if (Count != 1)
			{
				printf("Case %d is not a tree.\n", caseCount);
			}
			else
			{
				printf("Case %d is a tree. \n", caseCount);
			}
		}
	}

	return 0;
}