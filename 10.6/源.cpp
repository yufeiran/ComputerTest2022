#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue <int, vector<int>, greater<int>>myQueue;
	
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		myQueue.push(temp);
	}
	int ans = 0;
	while (myQueue.size() > 1)
	{
		int n1 = myQueue.top();
		myQueue.pop();
		int n2 = myQueue.top();
		myQueue.pop();
		ans += n1 + n2;
		myQueue.push(n1 + n2);
	}
	cout << ans << endl;

	return 0;
}