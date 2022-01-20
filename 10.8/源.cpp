#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string, string>BOOK;
map<string, string>RBOOK;



int main()
{

	while(true)
	{
		string cmd;
		getline(cin, cmd);
		if (cmd == "@END@") {
			break;
		}
		int pos = cmd.find("]");
		string cmd1, cmd2;
		cmd1 = cmd.substr(1, pos-1);
		cmd2 = cmd.substr(pos + 2);
		BOOK[cmd1] = cmd2;
		RBOOK[cmd2] = cmd1;
	}
	string sm;
	getline(cin, sm);
	int m = atoi(sm.c_str());
	for (int i = 0; i < m; i++)
	{
		string cmd;
		getline(cin, cmd);
		if (cmd[0] == '[')
		{
			string realcmd = cmd.substr(1, cmd.size() - 2);
			if (BOOK[realcmd] != "")
			{
				cout << BOOK[realcmd] << endl;
			}
			else {
				cout << "what?" << endl;
			}
		}
		else {
			if (RBOOK[cmd] != "")
			{
				cout << RBOOK[cmd] << endl;
			}
			else {
				cout << "what?" << endl;
			}
		}
	}

	return 0;
}