#include<iostream>

using namespace std;

struct node
{
	int data;
	node* lchild, * rchild;
};

void ADD(node*& now, int x,int father)
{

	if (now == NULL)
	{
		now = (node*)malloc(sizeof(node));
		now->data = x;
		now->lchild = NULL;
		now->rchild = NULL;
		cout << father << endl;
	}
	// ½øÈë×óÓÒ×ÓÊ÷
	else if (x < now->data)
	{
		ADD(now->lchild, x,now->data);
	}
	else if (x > now->data)
	{
		ADD(now->rchild, x,now->data);
	}



}

int main()
{
	int n;
	cin >> n;
	node* root=NULL;
	
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		ADD(root, temp,-1);
	}

	return 0;
}