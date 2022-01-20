#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;

struct node
{
	float a;
	float b;
	float m;
	node(int A, int B) :a(A), b(B), m(sqrt(A* A + B * B)) {};
	bool operator<(node n2) const {
		if (m > n2.m)return true;
		else return false;
	}
};

priority_queue<node> mQueue;


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string cmd1, cmd2;
		cin >> cmd1;
		if (cmd1 == "Pop")
		{
			if (mQueue.empty())
			{
				cout << "empty" << endl;
			}
			else {
				node nowNode = mQueue.top();
				mQueue.pop();
				cout << nowNode.a << "+i" << nowNode.b << endl;
				cout << "SIZE = " << mQueue.size() << endl;
			}
		}
		else if (cmd1 == "Insert")
		{
			cin >> cmd2;
			int index=cmd2.find("+i");
			string sA, sB;
			sA = cmd2.substr(0, index);
			sB = cmd2.substr(index + 2);
			int iA, iB;
			iA = atoi(sA.data());
			iB = atoi(sB.data());
			node newNode = node(iA, iB);
			mQueue.push(newNode);
			cout << "SIZE = " << mQueue.size() << endl;
			
		}
	}
	return 0;
}