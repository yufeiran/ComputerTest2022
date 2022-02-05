#include<iostream>
using namespace std;

const int MAX = 100;
char A[MAX];
char B[MAX];
int DP[MAX][MAX];



int main()
{
	while (cin >> A >> B)
	{
		for (int i = 0; i < MAX; i++) {
			DP[i][0] = 0;
			DP[0][i] = 0;
		}
		for (int i = 0; i < strlen(A); i++)
		{
			for (int j = 0; j < strlen(B); j++)
			{
				if (A[i] == B[j])
				{
					DP[i + 1][j + 1] = DP[i][j] + 1;
				}
				else
				{
					DP[i + 1][j + 1] = max(DP[i + 1][j], DP[i][j + 1]);
				}
			}

		}
		cout << DP[strlen(A)][strlen(B)] << endl;
	}

	return 0;
}