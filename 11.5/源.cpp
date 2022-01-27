#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct load
{
	int a, b, money;
	load(int A, int B, int MONEY) :a(A), b(B), money(MONEY) {};
	load() {};
	bool operator<(load a)const
	{
		if (money < a.money)return true;
		else return false;
	}
};

vector<load>loadList;
vector<load>choiceLoad;
int n;
const int MAX = 101;
int height[MAX];
int father[MAX];


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
	if (height[x] < height[y]) {
		father[x] = y;
	}
	else if (height[x] > height[y]) {
		father[y] = x;
	}
	else {
		father[y] = x;
		height[x]++;
	}
}

int rootSum()
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == father[i]) {
			count++;
		}
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
		for (int i = 0; i < n; i++)
		{
			int a, b, money, build;
			scanf("%d %d %d %d", &a, &b, &money, &build);
			a--; b--;
			load newLoad(a, b, money);
			if (build == 1)
			{
				Union(a, b);

			}
			else {
				loadList.push_back(newLoad);
			}
		}
		sort(loadList.begin(), loadList.end());
		while (rootSum() > 1) {
			for (int i = 0; i < loadList.size(); i++)
			{
				load nowLoad = loadList[i];
				if (find(nowLoad.a) != find(nowLoad.b)) {
					choiceLoad.push_back(nowLoad);
					Union(nowLoad.a, nowLoad.b);
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < choiceLoad.size(); i++)
		{
			sum += choiceLoad[i].money;
		}
		cout << sum << endl;
	}

	return 0;
}