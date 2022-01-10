#include<iostream>
using namespace std;

int Reverse(int a)
{
	int revx = 0;
	while (a != 0)
	{
		revx *= 10;
		revx += a % 10;
		a /= 10;
	}
	return revx;
}
int main()
{
	for (int i = 0; i <= 256; i++)
	{
		if (i * i == Reverse(i * i))
		{
			cout << i << endl;
		}
	}

	return 0;
}