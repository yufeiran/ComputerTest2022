#include<iostream>

using namespace std;

struct node {
	char data;
	node* lchild, * rchild;
};
string preData, inData;
/*
	�����������Ϊ��Ҫ�����������Ϊ�ο�
	�������Ҷ�ȡ������������ݣ�Ȼ������������������ڷ�Χ�е���� ���� �ұߣ�����߾Ͱ��������Ϊ���������ұ߾������������ھ��������ص���һ����

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