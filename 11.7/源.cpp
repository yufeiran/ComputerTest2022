#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
struct Load
{
	int from, to, len,money;
	Load(int FROM, int TO, int LEN,int MONEY) :from(FROM), to(TO), len(LEN),money(MONEY) {};
	Load() {};
	bool operator<(Load a)const {
		if (len < a.len)return true;
		else return false;
	}
};
struct Point
{
	int v, distance;
	Point(int V, int DISTANCE) :v(V), distance(DISTANCE) {};
	Point() {};
	bool operator<(Point a)const {
		if (distance < a.distance)return true;
		else return false;
	}
};
int n, m;
const int MAX_N = 1001;
const int MAX_M = 100000;

int DISTANCE[MAX_N];
vector<Load>EDGE[MAX_N];

vector<int>beforeNode[MAX_N];
bool inS[MAX_N];

void init()
{
	for (int i = 0; i < n; i++)
	{
		DISTANCE[i] = INT_MAX;
		inS[i] = false;
		EDGE[i].clear();
		beforeNode[i].clear();
	}


}

void Dij(int start)
{
	priority_queue<Point> myQueue;
	myQueue.push(Point(start, 0));
	DISTANCE[start] = 0;
	inS[start] = true;
	while (myQueue.empty() == false)
	{
		Point nowPoint = myQueue.top();
		myQueue.pop();

		for (int i = 0; i < EDGE[nowPoint.v].size(); i++) {
			Load nowLoad = EDGE[nowPoint.v][i];
			int nowV = nowPoint.v;
			int len = nowLoad.len;
			if (DISTANCE[nowV] + len <= DISTANCE[nowLoad.to]) {
				beforeNode[nowLoad.to].push_back(nowV);
				DISTANCE[nowLoad.to] = DISTANCE[nowV] + len;
				myQueue.push(Point(nowLoad.to, DISTANCE[nowLoad.to]));
			}
		}
	}

}

int minSum = INT_MAX;
void DFS(int nowIndex, int sum,int aim)
{
	if (nowIndex == aim)
	{
		if (sum < minSum)
		{
			minSum = sum;
			
		}
		return;
	}
	for (int i = 0; i < beforeNode[nowIndex].size(); i++)
	{
		int toIndex = beforeNode[nowIndex][i];
		int money = 0;
		for (int j = 0; j < EDGE[nowIndex].size(); j++)
		{
			Load nowLoad = EDGE[nowIndex][j];
			if (nowLoad.to == toIndex) {
				money = nowLoad.money;
				break;
			}
		}
		DFS(beforeNode[nowIndex][i], sum + money,aim);
	}
}

int main()
{
	while (true)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)break;
		init();
		for (int i = 0; i < m; i++)
		{
			int from, to, len, money;
			scanf("%d %d %d %d", &from, &to, &len, &money);
			from--; to--;
			EDGE[from].push_back(Load(from, to, len, money));
			EDGE[to].push_back(Load(to, from, len, money));
		}
		int start, end;
		scanf("%d %d", &start, &end);
		start--; end--;
		Dij(start);
		DFS(end, 0, start);
		cout << DISTANCE[end]<<" "<<minSum << endl;

	}

	return 0;
}
