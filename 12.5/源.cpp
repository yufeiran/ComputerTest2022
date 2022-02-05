#include<iostream>
using namespace std;

const int MAX = 1001;
int dp[MAX];
int DATA[MAX];
int n;

int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> DATA[i];
			dp[i] = DATA[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (DATA[j] <= DATA[i])
				{
					dp[i] = max(dp[i], dp[j] + DATA[i]);
				}
				else
				{
					dp[i] = max(dp[i], DATA[i]);
				}
			}
		}
		int max = -1;
		for (int i = 0; i < n; i++)
		{
			if (max < dp[i])
			{
				max = dp[i];
			}
		}
		cout << max << endl;
	}

	return 0;
}