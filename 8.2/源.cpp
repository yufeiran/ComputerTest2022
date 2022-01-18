#include<iostream>


using namespace std;

long long cal(int n)
{
	if (n == 1)
	{
		return 2;
	}
	else {
		return 3 * cal(n - 1) + 2;
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << cal(n) << endl;
	}

	return 0;

}