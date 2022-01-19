#include<iostream>
#include<vector>
using namespace std;

const int MAX = 21;
bool used[MAX];
vector<int>stick;
bool findFlag = false;
vector<int>way;
vector<int>finWay;
int aimLen = 0;
int aimCount = 0;

void init()
{
	memset(used, false, sizeof(used));
	stick.clear();
	way.clear();
	finWay.clear();
	aimLen = 0;
	aimCount = 0;
	findFlag = false;
	

}

int calSum()
{
	int sum = 0;
	for (int i = 0; i < stick.size(); i++)
	{
		sum += stick[i];
	}
	return sum;
}

void out(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void DFS(int index, int sum)
{
	used[index] = true;
	way.push_back(index);
	sum += stick[index];

	if (sum == aimLen)
	{
		findFlag = true;
		finWay = way;

	}
	else if(findFlag==false) {
		for (int i = 0; i < stick.size(); i++)
		{
			if (used[i] == false) {
				DFS(i, sum);
			}
		}
	}
	used[index] = false;
	way.pop_back();
}

void markUsed(vector<int>way)
{
	for (int i = 0; i < way.size(); i++)
	{
		used[way[i]] = true;
	}
}

void FIND()
{
	for (int i = 0; i < 4; i++)
	{
		findFlag = false;
		for (int k = 0; k < stick.size(); k++)
		{
			if (used[k] == false)
			{
				DFS(k, 0);
				if (findFlag == true)
				{
					markUsed(finWay);
					aimCount++;
				}
				break;
			}
		}
	}
	if (aimCount == 4) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		init();
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int len;
			cin >> len;
			stick.push_back(len);
		}
		int sum = calSum();
		if (sum % 4 != 0)
		{
			cout << "no" << endl;
		}
		else
		{
			aimLen = sum / 4;
			FIND();
		}
	}

	return 0;
}