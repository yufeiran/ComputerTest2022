#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

string raw;
stack<char>opStack;
string ans;


int main()
{
	cin >> raw;
	ans = raw;
	for (int i = 0; i < ans.size(); i++)
	{
		ans[i] = ' ';
	}

	
	for (int i = 0; i < raw.size(); i++)
	{
		if (raw[i] == '(')
		{
			opStack.push(i);
		}
		else if (raw[i] == ')')
		{
			if (opStack.empty() == true)
			{
				ans[i] = '?';
			}
			else
			{
				opStack.pop();
			}
		}
	}
	while (opStack.empty() == false)
	{
		ans[opStack.top()] = '$';
		opStack.pop();
	}

	cout << raw << endl;
	cout << ans << endl;
	return 0;
}