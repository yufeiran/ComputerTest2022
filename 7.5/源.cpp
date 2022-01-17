#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ISLAND
{
	int start;
	int end;
};

struct DISTANCE
{
	int min;
	int max;
};

struct BRIDGE
{
	int use; //1 used
	int len;
	int index;
};

vector<ISLAND>islandList;
vector<DISTANCE>distanceList;
vector<BRIDGE>bridgeList;
vector<int>order;


bool cmp(const BRIDGE B1, const BRIDGE B2)
{
	if (B1.len >= B2.len)return true;
	else return false;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		ISLAND newISLAND;
		cin >> newISLAND.start >> newISLAND.end;
		islandList.push_back(newISLAND);
	}
	for (int i = 0; i < m; i++)
	{
		BRIDGE B;
		B.index = i+1;
		cin >> B.len;
		bridgeList.push_back(B);
	}

	for (int i = 0; i < n - 1; i++)
	{
		ISLAND I1, I2;
		I1 = islandList[i];
		I2 = islandList[i + 1];
		DISTANCE D;
		D.min = I2.start - I1.end;
		D.max = I2.end - I1.start;
		distanceList.push_back(D);
	}

	sort(bridgeList.begin(), bridgeList.end(),cmp);
	//选最大的桥 
	int nowindex = 0;
	while (true)
	{
		DISTANCE nowDistance = distanceList[nowindex];
		bool findFlag = false;
		for (int i = 0; i < bridgeList.size(); i++)
		{
			if (bridgeList[i].len >= nowDistance.min && bridgeList[i].len <= nowDistance.max)
			{
				findFlag = true;
				order.push_back(bridgeList[i].index);
				bridgeList.erase(bridgeList.begin() + i);
				nowindex++;
			}
		}
		if (findFlag == false) {
			break;
		}
		if (nowindex == n - 1)
		{
			break;
		}
	}
	if (order.size() != n - 1) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		for (int i = 0; i < order.size(); i++)
		{
			cout << order[i];
			if (i != order.size() - 1)cout << " ";
			else cout << endl;
		}
	}


	return 0;
}