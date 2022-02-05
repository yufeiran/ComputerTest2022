#include<iostream>
#include<vector>
using namespace std;
const int MAX = 10000;
const int MAX_N = 1000;
int V[MAX];
int W[MAX];
int DP[MAX_N][MAX];
int value[MAX];
int weight[MAX];
int sum[MAX];
int N, M;


int DToB(int N)
{
	int sum = 0;
	int exp = 0; 
	while (N != 0)
	{
		
		if (N % 2 != 0) {
			sum += pow(10, exp);
		}
		exp++;
		N /= 2;
	}
	return sum;
}

int main()
{

	int n;
	cin >> n;
	while (n > 0)
	{
		n--;
		cin >> N >> M;
		for (int i = 1; i <= M; i++)
		{
			cin >> value[i] >> weight[i] >> sum[i];
		}
		int nowIndex = 1;
		for (int i = 1; i <= M; i++)
		{
			int nowLeft = sum[i];
			int nowLevel = 0;
			while (nowLeft != 0)
			{
				if (nowLeft % 2 != 0) {
					V[nowIndex] = value[i] * pow(2, nowLevel);
					W[nowIndex] = weight[i] * pow(2, nowLevel);
					nowIndex++;
				}
				nowLevel++;
				nowLeft /= 2;
			}
		}
		for (int i = 0; i <= nowIndex; i++)
		{
			DP[i][0] = 0;
		}
		for (int i = 0; i <= N; i++)
		{
			DP[0][i] = 0;
		}
		for (int i = 1; i <= nowIndex; i++)
		{
			for (int j = V[i]; j <= N; j++)
			{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - V[i]] + W[i]);
			}
		}
		cout << DP[nowIndex][N] << endl;
	}

	return 0;
}