#include<iostream>

using namespace std;

int count(int index,int max)
{
	if (index > max) {
		return 0;
	}
	else {
		return 1 + count(index * 2, max) + count(index * 2 + 1, max);
	}
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << count(m, n) << endl;
	}

	return 0;
}