#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int N, M;
const int MAX_N = 501;
int inEdge[MAX_N];
int isOut[MAX_N];
struct Load
{
	int from, to;
	Load() {};
	Load(int FROM, int TO) :from(FROM), to(TO) {};
};
vector<Load>EDGE[MAX_N];
vector<int>outIndex;

void init()
{
	for (int i = 0; i < N; i++)
	{
		isOut[i] = false;
		inEdge[i] = 0;
		EDGE[i].clear();
		outIndex.clear();
	}
}

int findZero()
{
	for (int i = 0; i < N; i++)
	{
		if (isOut[i]==false && inEdge[i] == 0)return i;
	}
	return -1;
}

int main()
{	
	scanf("%d %d", &N, &M);
	init();
	for (int i = 0; i < M; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		from--; to--;
		inEdge[to]++;
		EDGE[from].push_back(Load(from, to));
	}
	while (true)
	{
		int index = findZero();
		if (index == -1) {
			break;
		}
		isOut[index] = true;
		outIndex.push_back(index);
		for (int i = 0; i < EDGE[index].size(); i++)
		{
			Load nowLoad = EDGE[index][i];
			inEdge[nowLoad.to]--;

		}
		
	}
	for (int i = 0; i < outIndex.size(); i++)
	{
		printf("%d", outIndex[i]+1);
		if (i != outIndex.size() - 1)printf(" ");
		else printf("\n");
	}

	return 0;
}