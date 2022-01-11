#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> En;
vector<int>E;
vector<int>G;

void calEn(int i)
{
	En.clear();
	for (int j = 1; j < i; j++)
	{
		if (i % j == 0)
		{
			En.push_back(i);
		}
	}
}

int main()
{
	for (int i = 2; i <= 60; i++)
	{
		calEn(i);
		int sum = 0;
		for (int j = 0; j < En.size(); j++)
		{
			sum += En[j];
		}
		if (sum == i)E.push_back(i);
		else if (sum > i)G.push_back(i);
	}

	cout << "E:";
	for (int i = 0; i < E.size(); i++)
	{
		cout << " " << E[i];
	}
	cout << endl;
	cout << "G:";
	for (int i = 0; i < G.size(); i++)
	{
		cout << " " << G[i];
	}
	cout << endl;

	return 0;
}