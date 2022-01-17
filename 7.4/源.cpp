#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

struct NODE {
	int start;
	int end;
};

vector<NODE> nodeList;

bool cmp(const NODE N1, const NODE N2)
{
	if (N1.end < N2.end)return true;
	else return false;
}

int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			NODE Node;
			cin >> Node.start >> Node.end;
			nodeList.push_back(Node);
		}
		sort(nodeList.begin(), nodeList.end(), cmp);
		int nowTime = 0;
		int count = 0;
		while (nodeList.empty()==false)
		{
			NODE nowNode = nodeList[0];
			nodeList.erase(nodeList.begin());
			if (nowNode.start >= nowTime)
			{
				count++;
				nowTime = nowNode.end;
			}
		}
		cout << count << endl;
	}

	return 0;
}