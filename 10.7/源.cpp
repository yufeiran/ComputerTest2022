#include<map>
#include<iostream>

using namespace std;

struct STU
{
	string id;
	string name;
	string sex;
	int age;
	STU(string ID, string NAME, string SEX, int AGE) :id(ID),name(NAME), sex(SEX), age(AGE) {};
	STU() {};
};

map<string, STU> stuList;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		STU s;
		cin >> s.id >> s.name >> s.sex >> s.age;
		stuList.insert(pair<string, STU>(s.id, s));
		
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string id;
		cin >> id;
		auto it = stuList.find(id);
		if (it == stuList.end()) {
			cout << "No Answer!" << endl;
		}
		else {
			cout << (*it).second.id << " " << (*it).second.name << " " << (*it).second.sex << " " << (*it).second.age << endl;
		}

	}

	return 0;
}