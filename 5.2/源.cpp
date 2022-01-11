#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

queue<int>Q;


void MoveStep(int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp = Q.front();
		Q.pop();
		Q.push(temp);
	}
}

int main()
{
	while (1)
	{
		int n, p, m;
		cin >> n >> p >> m;
		if (n == 0 && p == 0 && m == 0)break;


		for (int i = 1; i <= n; i++)Q.push(i);
		//移到第p个小孩
		MoveStep(p - 1);

		while (Q.empty() == false)
		{

			//从p开始 移动到第m个小孩
			MoveStep(m - 1);

			//移除第m个小孩
			int nowM = Q.front();
			Q.pop();
			cout << nowM;
			if (Q.empty() == false)cout << ",";
			else cout << endl;
		}

	}

	return 0;
}
