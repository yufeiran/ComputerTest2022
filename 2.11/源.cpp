#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)break;
		int step = 0;
		while (n != 1)
		{
			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				n = 3 * n + 1;
				n /= 2;
			}
			step++;
		}
		printf("%d\n", step);
	}

	return 0;
}