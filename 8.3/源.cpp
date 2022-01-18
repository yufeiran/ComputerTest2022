#include<iostream>

using namespace std;

int fac(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else {
		return fac(n - 1) + fac(n - 2);
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << fac(n) << endl;
	}

	return 0;
}