#include <stdio.h>
#include <stdlib.h>

//#define SIZE 20


typedef struct list
{
	//int data[SIZE];		//存储的数据
	int *data;
	int size;
	int last;			//标志位

} list_t;				//list_t == struct list


list_t *creat_list1();								//创建一个空表
list_t *creat_list(int size);						//创建一个动态的空表
int is_full(list_t *list);							//判满
int is_empty(list_t *list);							//判空
int insertHead(list_t *list, int data);				//从头部增加一个数据
int insert_index(list_t *list, int index, int data);//从指定位置增加一个数据
int print_list(list_t *list);						//打印数据
int delete_data(list_t *list, int data);			//删除线性表中的任意一个与之匹配的数据
int delete_index_list(list_t *list, int index); 	//删除指定位置的数据
int delete_head_list(list_t *list);					//从头部开始删除一个数据
int change_data(list_t *list, int index, int data);	//修改指定位置的数据
int find_data(list_t *list, int data);				//寻找数据
int empty_list(list_t *list);						//清空
int destroy_list(list_t *list);						//销毁



int main(int argc, char const *argv[])
{
	list_t *list = creat_list(10); //建立空表
	if (list == NULL)
	{
		printf("creat_list函数执行失败！\n");
		return -1;

	}
	int i = 0, zet;
	for (i = 0; i < 10; i++)
	{
		insertHead(list, i);		//传值

	}
	delete_data(list, 8); 			//9  7 6  5 4 3 2 1 0
	delete_head_list(list);			//7  6 5  4 3 2 1 0
	change_data(list, 1, 15);		//7 15 5  4 3 2 1 0
	insert_index(list, 3, 20);		//7 15 5 20 4 3 2 1 0
	delete_index_list(list, 4);		//7 15 5 20 3 2 1 0
	print_list(list);

	zet = find_data(list, 15);		//返回数据15的位置
	printf("位置：%d\n", zet);		//为１

	empty_list(list);				//清空线性表
	print_list(list);				//打印线性表，此时为空表！

	destroy_list(list);				//销毁线性表

	return 0;
}


//创建线性表
/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function list_t *creat_list()
 * @return   list   线性表的首地址
 */
list_t *creat_list1()
{
	list_t *list = (list_t *)malloc(sizeof(list_t));//申请空间
	if (list == NULL)
	{
		printf("空间申请失败！\n");
		return NULL;
	}
	list->last = -1;	//初始化，-1代表表中没有有效数据
	return list;		//返回申请空间的首地址
}
/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　list_t *creat_list()	申请可存size个数据的线性表
 * @param    size      　数据个数
 * @return              [description]
 */
list_t *creat_list(int size)	//创建一个动态的空表
{
	list_t *list = (list_t *)malloc(sizeof(list_t));
	if (list == NULL)
	{
		printf("空间申请失败！\n");
		return NULL;
	}
	list->data = (int *)malloc(sizeof(int) * size);
	if (list->data == NULL)
	{
		printf("空间申请失败！\n");
		return NULL;
	}
	list->size = size;
	list->last = -1;
	return list;
}
/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　is_full()  判满
 * @param    list       线性表的首地址
 * @return              ０
 */
int is_full(list_t *list)
{
	return list->last == (list->size - 1);
}

/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function is_empty()  判空
 * @param    list       线性表首地址
 * @return              ０
 */
int is_empty(list_t *list)
{
	return list->last == -1;
}


/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　insertHead()  从头部增加一个数据
 * @param    list       线性表的首地址
 * @param    data       所要增加的数据
 * @return              0
 */
int insertHead(list_t *list, int data)
{
	int i;
	if (is_full(list))
	{
		printf("表满，无法执行插入操作\n");
		return -1;
	}
	for (i = list->last; i >= 0; i--)	//从最后一位开始后移一位
	{
		list->data[i + 1] = list->data[i];//将这个位置的数据赋值给后一位

	}
	list->data[0] = data;//在头部插入一个数据
	list->last++;//标志位后移一位
	return 0;
}


