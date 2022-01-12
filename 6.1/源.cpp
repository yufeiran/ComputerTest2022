#include<iostream>
#include<string>

using namespace std;

string Data;



int main()
{
	int n;
	cin >> n;
	
	while (n != 0)
	{
		Data.insert(Data.begin(), (n % 2)+'0');
		n = n / 2;
	}
	int index = -1;
	for (int i = 0; i < Data.length(); i++)
	{
		if (Data[i] == '0')
		{
			index = i;
		}
		else {
			break;
		}
	}
	Data = Data.substr(index + 1, Data.size() - (index + 1));
	cout << Data << endl;

	return 0;
}