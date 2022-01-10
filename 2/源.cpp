#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

bool isAnt(int a, int b)
{
	if (b > 9999)return false;
	char A[5], B[5];
	sprintf(A, "%d", a);
	sprintf(B, "%d", b);

	for (int i = 0; i < 4; i++)
	{
		if (A[i] != B[3 - i])
		{
			return false;
		}
	}
	return true;
}


//Ïà·´Êý
int Reverse(int x)
{
	int revx = 0;
	while (x != 0)
	{
		revx *= 10;
		revx += x % 10;
		x /= 10;
		
	}
	return revx;
}
int main()
{

	cout << Reverse(1234) << endl;
	for (int i = 1000; i <= 9999; i++)
	{
		if (isAnt(i, i * 9) == true)
		{
			cout << i << endl;
		}
	}

	return 0;
}