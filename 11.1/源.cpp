#include<iostream>
using namespace std;
const int MAX = 1000;
bool load[MAX][MAX];
bool visit[MAX];
int N, M;
void init()
{
	
	for (int i = 0; i < MAX; i++) {
		visit[i] = false;
		for (int j = 0; j < MAX; j++)
		{
			load[i][j] = false;
		}
	}
}

int lastUnVisited()
{
	for (int i = 0; i < N; i++)
	{
		if (visit[i] == false) {
			return i;
		}
	}
	return -1;
}

void DFS(int now)
{
	visit[now] = true;
	for (int i = 0; i < N; i++)
	{
		if (load[now][i] == true && visit[i] == false)
		{
			DFS(i);
		}
	}
}

int main()
{
	while (true)
	{
		init();
		cin >> N;
		if (N == 0)break;
		cin>> M;

		for (int i = 0; i < M; i++)
		{
			int left, right;
			cin >> left >> right;
			left--;
			right--;
			if (left < 0 || left>999)continue;
			if (right < 0 || right>999)continue;
			load[left][right] = true;
			load[right][left] = true;
		}
		int count = 0;
		while (true)
		{
			int index = lastUnVisited();
			if (index == -1)break;
			DFS(index);
			count++;

		}
		cout << count - 1 << endl;

	}
	

	return 0;
}