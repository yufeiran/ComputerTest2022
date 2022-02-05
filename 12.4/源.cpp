#include<iostream>
using namespace std;

const int MAX = 26;
int dp[MAX];
int DATA[MAX];

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1;
			cin >> DATA[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (DATA[j] >= DATA[i])
				{
					dp[i] = max(dp[i], dp[j] + 1); 
				}
				else
				{
					dp[i] = max(1, dp[i]);
				}
			}
		}
		int max = -1;
		for (int i = 0; i < n; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
			}
		}
		cout << max << endl;
	}
	
	return 0;
}