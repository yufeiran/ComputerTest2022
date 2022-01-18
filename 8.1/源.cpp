#include<iostream>

using namespace std;


long long fac(long long raw, int n)
{
	if (n == 1)
	{
		return raw;
	}
	else {
		return fac(raw * n, n - 1);
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << fac(1, n) << endl;
		
	}

	return 0;
}