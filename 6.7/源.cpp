#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int a)
{
	if (a == 0 || a == 1)
	{
		return false;
	}
	else {
		int max = sqrt(a);
		for (int i = 2; i <= max; i++)
		{
			if (a % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int a;
	while (cin >> a)
	{
		if (isPrime(a) == true)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}

	return 0;
}