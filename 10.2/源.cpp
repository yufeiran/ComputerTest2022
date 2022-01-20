#include<iostream>

using namespace std;

struct node {
	char data;
	node* lchild, * rchild;
};
string preData, inData;
/*
	先序遍历的作为主要，中序遍历作为参考
	从左往右读取先序遍历的数据，然后在中序遍历中找是在范围中的左边 还是 右边，在左边就把这个数作为左子树，右边就右子树，不在就跳出？回到上一级？

*/

int findIndex(int left, int right, char data)
{
	for (int i = left; i <= right; i++)
	{
		if (inData[i] == data) {
			return i;
		}
	}
	return -1;
}

node* makeTree(int &index,int left,int right)
{
	if (index >= preData.size())
	{
		return NULL;
	}
	if (left == right) {
		return NULL;
	}
	int center = findIndex( left, right, preData[index]);
	if (center == -1)
	{
		return NULL;
	}
	
	
	node* nowNode = (node*)malloc(sizeof(node));
	nowNode->data = preData[index];
	index++;

	
	nowNode->lchild = makeTree(index, left, center);
	nowNode->rchild = makeTree(index, center, right);
	return nowNode;
}


void postOrder(node* nowNode)
{
	if (nowNode->lchild != NULL)postOrder(nowNode->lchild);
	if (nowNode->rchild != NULL)postOrder(nowNode->rchild);
	cout << nowNode->data;
}


int main()
{

	while (cin >> preData >> inData)
	{
		int index = 0;
		node* root = makeTree(index, 0, inData.size() - 1);

		postOrder(root);
		cout << endl;
	}

	return 0;
}