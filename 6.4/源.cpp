#include<iostream>
#include<string>

using namespace std;

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
	for (int i = 0; i < x - 1; i++)
	{
		sum = MULX(sum, base);
	}
	return sum;
}

string NToDEX(string raw, int N)
{
	string result = "0";
	for (int i = 0; i < raw.size(); i++)
	{
		if (raw[i] - '0' != 0)
		{
			string base = EXPX(N, raw.size() - 1 - i);
			string temp;
			if (raw[i] >= '0' && raw[i] <= '9')
			{
				temp = MULX(base, raw[i] - '0');
			}
			else if ((raw[i] >= 'a' && raw[i] <= 'z'))
			{
				temp = MULX(base, raw[i] - 'a'+10);
			}
			else if(raw[i] >= 'A' && raw[i] <= 'Z')
			{
				temp = MULX(base, raw[i] - 'A'+10);
			}
			result = ADD(temp, result);
		}
	}
	return result;
}

string DIVX(string raw, int X)
{
	int left = 0;
	for (int i = 0; i < raw.size(); i++)
	{
		int oldBit = raw[i] - '0';
		raw[i] = (oldBit + left * 10) / X + '0';
		left = (oldBit + left * 10) % X;
	}

	int index = 0;
	while (raw[index] == '0')
	{
		index++;
	}

	return raw.substr(index);
}

int MODX(string raw, int X)
{
	int left = 0;
	for (int i = 0; i < raw.size(); i++)
	{
		int oldBit = raw[i] - '0';
		raw[i] = (oldBit + left * 10) / X + '0';
		left = (oldBit + left * 10) % X;
	}
	return left;
}

string DEXToN(string raw, int N)
{
	string result;
	while (raw.empty() == false)
	{
		//cout << "raw " << raw << " DIVX " << DIVX(raw, N) << " MODX " << MODX(raw, N) << endl;
		int modtemp = MODX(raw, N);
		if (modtemp >= 0 && modtemp <= 9)
		{
			result.insert(result.begin(), modtemp + '0');
		}
		else if (modtemp >= 10 && modtemp <= 36)
		{
			result.insert(result.begin(), modtemp + 'a'-10);
		}
		raw = DIVX(raw, N);
		
	}
	return result;
}

int main()
{
	int M, N;
	cin >> M >> N;
	string X;
	cin >> X;
	string temp = NToDEX(X, M);

	cout << DEXToN(temp, N) << endl;

	return 0;
}