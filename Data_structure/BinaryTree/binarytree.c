#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
} tree_t;


tree_t *creat_binary_tree(int num);				//创建二叉树
void pre_binary_tree(tree_t *root);				//先序遍历
void mid_binary_tree(tree_t *root);				//中序遍历
void post_binary_tree(tree_t *root);			//后序遍历
int trans_level(tree_t *root);




int main(int argc, char const *argv[])
{
	tree_t *tree = creat_binary_tree(1);
	printf("先序遍历：");
	pre_binary_tree(tree);
	printf("\n");
	printf("中序遍历：");
	mid_binary_tree(tree);
	printf("\n");
	printf("后序遍历：");
	post_binary_tree(tree);
	printf("\n");
	printf("层次遍历：");
	trans_level(tree);
	printf("\n");
	return 0;
}



/**
 * [creat_binary_tree 创建树]
 * @Author:   liuqi
 * @DateTime: 2018-03-27
 * @param     num        [根节点1]
 * @return               [根节点地址]
 */
tree_t *creat_binary_tree(int num)
{
	if (num > 6)
	{
		return NULL;
	}
	tree_t *root = (tree_t *)malloc(sizeof(tree_t));

	root->data = num;

	root->lchild = creat_binary_tree(num * 2);

	root->rchild = creat_binary_tree(num * 2 + 1);

	return root;
}

/**
 * [pre_binary_tree 先序遍历【根-左-右】]
 * @Author:   liuqi
 * @DateTime: 2018-03-27
 * @param     root       [根节点地址]
 */
void pre_binary_tree(tree_t *root)
{
	if (root == NULL)
	{
		return ;
	}
	printf("%d ", root->data);
	pre_binary_tree(root->lchild);
	pre_binary_tree(root->rchild);


}
/**
 * [mid_binary_tree 中序遍历【左-根-右】]
 * @Author:   liuqi
 * @DateTime: 2018-03-27
 * @param     root       [根节点地址]
 */
void mid_binary_tree(tree_t *root)
{
	if (root == NULL)
	{
		return ;
	}

	mid_binary_tree(root->lchild);
	printf("%d ", root->data);
	mid_binary_tree(root->rchild);

}
/**
 * [post_binary_tree 后序遍历【左-右-根】]
 * @Author:   liuqi
 * @DateTime: 2018-03-27
 * @param     root       [description]
 */
void post_binary_tree(tree_t *root)
{
	if (root == NULL)
	{
		return ;
	}

	post_binary_tree(root->lchild);
	post_binary_tree(root->rchild);
	printf("%d ", root->data);

}
int trans_level(tree_t *root)
{
	tree_t *queue[10];
	int head = 0;
	int tail = 0;

	tree_t *temp;

	queue[tail++] = root;
	while (head != tail)
	{
		temp = queue[head++];
		printf("%d ", temp->data);
		if (temp->lchild != NULL)
		{
			queue[tail++] = temp->lchild;
		}
		if (temp->rchild != NULL)
		{
			queue[tail++] = temp->rchild;
		}
	}

	return 0;

}