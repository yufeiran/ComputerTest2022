#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 101;
int height[MAX]; 
int father[MAX];
struct load
{
	int a, b, len;
	load(int A, int B, int LEN) :a(A), b(B), len(LEN) {};
	load() {};
	bool operator<(load a)const {
		if (len < a.len)return true;
		else return false;
	}
};
vector<load>loadList;
vector<load>choiceLoad;
int n;

bool cmp(load a, load b)
{
	if (a.len < b.len)return true;
	else return false;
}

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		height[i] = 0;
		father[i] = i;
		
	}
	loadList.clear();
	choiceLoad.clear();
}

int find(int x)
{
	if (x != father[x])
	{
		return find(father[x]);
	}
	return x;
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (height[x] > height[y])
	{
		father[y] = x;
	}
	else if (height[x] < height[y])
	{
		father[x] = y;
	}
	else {
		father[x] = y;
		height[y]++;
	}
}

int fatherSum()
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (father[i] == i)count++;
	}
	return count;
}

int main()
{
	while (true)
	{
		init();
		scanf("%d", &n);
		if (n == 0)break;
		for (int i = 0; i < n * (n - 1) / 2; i++)
		{
			int a, b, len;
			scanf("%d %d %d", &a, &b, &len);
			a--; b--;
			loadList.push_back(load(a, b, len));
		}
		sort(loadList.begin(), loadList.end());
		while (fatherSum() > 1)
		{
			for (int i = 0; i < loadList.size(); i++)
			{
				load nowLoad = loadList[i];
				if (find(nowLoad.a) != find(nowLoad.b))
				{
					choiceLoad.push_back(nowLoad);
					Union(nowLoad.a, nowLoad.b);

				}
			}
		}
		int size = 0;
		for (int i = 0; i < choiceLoad.size(); i++)
		{
			size += choiceLoad[i].len;
		}
		cout << size << endl;
	}


	return 0;
}