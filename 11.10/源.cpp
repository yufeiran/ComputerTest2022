#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int N, M;
const int MAX_N = 1001;
struct Load
{
	int from, to, len;
	int el, ll;
	Load();
	Load(int FROM, int TO, int LEN) :from(FROM), to(TO), len(LEN) {};
};
vector<Load>EDGE[MAX_N];
vector<Load>R_EDGE[MAX_N];
vector<int>frontV[MAX_N];
vector<int>endV[MAX_N];
int ev[MAX_N];
int lv[MAX_N];

vector<Load>choiceLoad;

void init()
{
	for (int i = 0; i < N; i++)
	{
		ev[i] = 0;
		lv[i] = INT_MAX;
	}
}

void elDFS(int index, int len)
{
	if (ev[index] < len)
	{
		ev[index] = len;
	}
	for (int i = 0; i < EDGE[index].size(); i++)
	{
		Load nowLoad = EDGE[index][i];
		elDFS(nowLoad.to, nowLoad.len+len);
	}
}

void lvDFS(int index, int len)
{
	if (lv[index] > len)
	{
		lv[index] = len;
	}
	for (int i = 0;i< R_EDGE[index].size(); i++)
	{
		Load nowLoad = R_EDGE[index][i];
		lvDFS(nowLoad.from, len - nowLoad.len);
	}
}

void calev()
{
	for (int i = 0; i < N; i++)
	{
		if (frontV[i].size() == 0)
		{
			elDFS(i, 0);
		}
	}

}

void callv()
{
	for (int i = 0; i < N; i++)
	{
		if (endV[i].size() == 0)
		{
			lvDFS(i, ev[i]);
		}
	}
}


void calelll()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < EDGE[i].size(); j++)
		{
			Load nowLoad = EDGE[i][j];
			EDGE[i][j].el = ev[nowLoad.from];
			EDGE[i][j].ll = lv[nowLoad.to] - nowLoad.len;
			if (EDGE[i][j].el == EDGE[i][j].ll)
			{
				choiceLoad.push_back(EDGE[i][j]);
			}
		}
	}
}

int findMax()
{
	int max = -1;
	for (int i = 0; i < N; i++)
	{
		if (max < ev[i])
		{
			max = ev[i];
		}
	}
	return max;
}

int main()
{
	scanf("%d %d", &N, &M);
	init();
	for (int i = 0; i < M; i++)
	{
		int from, to, len;
		scanf("%d %d %d", &from, &to, &len);
		from--; to--;
		endV[from].push_back(to);
		frontV[to].push_back(from);
		EDGE[from].push_back(Load(from, to, len));
		R_EDGE[to].push_back(Load(from, to, len));
	}

	calev();
	callv();
	calelll();


	cout << findMax() + 1 << endl;

	return 0;
}