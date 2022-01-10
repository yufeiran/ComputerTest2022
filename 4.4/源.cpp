#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string>quiz;
vector<string>raw;
struct ANS {
	char DATA;
	int count;
};
vector<ANS> AnsList;


int main()
{
	while (1) {
		string s1, s2;
		getline(cin, s1);
		if (s1 == "#") {
			break;
		}
		getline(cin, s2);

		quiz.push_back(s1);
		raw.push_back(s2);
		for (int i = 0; i < s1.length(); i++)
		{
			int count = 0;
			for (int j = 0; j < s2.length(); j++)
			{
				if (s2[j] == s1[i])count++;
			}
			ANS a;
			a.DATA = s1[i];
			a.count = count;
			AnsList.push_back(a);
		}
	}
	for (int i = 0; i < AnsList.size(); i++)
	{
		cout << AnsList[i].DATA << " " << AnsList[i].count << endl;
	}
	

	return 0;
}