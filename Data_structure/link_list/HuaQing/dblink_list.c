#include <stdio.h>
#include <stdlib.h>

typedef struct dblink_list
{
	int data;
	struct dblink_list *front;
	struct dblink_list *next;
} dblink_list;


dblink_list *Creat_dblink_list();										//创建空双链表
int is_empty(dblink_list *head);										//判空
int insert_head_dblink(dblink_list *head, int data);					//头插一个数据
int delete_head_dblink(dblink_list *head);								//删除头部数据
int print_dblink(dblink_list *head);									//正向打印
int print_dblink_reverse(dblink_list *head);							//反向打印
int change_dblink_data(dblink_list *head, int data);					//头部第一个数据修改
int change_dblink_index(dblink_list *head, int index, int data);		//任意位置数据修改
dblink_list *find_dblink_data(dblink_list *head, int data);				//查找数据
int clean_dblink(dblink_list *head);									//清空
int dis_dblink(dblink_list *head);										//销毁


int main(int argc, char const *argv[])
{
	dblink_list *list = Creat_dblink_list();
	insert_head_dblink(list, 10);
	insert_head_dblink(list, 20);
	insert_head_dblink(list, 30);
	insert_head_dblink(list, 40);
	insert_head_dblink(list, 50);
	print_dblink(list);
	print_dblink_reverse(list);
	change_dblink_data(list, 66);
	print_dblink(list);
	change_dblink_index(list, 2, 99);
	print_dblink(list);
	dblink_list *p = find_dblink_data(list, 20);
	printf("%p\n", p);

	dis_dblink(list);
	return 0;
}

/**
 * [Creat_dblink_list 创建空双链表]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @return   [双链表头结点地址]
 */
dblink_list *Creat_dblink_list()
{
	dblink_list *head = (dblink_list *)malloc(sizeof(dblink_list));
	dblink_list *tail = (dblink_list *)malloc(sizeof(dblink_list));
	if (head == NULL || tail == NULL)
	{
		printf("申请空间失败！\n");
		return NULL;
	}
	head->next = tail;
	head->front = NULL;
	tail->next = NULL;
	tail->front = head;

	return head;

}
/**
 * [is_empty 判空]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头结点地址]
 * @return              [0]
 */
int is_empty(dblink_list *head)
{
	return head->next->next == NULL;
}
/**
 * [insert_head_dblink 头插一个数据]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头结点地址]
 * @param    data       [数据]
 * @return              [0]
 */
int insert_head_dblink(dblink_list *head, int data)
{
	dblink_list *newnode = (dblink_list *)malloc(sizeof(dblink_list));
	newnode->data = data;

	newnode->next = head->next;
	newnode->front = head;
	head->next = newnode;
	newnode->next->front = newnode;

	return 0;
}
/**
 * [delete_head_dblink 从头删除一个数据]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头结点地址]
 * @return              [0]
 */
int delete_head_dblink(dblink_list *head)
{
	if (is_empty(head))
	{
		printf("表空，删除失败！\n");
		return -1;
	}
	dblink_list *temp = head->next;

	head->next = temp->next;
	temp->next->front = head;

	free(temp);
	return 0;
}
//正向打印
/**
 * [print_dblink 正向打印]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头结点地址]
 * @return              [0]
 */
int print_dblink(dblink_list *head)
{
	if (is_empty(head))
	{
		printf("表空，打印失败！\n");
		return -1;
	}
	while (head->next->next != NULL)
	{
		printf("%3d", head->next->data);
		head = head->next;
	}
	printf("\n");
	return 0;
}

//反向打印
/**
 * [print_dblink_reverse 反向打印]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头节点地址]
 * @return              [0]
 */
int print_dblink_reverse(dblink_list *head)
{
	if (is_empty(head))
	{
		printf("表空，打印失败！\n");
		return -1;
	}
	while (head->next->next != NULL)
	{
		head = head->next;

	}
	while (head->front != NULL)
	{
		printf("%3d", head->data);
		head = head->front;
	}
	printf("\n");
	return 0;
}
/**
 * [change_dblink_data 从头修改数据]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头结点]
 * @param    data       [数据]
 * @return              [0]
 */
int change_dblink_data(dblink_list *head, int data)
{
	if (is_empty(head) || head->next == NULL)
	{
		printf("修改数据失败！\n");
		return -1;
	}
	head->next->data = data;
	return 0;
}
/**
 * [change_dblink_index 指定位置修改数据]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头结点地址]
 * @param    index      [指定位置]
 * @param    data       [数据]
 * @return              [0]
 */
int change_dblink_index(dblink_list *head, int index, int data)
{
	if (is_empty(head) || index < 0)
	{
		printf("修改数据失败！\n");
		return -1;
	}
	while (index--)
	{
		head = head->next;
		if (head->next->next == NULL)
		{
			printf("输入的位置过大，修改失败！\n");
			return -1;
		}

	}
	head->data = data;
	return 0;
}
/**
 * [find_dblink_data 查找数据]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头节点地址]
 * @param    data       [数据]
 * @return              [NULL]
 */
dblink_list *find_dblink_data(dblink_list *head, int data)
{
	while (head->next->next != NULL)
	{
		if (head->next->data == data)
			return head;

		head = head->next;
	}

	return NULL;
}
/**
 * [clean_dblink 清空]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头节点地址]
 * @return              [0]
 */
int clean_dblink(dblink_list *head)
{
	while (!is_empty(head))
	{
		delete_head_dblink(head);
	}
	return 0;
}
/**
 * [dis_dblink 销毁链表]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    head       [头结点地址]
 * @return              [0]
 */
int dis_dblink(dblink_list *head)
{
	clean_dblink(head);
	free(head->next);
	free(head);

	return 0;
}