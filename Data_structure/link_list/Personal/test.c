#include <stdio.h>
#include <stdlib.h>

typedef struct link_node
{
	int data;
	struct link_node *next;
} link_list;

//创建
link_list *creat_link_list();
//增加
int insert_head_link_list(link_list *head, int data);
//删除
int del_head_link_list(link_list *head);
//打印
int print_link_list(link_list *head);
//修改
int change_index_link_list(link_list *head, int index, int data);
//查找
link_list *find_link_list(link_list *head, int data);
//清空
//销毁
//逆打印
//判空
int is_empty(link_list *head);

int main(int argc, char const *argv[])
{
	int i;
	link_list *head = creat_link_list();
	for (i = 0; i < 10; i++)
	{
		insert_head_link_list(head, i * 10);
	}

	print_link_list(head);
	return 0;
}

link_list *creat_link_list()
{
	link_list *head = (link_list *)malloc(sizeof(link_list));
	if (head == NULL)
	{
		return NULL;
	}
	head->next = NULL;
	return head;
}

int insert_head_link_list(link_list *head, int data)
{
	link_list *newnode = (link_list *)malloc(sizeof(link_list));
	if (newnode == NULL)
	{
		return -1;
	}
	newnode->data = data;
	newnode->next = head->next;
	head->next = newnode;
	return 0;
}

int del_head_link_list(link_list *head)
{
	if (is_empty(head))
	{
		return -1;
	}
	link_list *temp = head->next;
	if (temp == NULL)
	{
		return -1;
	}
	head->next = temp->next;
	free(temp);
}

int print_link_list(link_list *head)
{
	if (is_empty(head))
	{
		return -1;
	}
	while (head->next != NULL)
	{
		printf("%d ", head->next->data);
		head = head->next;
	}
	printf("\n");
}
int change_index_link_list(link_list *head, int index, int data)
{
	if (is_empty(head) || index < 0)
	{
		return -1;
	}
	while (index--)
	{
		head = head->next;
		if (head->next = NULL)
		{
			printf("过大，无法改变\n");
		}

	}
	head->next->data = data;
	return 0;
}
link_list *find_link_list(link_list *head, int data)
{
	while (head->next != NULL)
	{
		if (head->next->data == data)
		{
			return head;
		}
		head = head->next;

	}
	return NULL;
}
int is_empty(link_list *head)
{
	return head->next == NULL;
}