#include<iostream>

using namespace std;

struct node
{
	int data;
	node* lchild, * rchild;
	node(int x) :data(x), lchild(NULL), rchild(NULL) {};
};

node* ADD(node* now, int x)
{
	if (now == NULL)
	{
		now = (node*)malloc(sizeof(node));
		now->data = x;
		now->lchild = NULL;
		now->rchild = NULL;
	}
	else if (x < now->data)
	{
		now->lchild = ADD(now->lchild, x);
	}
	else if (x > now->data)
	{
		now->rchild = ADD(now->rchild, x);
	}
	return  now;

}

void preOrder(node* now)
{
	cout << now->data << " ";
	if(now->lchild!=NULL) preOrder(now->lchild);
	if (now->rchild != NULL)preOrder(now->rchild);
}

void inOrder(node* now)
{
	if (now->lchild != NULL)inOrder(now->lchild);
	cout << now->data << " ";
	if (now->rchild != NULL)inOrder(now->rchild);
}

void postOrder(node* now)
{
	if (now->lchild != NULL)postOrder(now->lchild);
	if (now->rchild != NULL)postOrder(now->rchild);
	cout << now->data << " ";
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
		root = ADD(root, temp);
	}
	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;

	return 0;
}