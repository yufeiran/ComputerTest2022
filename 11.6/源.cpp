#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
const int MAX_N = 200;
const int MAX_M = 1000;
int n, m;

struct load {
	int a, b, len;
	load() {};
	load(int  A, int B, int LEN) :a(A), b(B), len(LEN) {};
	bool operator<(load a)const {
		if (len < a.len)return true;
		else return false;
	}
};

vector<load>Edge[MAX_N];
const int DIS_MAX = 9999999;
int Distance[MAX_N];
bool inS[MAX_N];

void init()
{
	for (int i = 0; i < n; i++)
	{
		Edge[i].clear();
	}
	for (int i = 0; i < n; i++)
	{
		inS[i] = false;
		Distance[i] = DIS_MAX;
	}


}

bool isAllChoice()
{
	for (int i = 0; i < n; i++)
	{
		if (inS[i] == false)return false;
	}
	return true;
}

int findMin()
{
	int min = DIS_MAX;
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (inS[i] == false)
		{
			if (Distance[i] < min) {
				index = i;
				min = Distance[i];
			}
		}
	}
	return index;
}

int main()
{
	while (scanf("%d %d", &n, &m) != EOF) {
		init();
		for (int i = 0; i < m; i++)
		{
			int a, b, len;
			scanf("%d %d %d", &a, &b, &len);
			Edge[a].push_back(load(a, b, len));
			Edge[b].push_back(load(b, a, len));
		}
		int start, end;
		scanf("%d %d", &start, &end);

		inS[start] = true;
		for (int i = 0; i < Edge[start].size(); i++) {
			load nowLoad = Edge[start][i];
			Distance[nowLoad.b] = nowLoad.len;
		}
		
		while (isAllChoice()==false) {
			//在所有Distance中选近的且不属于S的边
			int choiceV = findMin();
			if (choiceV == -1)break;
			inS[choiceV] = true;
			
			//把它的所有边和原来的比较，更新Distance
			for (int i = 0; i < Edge[choiceV].size(); i++) {
				load nowLoad = Edge[choiceV][i];
				if (inS[nowLoad.b] == false) {
					//如果从新加的点出发到其他点的距离比原来的近，就更新
					if (Distance[choiceV] + nowLoad.len < Distance[nowLoad.b]) {
						Distance[nowLoad.b] = Distance[choiceV] + nowLoad.len;
					}
				}

			}
		}
		if (Distance[end] != DIS_MAX) {
			cout << Distance[end] << endl;
		}
		else {
			cout << "-1" << endl;
		}
		
	}
	return 0;
}