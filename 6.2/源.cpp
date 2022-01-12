#include<iostream>
#include<string>

using namespace std;

string DIV2(string raw)
{
	string result;
	//从高位开始除
	int left = 0;
	for (int i = 0; i<raw.size(); i++)
	{
		int oldBit = raw[i] - '0';
		raw[i] = (oldBit +left*10) / 2+'0';
		left = (oldBit + left * 10) % 2;
	}
	//去多余的0
	if (raw.size() > 1 && raw[0] == '0')
	{
		raw=raw.substr(1, raw.size() - 1);
	}
	return raw;
}

string MOD2(string raw)
{
	if ((raw[raw.size() - 1] - '0') % 2 == 0) {
		string result = "0";
		return result;
	}
	else {
		string result = "1";
		return result;
	}
}

int main()
{
	string Data;
	string Result;
	while (cin >> Data)
	{
		Result.clear();
		while (Data != "0")
		{
			//cout << "DIV2 " << DIV2(Data) << " MOD2 " << MOD2(Data) << endl;
			Result.insert(Result.begin(), MOD2(Data)[0]);
			Data = DIV2(Data);
			
		}

		
		if (Result.empty()) {
			cout << "0" << endl;
		}
		else{
			cout << Result << endl;
		}
	}

	return 0;
}