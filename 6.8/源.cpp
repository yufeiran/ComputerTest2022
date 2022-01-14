#include<iostream>
using namespace std;

const int MAX = 10001;
bool isPrime[MAX];



void calPrime()
{
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < MAX; i++)
	{
		if (isPrime[i] == true)
		{
			int now = i;
			while (now * i < MAX)
			{
				isPrime[now * i] = false;
				now++;
			}
		}
	}
}



int main()
{
	for (int i = 0; i < MAX; i++)isPrime[i] = true;
	calPrime();
	int n;
	
	while (cin >> n)
	{
		bool firstFlag = true;
		bool outputFlag = false;
		for (int i = 2; i < n; i++)
		{
			if (i % 10 == 1 && isPrime[i] == true)
			{
				if (firstFlag == true)
				{
					firstFlag = false;
				}
				else
				{
					cout << " ";
				}
				cout << i;
				outputFlag = true;
			}
		}
		if (outputFlag == false)cout << "-1";
		cout << endl;
	}

	return 0;
}