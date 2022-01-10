#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int MAX = 100000;
int NEXT[MAX+1];

void makeNext(string quiz)
{

	for (int i = 1; i <=quiz.length(); i++)
	{
		//生成前后缀
		vector<string>start;
		vector<string>end;
		for (int j = 1; j < i; j++)
		{
			string sFirst, sEnd;
			sFirst = quiz.substr(0, j);
			sEnd = quiz.substr(i - j, j);
			start.push_back(sFirst);
			end.push_back(sEnd);
		}
		//找start 和 end 共同的子串
		int maxLen = 0;
		for (int j = 0; j < start.size(); j++)
		{
			auto ans= find(end.begin(), end.end(), start[j]);
			if (ans != end.end())
			{
				if ((*ans).length() > maxLen)
				{
					maxLen = (*ans).length();
				}
			}
		}
		NEXT[i] = maxLen;

	}
	NEXT[1] = -1;
	NEXT[0] = -1;


}

int kmp(string quiz, string raw)
{
	int i, j;
	i = 0;
	j = 0;
	while (i < raw.size() && j < quiz.size())
	{
		if (j == -1 || raw[i] == quiz[j]) {  //字符串匹配成功
			i++;
			j++;
		}
		else {
			j = NEXT[j];  //匹配失败
		}

	}
	if (j == quiz.size()) {
		return i - j + 1;	//匹配成功
	}
	else {
		return -1;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n, m;
		cin >> n >> m;
		string raw, quiz;
		for (int j = 0; j < n; j++)
		{
			char data;
			cin >> data;
			raw.insert(raw.end(),data);

		}
		for (int j = 0; j < m; j++)
		{
			char data;
			cin >> data;
			quiz.insert(quiz.end(), data);
		}
		makeNext(quiz);
		
		cout << kmp(quiz, raw) << endl;
	}
	return 0;
}