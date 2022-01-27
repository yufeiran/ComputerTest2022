#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

const int MAX_N = 101;
int inEdgeSum[MAX_N];
int n, m;
struct load
{
	int from, to;
	load() {};
	load(int FROM, int TO) :from(FROM), to(TO) {};
};
vector<load>EDGE[MAX_N];
bool isOut[MAX_N];


int findZero()
{

	for (int i = 0; i < n; i++)
	{
		if (isOut[i]==false&& inEdgeSum[i] == 0)return i;
	}
	return -1;
}

void init()
{
	for (int i = 0; i < MAX_N; i++) {
		inEdgeSum[i] = 0;
		EDGE[i].clear();
		isOut[i] = false;
	}

}

bool isAllEmpty()
{
	for (int i = 0; i < n; i++)
	{
		if (EDGE[i].empty() == false)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	while (true)
	{

		scanf("%d %d", &n, &m);
		
		if (n == 0 && m == 0)break;
		init();
		for (int i = 0; i < m; i++)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			inEdgeSum[to]++;
			EDGE[from].push_back(load(from, to));
		}
		while (true)
		{
			int index = findZero();
			if (index == -1)
			{
				break;
			}
			isOut[index] = true;
			for (int i = 0; i < EDGE[index].size(); i++)
			{
				int to = EDGE[index][i].to;
				inEdgeSum[to]--;
				EDGE[index].erase(EDGE[index].begin()+i);
			}
		}
		if (isAllEmpty() == true)
		{
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		
	}


	return 0;
}