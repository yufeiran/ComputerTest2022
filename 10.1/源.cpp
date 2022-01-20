#include<iostream>

using namespace std;

string input;

struct node {
	char data;
	node* lchild, *rchild;
};

node *preOrder(int &index)
{
	if (index >= input.size()) {
		index++;
		return NULL;
	}
	if (input[index] == '#') {
		index++;
		return NULL;
	}
	node* nowNode = (node*)malloc(sizeof(node));
	nowNode->data = input[index];
	index++;
	nowNode->lchild = preOrder(index);
	nowNode->rchild = preOrder(index);
	return nowNode;

}

void inOrder(node* now)
{
	if (now->lchild != NULL)inOrder(now->lchild);
	cout << now->data << " ";
	if (now->rchild != NULL)inOrder(now->rchild);
}

int main() {
	cin >> input;
	int index = 0;
	node* root = preOrder(index);
	inOrder(root);

	return 0;
}