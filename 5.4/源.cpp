#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;


stack<string>S;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		S.push(temp);
	}

	for (int i = 0; i < n; i++)
	{
		cout << S.top();
		S.pop();
		if (S.empty() == false)cout << " ";
		else cout << endl;
	}



	return 0;
}