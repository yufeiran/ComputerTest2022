#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct STU {
	int id;
	string name;
	int score;
};

vector<STU>v;

int mode;

bool cmp(STU s1, STU s2)
{
	if (s1.score == s2.score)
	{
		if (s1.id < s2.id)
		{
			return true;
		}
		return false;
	}
	else if (mode == 0) //½µÐò
	{
		if (s1.score > s2.score)return true;
		else return false;
	}
	else if (mode == 1) //ÉýÐò
	{
		if (s1.score < s2.score)return true;
		else return false;
	}

}

int main()
{
	int N;

	cin >> N;
	cin >> mode;
	for (int i = 0; i < N; i++)
	{
		STU s;
		s.id = i;
		cin >> s.name;
		cin >> s.score;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++)
	{
		cout << v[i].name << " " << v[i].score << endl;
	}

	return 0;
}