#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 200;
struct Data {
	int id;
	int data;
};

Data DATA[MAX];

bool cmp(Data d1, Data d2)
{
	if (d1.data < d2.data)return true;
	else return false;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		DATA[i].id = i;
		scanf("%d", &DATA[i].data);

	}
	int aim;
	scanf("%d", &aim);
	sort(DATA, DATA+N, cmp);

	for (int i = 0; i < N; i++)
	{
		if (DATA[i].data > aim)
		{
			printf("-1\n");
			break;
		}
		else if (DATA[i].data == aim)
		{
			printf("%d\n", DATA[i].id);
			break;
		}
	}


	return 0;
}