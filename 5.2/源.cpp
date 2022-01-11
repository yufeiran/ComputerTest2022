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
		//�Ƶ���p��С��
		MoveStep(p - 1);

		while (Q.empty() == false)
		{

			//��p��ʼ �ƶ�����m��С��
			MoveStep(m - 1);

			//�Ƴ���m��С��
			int nowM = Q.front();
			Q.pop();
			cout << nowM;
			if (Q.empty() == false)cout << ",";
			else cout << endl;
		}

	}

	return 0;
}
