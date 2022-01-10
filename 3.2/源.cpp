#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Stu {
	int id, score;
} STU;

vector<STU> V;

bool cmp(const STU s1, const STU s2)
{
	if (s1.score < s2.score)return true;
	else if (s1.score==s2.score && s1.id < s2.id)return true;
	else return false;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int id, score;
		scanf("%d %d", &id, &score);
		STU s;
		s.id = id;
		s.score = score;
		V.push_back(s);
	}
	sort(V.begin(), V.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", V[i].id, V[i].score);
	}

	return 0;
}