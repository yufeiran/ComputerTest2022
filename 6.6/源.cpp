#include<iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << (a * b) / gcd(a, b) << endl;
	/*

	int i = 1;
	while (1)
	{
		int now = i * a;
		if (now % b == 0)
		{
			cout << now << endl;
			break;
		}
		i++;
	}
	*/
	return 0;
}