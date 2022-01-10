#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> quiz;

bool findFlag = false;


//递归版本 二分查找
void binarySearch(int left, int right,int aim)
{
	if (left > right)return;
	int mid = (left + right) / 2;
	if (v[mid] == aim) {
		printf("YES\n");
		findFlag = true;
		return;
	}
	else {
		if (aim > v[mid]) {
			binarySearch(mid + 1, right, aim);
		}
		else if (aim < v[mid]) {
			binarySearch(left, mid - 1, aim);
		}
	}
	
}

//非递归版本 二分查找
bool BinarySearch(int N, int target)
{
	int left = 0;
	int right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target == v[mid]) {
			return true;
		}
		else if (target > v[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

int main()
{
	int n, m;
	
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			int data;
			scanf("%d", &data);
			v.push_back(data);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int data;
			scanf("%d", &data);
			quiz.push_back(data);
		}
		sort(v.begin(), v.end());

		//binary search
		for (int i = 0; i < m; i++)
		{
			int aim = quiz[i];

			/*
			findFlag = false;
			binarySearch(0, n - 1, aim);
			if (findFlag == false) {
				printf("NO\n");
			}
			*/
			if (BinarySearch(n, aim)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}

		}
	}



	return 0;
}