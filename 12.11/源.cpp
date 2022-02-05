#include<iostream> 

using namespace std;

const int MAX = 1001;
int DP[MAX][MAX];
int DATA[MAX][MAX];

int n, N,row;

int main()
{
	cin >> n;
	int count = 1;
	while (n != 0)
	{
		n--;
		cin >> N;
		row = 2 * N - 1;
		memset(DATA, 0, sizeof(DATA));
		memset(DP, 0, sizeof(DP));
		for (int i = 0; i < row; i++)
		{
			if (i < N)
			{
				for (int j = 0; j <= i; j++)
				{
					cin >> DATA[i][j];
				}
			}
			else
			{
				int nowN = 2 * N - 1 - i;
				for (int j = 0; j < nowN; j++)
				{
					cin >> DATA[i][j];
				}
			}
		}
		DP[row - 1][0] = DATA[row - 1][0];
		for (int i = row - 2; i >= 0; i--)
		{
			for (int j = 0; j < row - 1; j++)
			{
				if (i < N-1) {
					DP[i][j] = max(DP[i + 1][j], DP[i + 1][j + 1]) + DATA[i][j];
				}
				else {
					if (j - 1 >= 0) {
						DP[i][j] = max(DP[i + 1][j], DP[i + 1][j - 1]) + DATA[i][j];
					}
					else {
						DP[i][j] = DP[i + 1][j] + DATA[i][j];
					}
					
				}
				
			}
		}
		cout <<"Case "<<count<<": " << DP[0][0] << endl;
		count++;

	}

	return 0;
}