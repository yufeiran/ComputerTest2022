#include<iostream>
#include<climits>
using namespace std;

const int MAX = 1000001;
long long DATA[MAX];
long long DP[MAX];


int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> DATA[i];
		}
		DP[0] = DATA[0];
		for (int i = 1; i < n; i++)
		{
			DP[i] = max(DATA[i], DP[i - 1] + DATA[i]);
		}
		long long MAX = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			if (MAX < DP[i])
				MAX = DP[i];
		}
		cout << MAX << endl;
	}
	
	

	return 0;
}