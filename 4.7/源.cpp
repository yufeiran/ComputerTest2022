#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int MAX = 100000;
int NEXT[MAX + 1];

void makeNext(string quiz)
{

	for (int i = 1; i <= quiz.length(); i++)
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
			auto ans = find(end.begin(), end.end(), start[j]);
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


//稍微修改的KMP 从start位置开始匹配
int kmp(string quiz, string raw,int start)
{
	int i, j;
	i = start;
	j = 0;
	while ((i < (int)raw.size()) &&( j <(int) quiz.size()))
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
		string quiz, raw;
		cin >> quiz;
		cin >> raw;
		makeNext(quiz);

		int nowPos = 0;
		int Count = 0;
		while (1)
		{
			int index = kmp(quiz, raw,nowPos);
			if (index != -1)
			{
				Count++;
				nowPos = index;
			}
			else {
				break;
			}

		}
		cout << Count << endl;


	}
	return 0;
}