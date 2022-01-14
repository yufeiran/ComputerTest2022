#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

int FastExponentiation(int a, int b, int mod)
{
	int answer = 1;
	while (b != 0)
	{
		if (b % 2 == 1)
		{
			answer *= a;
			answer = answer % mod;
		}
		b /= 2;
		a *= a;
		a %= mod;

	}
	return answer;
}


int main()
{
	while (1)
	{
		int A, B;
		cin >> A >> B;
		if (A == 0 && B == 0)break;
		cout << FastExponentiation(A, B, 1000) << endl;


	}

	return 0;
}