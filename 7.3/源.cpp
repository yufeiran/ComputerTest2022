#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>gun;
vector<int>monster;



int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		gun.clear();
		monster.clear();
		int gunSum = 0; int monsterSum = 0;
		scanf("%d %d", &gunSum, &monsterSum);
		for (int j = 0; j < gunSum; j++)
		{
			int temp;
			scanf("%d", &temp);
			gun.push_back(temp);
		}
		for (int j = 0; j < monsterSum; j++)
		{
			int temp;
			scanf("%d", &temp);
			monster.push_back(temp);
		}
		sort(gun.begin(), gun.end());
		sort(monster.begin(), monster.end());

		int bouns = 0;
		while (1)
		{
			int gunNow = gun[gun.size() - 1];
			gun.pop_back();
			int monsterNow = monster[0];
			monster.erase(monster.begin());
			if (gunNow >= monsterNow)
			{
				bouns += gunNow - monsterNow;
			}
			else {
				break;
			}
			if (gun.empty()) {
				break;
			}
		}
		printf("%d\n", bouns);


	}

	return 0;
}