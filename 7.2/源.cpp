#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct ROOM
{

	int J; //JavaBean
	int F; //Food
	float rate;
};

vector<ROOM> RoomList;

bool cmp(const ROOM R1, const ROOM R2)
{
	if (R1.rate > R2.rate)return true;
	else return false;
}



int main()
{
	int M, N;
	while (1) {
		scanf("%d %d", &M, &N);
		if (M == -1 && N == -1)break;
		RoomList.clear();
		for (int i = 0; i < N; i++)
		{
			ROOM R;
			scanf("%d %d", &R.J, &R.F);
			R.rate = (float)R.J /(float) R.F;
			RoomList.push_back(R);

		}
		sort(RoomList.begin(),RoomList.end(), cmp);
		int nowLeft = M;
		float JaveBeanSum = 0;
		while (nowLeft != 0)
		{
			ROOM RNow = RoomList[0];
			RoomList.erase(RoomList.begin());
			if (nowLeft >= RNow.F)
			{
				JaveBeanSum += RNow.J;
				nowLeft -= RNow.F;
			}
			else {
				float per = (float)nowLeft / (float)RNow.F;
				JaveBeanSum += RNow.J * per;
				nowLeft = 0;
			}
		}
		printf("%.3f\n", JaveBeanSum);
	}
	


	return 0;
}