#include<iostream>
#include<string>

using namespace std;

string raw;

string Data;

string DIVX(string raw,int X)
{
	int left = 0;
	for (int i = 0; i < raw.size(); i++)
	{
		int oldBit = raw[i] - '0';
		raw[i] = (oldBit + left*10) / X + '0';
		left = (oldBit + left*10) % X;
	}

	int index = 0;
	while (raw[index] == '0')
	{
		index++;
	}

	return raw.substr(index);
}

string MOD2(string raw)
{
	if (raw[raw.size() - 1] % 2 == 0) {
		return "0";
	}
	else {
		return "1";
	}
}

string ADD(string a, string b)
{
	int lenA = a.size();
	int lenB = b.size();
	if (lenA > lenB)
	{
		b.insert(b.begin(), lenA - lenB, '0');
	}
	else if (lenA < lenB)
	{
		a.insert(a.begin(), lenB - lenA, '0');
	}
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		int abit = a[i] - '0';
		int bbit = b[i] - '0';
		int cbit = (abit + bbit + carry) % 10;
		carry = (abit + bbit + carry) / 10;
		a[i] = cbit + '0';
	}
	if (carry == 1)
	{
		a.insert(a.begin(), '1');
	}
	return a;
}

string MULX(string raw, int x)
{
	string sum = "0";
	for (int i = 0; i < x; i++)
	{
		sum = ADD(sum, raw);
	}
	return sum;
}

string EXPX(int base, int x)
{
	if (x == 0)
	{
		return "1";
	}
	string sum = "0";
	sum[0] += base;
	for (int i = 0; i < x-1; i++)
	{
		sum = MULX(sum, base);
	}
	return sum;
}

string BToDec(string bString)
{
	string sum = "0";
	for (int i = 0; i < bString.size(); i++)
	{
		if (bString[i] == '1')
		{
			string temp = EXPX(2, bString.size() - 1 - i);
			sum = ADD(sum, temp);
		}
	}
	return sum;
}

int main()
{

	cin >> raw;
	
	while (raw.empty()==false)
	{
		//cout<<"raw "<<raw << " DIV " << DIVX(raw, 2) << " MOD2 " << MOD2(raw) << endl;
		Data.insert(Data.end(), MOD2(raw)[0]);
		raw = DIVX(raw, 2);
		
	}
	//cout << Data << endl;
	cout << BToDec(Data) << endl;


	return 0;
}