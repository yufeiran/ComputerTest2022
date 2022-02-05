#include<iostream>
#include<climits>
using namespace std;
const int MAX = 101;
int DATA[MAX][MAX];
int DP[MAX][MAX];
int n;

int CAL(int i, int j)
{
	int dp[MAX];
	if (i == j)
	{
		dp[0] = DATA[i][0];
		for (int k = 1; k < n; k++)
		{
			dp[k] = max(DATA[i][k], dp[k - 1] + DATA[i][k]);
		}

	}
	else {
		int temp = 0;
		for (int k = i; k <= j; k++)
		{
			temp += DATA[0][k];
		}
		dp[0] = temp;
		for (int k = 1; k < n; k++)
		{
			int temp = 0;
			for (int l = i; l <= j; l++)
			{
				temp += DATA[k][l];
			}
			dp[k] = max(temp, temp + dp[k - 1]);
		}

	}
	int max = INT_MIN;
	for (int k = 0; k < n; k++)
	{
		if (max < dp[k])
		{
			max = dp[k];
		}

	}
	return max;

}



int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> DATA[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i <=j; i++)
		{
			DP[i][j] = CAL(i, j);
		}
	}
	int max = INT_MIN;
	for (int j = 0; j < n; j++)
	{
		for (int i= 0; i <= j; i++)
		{
			if (max < DP[i][j])
			{
				max = DP[i][j];
			}
		}
	}
	cout << max << endl;

	return 0;
}