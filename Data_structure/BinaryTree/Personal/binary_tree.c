#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
} Binary_node;


void Create_Binary_tree(Binary_node *root);
void pre_binary_tree(Binary_node *root);

int main(int argc, char const *argv[])
{
	Binary_node *tree = (Binary_node *)malloc(sizeof(Binary_node));
	Create_Binary_tree(tree);
	pre_binary_tree(tree);
	return 0;
}

void Create_Binary_tree(Binary_node *root)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		return ;
	}
	else
	{
		root = (Binary_node *)malloc(sizeof(Binary_node));
		root->data = ch;
		Create_Binary_tree(root->lchild);
		Create_Binary_tree(root->rchild);
	}
}

void pre_binary_tree(Binary_node *root)
{
	if (root == NULL)
	{
		return ;
	}
	printf("%d ", root->data);
	pre_binary_tree(root->lchild);
	pre_binary_tree(root->rchild);

}