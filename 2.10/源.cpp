#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

int keyTab[26] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,
2,3,1,2,3,4,1,2,3,1,2,3,4 };

int main()
{
	string s;
	while (cin >> s)
	{
		int time = 0;
		for (int i = 0; i < s.size(); i++)
		{
			time += keyTab[s[i] - 'a'];
			if (i != 0 && s[i] - s[i - 1] == keyTab[s[i] - 'a'] - keyTab[s[i - 1] - 'a']) {
				time += 2;
			}
		}
		cout << time << endl;
	}

	return 0;
}