/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　insert_index()  从指定位置增加数据
 * @param    list       线性表的首地址
 * @param    index      指定位置
 * @param    data       所要增加的数据
 * @return              ０
 */
int insert_index(list_t *list, int index, int data)
{
	if (is_full(list) || index < 0 || index > list->last - 1)
	{
		printf("增加数据时指定位置出错\n");
		return -1;
	}
	int i;
	for (i = list->last; i >= index; i--)
	{
		list->data[i + 1] = list->data[i];
	}
	list->data[index] = data;
	list->last++;

	return 0;
}



/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　print_list()　　打印数据
 * @param    list       线性表的首地址
 * @return              ０
 */
int print_list(list_t *list)
{
	if (is_empty(list))
	{
		printf("空表，无法打印！\n");
		return -1;
	}
	int i;
	for (i = 0; i <= list->last; i++)//打印
	{
		printf("%2d\n", list->data[i]);
	}
	printf("\n");
	return 0;
}


/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　delete_data()   删除与之匹配的数据
 * @param    list       线性表的首地址
 * @param    data       指定数据
 * @return              ０
 */
int delete_data(list_t *list, int data)
{
	if (is_empty(list))				//判断是否为空表
	{
		printf("表空，无法删除数据\n");//空则退出
		return -1;
	}
	int i, j;
	for (i = list->last; i >= 0; i--)//遍历寻找需要删除的数据
	{
		if (list->data[i] == data)		//匹配需要删除的数据
		{
			for (j = i; j <= list->last; j++)//从需要删除的数据开始到list->last位置遍历
				list->data[j] = list->data[j + 1];//后面一个数向前移动一位进行覆盖
		}
	}
	list->last--;//标志位前移一位
	return 0;
}

/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　delete_index_list()   删除指定位置的数据
 * @param    list       线性表首地址
 * @param    index      所指定的位置
 * @return              ０
 */
int delete_index_list(list_t *list, int index)
{
	int i;
	if (is_empty(list) || index < 0 || index > list->last)
	{
		printf("删除指定位置的数据时，指定的位置错误！\n");
		return -1;
	}
	for (i = index; i < list->last; i++)
	{
		list->data[i] = list->data[i + 1];
	}
	list->last--;
	return 0;
}

/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　delete_head_list(list_t *list)	从头部删除一个数据
 * @param    list       线性表首地址
 * @return              ０
 */
int delete_head_list(list_t *list)
{
	int i;
	if (is_empty(list))
	{
		printf("表空，无法删除数据\n");
		return -1;
	}
	for (i = 1; i <= list->last; i++)
	{
		list->data[i - 1] = list->data[i];
	}

	list->last--;
	return 0;
}

//修改数据
/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function
 * @param    list       线性表首地址
 * @param    index      指定位置
 * @param    data       修改的目标数据
 * @return              ０
 */
int change_data(list_t *list, int index, int data)
{
	if (is_empty(list) || index < 0 || index > list->last)
	{
		printf("表空，无法执行修改数据\n");
		return -1;
	}
	list->data[index] = data;
	return 0;
}
/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function find_data()
 * @param    list       线性表首地址
 * @param    data       寻找的数据
 * @return              指定数据的位置
 */
int find_data(list_t *list, int data)
{
	if (is_empty(list))
	{
		printf("表空，无法执行return_index\n");
	}
	int i;
	for (i = 0; i < list->last; i++)
	{
		if (list->data[i] == data)
		{
			return i;
		}
	}
	printf("寻找不到该数据！\n");
	return -1;
}


/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　empty_list()　　清空线性表
 * @param    list       线性表的首地址
 * @return              ０
 */
int empty_list(list_t *list)
{
	list->last = -1;
	printf("清空线性表成功！\n");
	return 0;
}

/**
 * @Author   liuqi
 * @DateTime 2018-03-21
 * @function　destroy_list()  销毁线性表
 * @param    list       线性表的首地址
 * @return              ０
 */
int destroy_list(list_t *list)
{
	free(list->data);
	free(list);
	return 0;
}




