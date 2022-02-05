#include<iostream>
using namespace std;

const int MAX = 101;

int DP[MAX][MAX];
int n;
int DATA[MAX][MAX];


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> DATA[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		DP[n - 1][i] = DATA[n - 1][i];
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			DP[i][j] = max(DP[i + 1][j], DP[i + 1][j + 1]) + DATA[i][j];
		}
	}
	cout << DP[0][0] << endl;
	return 0;
}