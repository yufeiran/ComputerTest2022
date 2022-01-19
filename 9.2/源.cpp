#include<iostream> 
#include<queue>
using namespace std;

int bfs(int n)
{
	queue<long long>q;
	q.push(1);
	while (q.empty() == false)
	{
		long long now = q.front();
		q.pop();

		if (now % n == 0) {

			return now;
		}
		q.push(now * 10);
		q.push(now * 10 + 1);
	}
	
}

int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)break;
		cout << bfs(n) << endl;
	}
	return 0;
}