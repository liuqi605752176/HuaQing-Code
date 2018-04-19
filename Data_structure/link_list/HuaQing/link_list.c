#include <stdio.h>
#include <stdlib.h>


typedef struct link_node
{
	int data;
	struct link_node *next;

} link_node;

link_node *CreatLinklist();										//创建空链表
int insert_head_data(link_node *list, int data);				//增加数据
int insert_index_data(link_node *list, int index, int data);	//指定位置增加数据
int delete_head_data(link_node *list);							//删除数据
int delete_index_data(link_node *list, int index);				//指定位置删除数据
int print_link_list(link_node *list);							//打印数据
int change_index_data(link_node *list, int index, int data);	//修改数据
int find_index_data(link_node *list, int data); 				//查找数据,返回相对位置
link_node *locale_link_list(link_node *list, int data);			//查找数据，返回物理地址
int is_empty(link_node *list);
int clean_link_list(link_node *list);							//清空
int dis_link_list(link_node *list);								//销毁
int Reverse_print(link_node *list);								//逆打印1
int Reverse_print2(link_node *list);							//逆打印2
int is_empty(link_node *list);									//判空



int main(int argc, char const *argv[])
{
	link_node *link_list = CreatLinklist();
	int ret;

	insert_head_data(link_list, 20);			//20
	insert_head_data(link_list, 30);			//30 20
	insert_head_data(link_list, 40);			//40 30 20
	insert_index_data(link_list, 2, 70);		//40 30 70 20
	delete_index_data(link_list, 1);			//40 70 20
	change_index_data(link_list, 1, 15);		//40 15 20

	ret = find_index_data(link_list, 40);
	printf("这个数在这个链表中的%d个！\n", ret);	//0
	print_link_list(link_list);					//40 15 20
	Reverse_print(link_list);					//20 15 40
	Reverse_print2(link_list);					//20 15 40
	printf("\n");

	return 0;
}

/**
 * [CreatLinklist 创建一个空链表]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @return   [链表头结点的地址]
 */
link_node *CreatLinklist()
{
	link_node *head = (link_node *)malloc(sizeof(link_node));
	if (head == NULL)
	{
		printf("创建空表失败！\n");
		return NULL;
	}
	head->next = NULL;

	return head;
}
/**
 * [insert_data 插入数据]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点地址]
 * @param    data       [需要插入的数据]
 * @return              [0]
 */
int insert_head_data(link_node *list, int data)
{
	link_node *newnode = (link_node *)malloc(sizeof(link_node));
	if (newnode == NULL)
	{
		printf("新节点申请空间失败！\n");
		return -1;
	}
	newnode->data = data;
	newnode->next = list->next;
	list->next = newnode;

	return 0;
}
/**
 * [insert_index_data 指定位置增加数据]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点的地址]
 * @param    index      [指定位置]
 * @param    data       [插入的数据]
 * @return              [0]
 */
int insert_index_data(link_node *list, int index, int data)
{
	link_node *newnode = (link_node *)malloc(sizeof(link_node));
	if (index < 0)
	{
		printf("指定位置有误，增加数据失败！\n");
	}
	while (index--)
	{
		list = list->next;
		if (list == NULL)
		{
			printf("增加数据，指定位置过大！\n");
			return -1;
		}
	}

	newnode->data = data;
	newnode->next = list->next;
	list->next = newnode;

	return 0;
}
/**
 * [delete_head_data 头部删除数据]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表的头结点地址]
 * @return              [0]
 */
int delete_head_data(link_node *list)
{
	if (is_empty(list))
	{
		printf("空表无法打印！\n");
		return -1;
	}
	link_node *temp = list->next;
	if (temp == NULL)
	{
		printf("申请临时空间失败！\n");
		return -1;
	}
	list->next = temp->next;
	free(temp);
	return 0;
}

/**
 * [delete_index_data 删除指定位置数据]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点地址]
 * @param    index      [指定位置]
 * @return              [0]
 */
int delete_index_data(link_node *list, int index)
{
	if (is_empty(list) || index < 0)
	{
		printf("指定位置错误，无法删除指定位置数据！\n");
		return -1;
	}

	while (index--)
	{
		list = list->next;
		if (list->next == NULL)
		{
			printf("指定位置过大，无法删除数据！\n");
			return -1;
		}
	}
	delete_head_data(list);
	return 0;

}

/**
 * [print_link_list 打印操作]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点的地址]
 * @return              [0]
 */
int print_link_list(link_node *list)
{
	if (is_empty(list))
	{
		printf("链表为空，无法执行打印操作!\n");
		return -1;
	}
	list = list->next;
	while (list != NULL)
	{
		printf("%3d", list->data);
		list = list->next;
	}
	printf("\n");
	return 0;
}

/**
 * [change_index_data 改变指定位置数据]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点地址]
 * @param    index      [指定位置]
 * @param    data       [指定数据]
 * @return              [0]
 */
int change_index_data(link_node *list, int index, int data)
{
	int i = 0;
	if (index < 0 || is_empty(list))
	{
		printf("改变指定位置数据出错！\n");
		return -1;
	}
	while (index--)
	{
		list = list->next;
		if (list->next == NULL)
		{
			printf("指定位置过大，无法改变！\n");
		}
	}
	list->next->data = data;
	return 0;
}

/**
 * [find_index_data 寻找数据]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头节点地址]
 * @param    data       [指定的数据]
 * @return              [该节点位置]
 */
int find_index_data(link_node *list, int data)
{
	int count = 0;
	while (list->next->data != data)
	{
		count++;
		if (list->next == NULL)
		{
			printf("该链表中没有这个元素！\n");
		}
		list = list->next;
	}
	return count;
}

link_node *locale_link_list(link_node *list, int data)
{
	while (list->next != NULL)
	{
		if (list->next->data == data)
		{
			return list;
		}
		list = list->next;
	}
	printf("表中没有该数据！\n");
	return NULL;
}
/**
 * [is_empty 判空]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点的地址]
 * @return              [0]
 */
int is_empty(link_node *list)//判空
{
	return list->next == NULL;
}

/**
 * [clean_link_list 清空节点]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点地址]
 * @return              [0]
 */
int clean_link_list(link_node *list)
{
	while (!is_empty(list))
	{
		delete_head_data(list);
	}
	return 0;
}

/**
 * [dis_link_list 释放链表空间]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点地址]
 * @return              [0]
 */
int dis_link_list(link_node *list)
{
	clean_link_list(list);
	free(list);
	return 0;
}
/**
 * [Reverse_print 借助临时变量逆向打印]
 * @Author   liuqi
 * @DateTime 2018-03-22
 * @param    list       [链表头结点地址]
 * @return              [0]
 */
int Reverse_print(link_node *list)
{
	link_node *temp = CreatLinklist();

	if (is_empty(list))
	{
		printf("链表为空，无法执行打印操作!\n");
		return -1;
	}

	while (list->next != NULL)
	{
		insert_head_data(temp, list ->next->data);
		list = list->next;
	}
	print_link_list(temp);
	free(temp);
	return 0;
}

int Reverse_print2(link_node *list)
{
	if (list->next == NULL)
	{
		return 0;
	}
	Reverse_print2(list->next);
	printf("%3d", list->next->data);
	return 0;

}
