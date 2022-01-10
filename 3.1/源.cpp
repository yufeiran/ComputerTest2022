#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		v.push_back(data);
	}
	sort(v.begin(), v.end());
	for (auto i=v.begin();i!=v.end();i++)
	{
		printf("%d", *i);
		printf(" ");
		if (i != v.end()) {
			
		}
		else {
			printf("\n");
		}
	}

	return 0;
}