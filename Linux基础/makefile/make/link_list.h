#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

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

#endif //_LINK_LIST_H_