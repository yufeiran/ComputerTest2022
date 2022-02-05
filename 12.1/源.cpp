#include<iostream>
using namespace std;
int n;
int Count = 0;
void DFS(int index,int aim)
{
	if (index == aim)
	{
		Count++;
		return;
	}
	if (index > aim)
	{
		return;
	}
	DFS(index + 1, aim);
	DFS(index + 2, aim);
}
int main()
{
	cin >> n;
	DFS(0, n);
	cout << Count << endl;
	return 0;
}