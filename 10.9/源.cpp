#include<iostream>
#include<map>
using namespace std;
map<string, int> dict;

string raw;

void findkey(string oldkey, int index,int maxlen)
{
	if (oldkey.size() == maxlen) {
		return;
	}
	if (index == 0) {
		oldkey += "0";
	}
	else {
		oldkey += "1";
	}
	dict[oldkey] = 0;
	int pos = string::npos; 
	while (true)
	{
		pos = raw.find(oldkey, pos+1);
		if (pos != string::npos) {
			dict[oldkey]++;
		}
		else {
			break;
		}
	}
	if (dict[oldkey] > 1) {
		cout << oldkey << " " << dict[oldkey] << endl;
	}
	findkey(oldkey, 0,maxlen);
	findkey(oldkey, 1,maxlen);
}


int main()
{

	cin >> raw;

	//Éú³Ékey
	findkey("", 0, raw.size() - 1);
	findkey("", 1, raw.size() - 1);

	return 0;
}