#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

string A, B;


int main()
{
	while(cin >> A >> B)
	{
		long long SUM = 0;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < B.size(); j++)
			{
				SUM += (A[i] - '0') * (B[j] - '0');
			}
		}
		cout << SUM << endl;
	}
	return 0;
}