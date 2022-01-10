#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string key = "VWXYZABCDEFGHIJKLMNOPQRSTU";


int main()
{
	for (int i = 0; i < 100; i++)
	{
		string cmd;
		getline(cin, cmd);
		if (cmd == "START") {
			string raw;
			getline(cin, raw);
			for (int i = 0; i < raw.length(); i++)
			{
				if (raw[i] >= 'A' && raw[i] <= 'Z')
				{
					
					int index = raw[i] - 'A';
					raw[i] = key[index];
				}
			}
			cout << raw;
			string cmd2;
			getline(cin, cmd2);
			if (cmd2 == "END") {

			}
			else {
				break;
			}
		}
		else if (cmd == "ENDOFINPUT") {
			break;
		}
	}

	return 0;
}