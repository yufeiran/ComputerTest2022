#include<iostream>
#include<queue>
using namespace std;

struct ROAD
{
	int pos, time;
};

const int MAX = 100001;

bool visit[MAX];

int bfs(int N, int K)
{
	memset(visit, false, sizeof(visit));
	int minTime = 99999999;
	queue<ROAD>roadList;
	ROAD r;
	r.pos = N; r.time = 0;
	roadList.push(r);
	while (roadList.empty() == false)
	{
		ROAD nowR = roadList.front();
		visit[nowR.pos] = true;
		roadList.pop();
		if (nowR.pos == K && minTime > nowR.time)
		{
			minTime = nowR.time;
		}
		ROAD r1, r2, r3;
		if (nowR.pos - 1 >= 0 && nowR.pos-1 <= 100000)
		{
			
			r1.pos = nowR.pos - 1;
			r1.time = nowR.time + 1;
			if(visit[r1.pos]==false) roadList.push(r1);
		}
		if (nowR.pos + 1 >= 0 && nowR.pos+1 <= 100000)
		{
			r2.pos = nowR.pos + 1;
			r2.time = nowR.time + 1;
			if (visit[r2.pos] == false)roadList.push(r2);
		}
		if (nowR.pos * 2 >= 0 && nowR.pos *2<= 100000)
		{
			r3.pos = nowR.pos * 2;
			r3.time = nowR.time + 1;
			if (visit[r3.pos] == false)roadList.push(r3);
		}
	}
	return minTime;
}


int main()
{
	int N, K;
	cin >> N >> K;
	cout << bfs(N, K) << endl;

	return 0;
}