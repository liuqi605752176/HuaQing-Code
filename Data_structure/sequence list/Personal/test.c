#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int *data;
	int size;
	int last;
} Seqlist;

//创建
Seqlist *creat_seqlist(int size);
//删除
int del_index_seqlist(Seqlist *list, int index);
//增加
int add_index_seqlist(Seqlist *list, int index, int data);
int add_head_seqlist(Seqlist *list, int data);
//修改
int change_index_seqlist(Seqlist *list, int index);
//判满
int is_full(Seqlist *list);
//判空
int is_empty(Seqlist *list);
//清空
int clean_seqlist(Seqlist *list);
//销毁
int dis_seqlist(Seqlist *list);
//打印
int print_seqlist(Seqlist *list);


int main(int argc, char const *argv[])
{
	Seqlist *Seqlist = creat_seqlist(20);
	int i;
	for (i = 0; i < 10; i++)
	{
		add_head_seqlist(Seqlist, i * 10);
	}
	add_index_seqlist(Seqlist, 2, 666);
	print_seqlist(Seqlist);
	del_index_seqlist(Seqlist, 2);
	print_seqlist(Seqlist);

	clean_seqlist(Seqlist);
	dis_seqlist(Seqlist);
	return 0;
}


Seqlist *creat_seqlist(int size)
{
	Seqlist *list = (Seqlist *)malloc(sizeof(Seqlist));
	if (list == NULL)
		return NULL;
	list->data = (int *)malloc(sizeof(int) * size);
	if (list->data == NULL)
		return NULL;
	list->size = size;
	list->last = -1;
	return list;
}

int del_index_seqlist(Seqlist *list, int index)
{
	int i;
	if (is_empty(list) || index < 0 || index > list->last)
		return -1;
	for (i = index; i < list->last; i++)
	{
		list->data[i] = list->data[i + 1];
	}
	list->last--;
}
int add_index_seqlist(Seqlist *list, int index, int data)
{
	if (is_full(list) || index < 0 || index > list->last - 1)
	{
		return -1;
	}
	int i;
	for (i = list->last; i >= index; i--)
	{
		list->data[i + 1] = list->data[i];
	}
	list->data[index] = data;
	list->last++;
}
int add_head_seqlist(Seqlist *list, int data)
{
	if (is_full(list))
	{
		return -1;
	}
	int i;
	for (i = list->last; i >= 0; i--)
	{
		list->data[i + 1] = list->data[i];
	}
	list->data[0] = data;
	list->last++;
	return 0;
}
int change_index_seqlist(Seqlist *list, int index, int data)
{
	if (is_empty(list) || index < 0 || index > list->last)
	{
		return -1;
	}
	list->data[index] = data;

	return 0;
}
int clean_seqlist(Seqlist *list)
{
	list->last = -1;
	return 0;
}

int dis_seqlist(Seqlist *list)
{
	clean_seqlist(list);
	free(list);
	return 0;
}
int is_empty(Seqlist *list)
{
	return list->last == -1;
}
int is_full(Seqlist *list)
{
	return list->last == list->size - 1;
}
int print_seqlist(Seqlist *list)
{
	int i;
	if (is_empty(list))
	{
		return -1;
	}
	for (i = 0; i < list->last + 1; i++)
	{
		printf("%d ", list->data[i]);
	}

	printf("\n");
}