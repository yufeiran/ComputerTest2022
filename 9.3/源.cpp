#include<iostream>
#include<vector>

using namespace std;

const int MAX = 26;

bool board[MAX][MAX];

int p, q;

int direction[8][2] = { {-1,-2},{1,-2}, {-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2} };

struct POS
{
	int x, y;
	POS(int X, int Y) :x(X), y(Y) {}
};
vector<POS> load;
vector<POS> finalLoad;
bool findflag = false;

void init()
{
	memset(board, false, sizeof(board));
	findflag = false;
	load.clear();
	finalLoad.clear();
}

void DFS(int x, int y, int step)
{
	board[x][y] = true;
	POS pos(x, y);
	load.push_back(pos);
	if (step == p * q)
	{
		findflag = true;
		finalLoad = load;
	}

	for (int i = 0; i < 8; i++)
	{
		int nowPosX = x + direction[i][0];
		int nowPosY = y + direction[i][1];
		if (nowPosX>=0&&nowPosX<p&&nowPosY>=0&&nowPosY<q&& board[nowPosX][nowPosY] == false)
		{
			DFS(nowPosX, nowPosY, step + 1);
		}
	}
	load.pop_back();
	board[x][y] = false;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> q;
		init();
		DFS(0, 0, 1);
		cout << "Scenario #" << i + 1 << ":" << endl;
		if (findflag == false)
		{
			cout << "impossible" << endl;
		}
		else {
			for (int j = 0; j < finalLoad.size(); j++)
			{
				cout << (char)('A' + finalLoad[j].y) << finalLoad[j].x + 1;
			}
			cout << endl;
		}
	}

	return 0;
}