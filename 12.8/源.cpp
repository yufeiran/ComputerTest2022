#include<iostream>
#include<climits>
using namespace std;

const int MAX_F = 10001;
const int MAX_N = 501;

int DP[MAX_N][MAX_F];

int E, F, N;
int TotalW;
int V[MAX_N];
int W[MAX_N];
int MAX = INT_MAX / 10;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> E >> F;
		TotalW = F - E;
		cin >> N;
		for (int k = 0; k < N; k++)
		{
			cin >> V[k+1] >> W[k+1];

		}

		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= TotalW; k++)
			{

				DP[j][k] = MAX;
			}
			DP[j][0] = 0;
		}

		

		for (int j = 1 ; j <= N; j++)
		{
			for (int k = W[j]; k <= TotalW; k++)
			{
				DP[j][k] = min(DP[j - 1][k], DP[j][k - W[j]] + V[j]);

			}
		}
		if (DP[N][TotalW] != MAX)cout << "The minimum amount of money in the piggy-bank is " << DP[N][TotalW] << "." << endl;
		else cout << "This is impossible." << endl;
	}
	return 0;
}