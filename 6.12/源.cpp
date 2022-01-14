#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAX = 10;

struct Martix
{
	int n;
	long long DATA[MAX][MAX];
};

Martix MUL(Martix A, Martix B)
{
	int len = A.n;
	Martix C;
	C.n = len;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			int sum = 0;
			for (int k = 0; k < len; k++)
			{
				sum += A.DATA[i][k] * B.DATA[k][j];
			}
			C.DATA[i][j] = sum;
		}
	}
	return C;
}

Martix ME(int n)
{
	Martix C;
	C.n = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				C.DATA[i][j] = 1;
			}
			else
			{
				C.DATA[i][j] = 0;
			}
		}
	}
	return C;
}

Martix FastMulMartix(Martix A, int n)
{
	Martix B = ME(A.n);
	while (n != 0)
	{
		if (n % 2 == 1)
		{
			B = MUL(B, A);

		}
		A = MUL(A, A);
		n /= 2;
	}
	return B;
}

int main()
{
	Martix A;
	int p;
	cin >> A.n >> p;
	for (int i = 0; i < A.n; i++)
	{
		for (int j = 0; j < A.n; j++)
		{
			cin >> A.DATA[i][j];
		}
	}
 	Martix C = FastMulMartix(A, p);
	for (int i = 0; i < C.n; i++)
	{
		for (int j = 0; j < C.n; j++)
		{
			cout << C.DATA[i][j];
			if (j != C.n-1)cout << " ";
			else cout << endl;
		}
	}


	return 0;
}