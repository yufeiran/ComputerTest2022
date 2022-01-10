#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string s;

int main()
{

	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] < 'z') {
			s[i]++;
		}
		else if (s[i] >= 'A' && s[i] < 'Z') {
			s[i]++;
		}
		else if (s[i] == 'z') {
			s[i] = 'a';
		}
		else if (s[i] == 'Z') {
			s[i] = 'A';
		}
	}
	cout << s << endl;

	return 0;
}