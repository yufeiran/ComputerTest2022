#include<iostream>

using namespace std;

const int MAX = 1001;
int height[MAX]; 
int father[MAX];
int N, M;

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		height[i] = 0;
		father[i] = i;
	}
}

int find(int x)
{
	if (father[x] != x)
	{
		return find(father[x]);
	}
	else return father[x];
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
	else
	{
		father[y] = x;
		height[x]++;
	}
}

int main()
{
	while (true)
	{
		init();
		cin >> N;
		if (N == 0)break;
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			int x, y;
			cin >> x >> y;
			Union(x, y);
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (find(i) == i)
			{
				ans++;
			}
		}
		cout << ans - 1 << endl;
	}

	return 0;
}