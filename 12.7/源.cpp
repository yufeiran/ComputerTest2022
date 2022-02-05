#include<iostream>
using namespace std;

const int MAX_C = 1001;
const int MAX_N = 101;
int DP[MAX_N][MAX_C];
int c, n;
int Weight[MAX_N];
int Value[MAX_N];


int main()
{
	while (cin >> c >> n)
	{
		for (int i = 0; i < n; i++)
		{
			DP[i][0] = 0;
			cin >> Weight[i+1];
			cin >> Value[i+1];
		}
		for (int i = 0; i < c; i++)
		{
			DP[0][i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= c; j++)
			{
				if (j - Weight[i] >= 0) {
					DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - Weight[i]] + Value[i]);
				}
				
			}
		}
		cout << DP[n][c] << endl;
	}
	return 0;
}