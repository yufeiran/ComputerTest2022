#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<iomanip>
using namespace std;


stack<char>opStack;
stack<float>dataStack;

int Priority(char c)
{
	if (c == '#')
		return 0;
	else if (c == '$')
		return 1;
	else if (c == '+')
		return 2;
	else if (c == '-')
		return 3;
	else if (c == '*')
		return 4;
	else if (c == '/')
		return 5;
}


int getDigital(string raw, int &start)
{
	int sum = 0;
	int i = start;
	while (1)
	{
		if (raw[i] >= '0' && raw[i] <= '9')
		{
			sum *= 10;
			sum += raw[i] - '0';
			i++;
		}
		else break;
	}
	start = i-1;
	return sum;
}

float cal(float a, float b, char op)
{
	if (op == '+')
	{
		return a + b;
	}
	if (op == '-')
	{
		return a - b;
	}
	if (op == '*')
	{
		return a * b;
	}
	if (op == '/')
	{
		return a / b;
	}
}

int main()
{
	while (1)
	{
		string raw;
		getline(cin, raw);
		if (raw == "0")break;
		raw.push_back('$');
		opStack.push('#');
		int len = raw.size();
		for (int i = 0; i <len; i++)
		{
			if (raw[i] >= '0' && raw[i] <= '9')
			{
				int data = getDigital(raw, i);
				dataStack.push(data);
			}
			else if (raw[i] == '+' || raw[i] == '-' || raw[i] == '*' || raw[i] == '/'||raw[i]=='$')
			{
				while (1) {
					int nowPriority = Priority(raw[i]);
					int topPriority = Priority(opStack.top());
					if (opStack.size() == 2 && opStack.top() == '$')
					{
						break;
					}
					if (nowPriority > topPriority)
					{
						opStack.push(raw[i]);
						break;
					}
					else {
						float b = dataStack.top();
						dataStack.pop();
						float a = dataStack.top();
						dataStack.pop();
						char op = opStack.top();
						opStack.pop();
						float c = cal(a, b, op);
						dataStack.push(c);
					}
				}
			
			}
		}
		cout << setiosflags(ios::fixed);

		cout<<setprecision(2) << dataStack.top() << endl;
		//printf("%.2f\n", dataStack.top()); //c 风格的输出，比c++的输出格式控制更简单
		dataStack.pop();

	}
}