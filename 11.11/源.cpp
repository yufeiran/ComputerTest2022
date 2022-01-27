#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<climits>
using namespace std;
const int MAX_N = 100001;
vector<int>frontV[MAX_N];
vector<int>endV[MAX_N];
struct Load
{
	int  from, to;
	Load() {};
	Load(int FROM, int TO) :from(FROM), to(TO) {};
};
vector<Load>EDGE[MAX_N];
vector<Load>R_EDGE[MAX_N];
int Value[MAX_N];

int ev[MAX_N];
int lv[MAX_N];

int n, m;
int maxTime = 0;
void init()
{
	for (int i = 0; i < n; i++)
	{
		ev[i] = 0;
		lv[i] = INT_MAX;
		Value[i] = 0;
	}
}

void evDFS(int index, int len)
{
	if (ev[index] < len)
	{
		ev[index] = len;
	}
	for (int i = 0; i < EDGE[index].size(); i++)
	{
		Load nowLoad = EDGE[index][i];
		int value = Value[nowLoad.from];
		evDFS(nowLoad.to, value+len);
	}
}

void lvDFS(int index, int len)
{
	if (lv[index] > len)
	{
		lv[index] = len;
	}
	for (int i = 0; i < R_EDGE[index].size(); i++)
	{
		Load nowLoad = R_EDGE[index][i];
		int value = Value[nowLoad.from];
		lvDFS(nowLoad.from, len - value);
	}
}

void calev()
{
	for (int i = 0; i < n; i++)
	{
		if (frontV[i].empty() == true)
		{
			evDFS(i, 0);
		}
	}
}

void callv()
{
	for (int i = 0; i < n; i++)
	{
		if (endV[i].empty())
		{
			lvDFS(i, maxTime-Value[i]);
		}
	}
}

void findMax()
{
	for (int i = 0; i < n; i++)
	{
		if (ev[i]+Value[i] > maxTime)
		{
			maxTime = ev[i]+Value[i];
		}
	}
}

long long calF()
{
	long long answer = 1;
	for (int i = 0; i < n; i++)
	{
		long long now = lv[i] - ev[i] + 1;
		answer *= now;
	}
	answer %= (long long)(1e9 + 7);
	return answer;
}

int main()
{
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < n; i++)
	{
		int len;
		scanf("%d", &len);
		Value[i] = len;
	}
	for (int i = 0; i < m; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		from--; to--;
		EDGE[from].push_back(Load(from, to));
		R_EDGE[to].push_back(Load(from, to));
		frontV[to].push_back(from);
		endV[from].push_back(to);
	}
	calev();
	findMax();
	callv();
	cout << maxTime << endl;
	cout << calF() << endl;

	return 0;
}