#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

struct Animal {
	int order;
	int id;
	Animal(int Order, int Id) :order(Order), id(Id) {}
	Animal();
};

queue<Animal>CatQ;
queue<Animal>DogQ;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int cmd1, cmd2;
		cin >> cmd1 >> cmd2;
		if (cmd1 == 1)
		{
			if (cmd2 > 0)
			{
				Animal dog(i, cmd2);

				DogQ.push(dog);
			}
			else if (cmd2 < 0)
			{
				Animal cat(i,cmd2);

				CatQ.push(cat);
			}
		}
		else if (cmd1 == 2)
		{
			if (cmd2 == 0)
			{
				if (DogQ.front().order < CatQ.front().order)
				{
					if (DogQ.empty() == false)
					{
						cout << DogQ.front().id;
						DogQ.pop();
						if (DogQ.empty() == false || CatQ.empty() == false)cout << " ";
						else cout << endl;
					}
				}
				else
				{
					if (CatQ.empty() == false)
					{
						cout << CatQ.front().id;
						CatQ.pop();
						if (DogQ.empty() == false || CatQ.empty() == false)cout << " ";
						else cout << endl;
					}

				}
			}
			else if (cmd2 == 1)
			{
				if (DogQ.empty() == false)
				{
					cout << DogQ.front().id;
					DogQ.pop();
					if (DogQ.empty() == false || CatQ.empty() == false)cout << " ";
					else cout << endl;
				}
			}
			else if (cmd2 == -1)
			{
				if (CatQ.empty() == false)
				{
					cout << CatQ.front().id;
					CatQ.pop();
					if (DogQ.empty() == false || CatQ.empty() == false)cout << " ";
					else cout << endl;
				}
			}

		}
	}

	return 0;
}