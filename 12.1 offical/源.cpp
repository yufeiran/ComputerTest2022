#include<iostream>
using namespace std;
const int MAX = 91;
long long DP[MAX]; 

int main()
{
	DP[0] = 0;
	DP[1] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << DP[n] << endl;
	return 0;
}