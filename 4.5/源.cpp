#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int Count[26] = {};
string s;

int main()
{
	getline(cin, s);
	for (int i = 0; i < 26; i++)Count[i] = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int index = s[i] - 'A';
			Count[index]++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << (char)('A' + i) << ":" << Count[i] << endl;
	}

	return 0;

}