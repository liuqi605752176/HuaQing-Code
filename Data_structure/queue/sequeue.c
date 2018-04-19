#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

} node_t; //结点数据类型

typedef struct queue
{
	node_t * head;
	node_t * tail;

} queue_t; //队列数据类型


//创建

queue_t * creat_queue()
{
	//申请头结点的存储空间
	node_t * head = (node_t *)malloc(sizeof(node_t));
	if (head == NULL)
	{
		return NULL;
	}

	//初始化
	head->next = NULL;

	//申请头，尾指针的存储空间
	queue_t * queue = (queue_t *)malloc(sizeof(queue_t));

	if (queue == NULL)
	{
		return NULL;
	}

	//初始化头尾指针
	queue->head = head;
	queue->tail = head;

	return queue;//返回标识符


}

//判空
int isnull(queue_t * queue)
{
	return queue->head->next == NULL;
}

//入队数据
int in_queue(queue_t * queue, int data)
{
	node_t * newnode = (node_t *)malloc(sizeof(node_t));

	newnode->data = data;

	newnode->next = queue->tail->next;
	queue->tail->next = newnode;

	queue->tail = newnode;

	return 0;
}


//出队数据
int out_queue(queue_t *queue, int *data)
{
	if (isnull(queue))
	{
		printf("表为空，无法出队\n");
		return -1;
	}

	node_t * temp = queue->head->next;

	queue->head->next = temp -> next;

	*data = temp->data;

	free(temp);

	if (queue->head->next == NULL)
	{
		queue->tail = queue->head;
	}
	return 0;

}

int print_queue(queue_t * queue)
{
	if (isnull(queue))
	{
		return -1;
	}
	node_t * head = queue->head;
	head = head->next;
	printf("队头");
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}

	printf("队尾\n");
	return 0;

}


int get_length(queue_t * queue)
{
	if (isnull(queue))
	{
		return 0;
	}


	int len = 0;
	node_t * head = queue->head;
	head = head->next;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;

}
//清空
int clean_queue(queue_t * queue)
{
	int temp;
	while (queue->head != NULL)
	{
		out_queue(queue, &temp);
	}

	return 0;
}



//销毁

int dis_queue(queue_t * queue)
{
	clean_queue(queue);
	free(queue->head);
	free(queue);

	return 0;
}
//逆向打印
int reprint_queue(queue_t * queue)
{
	int * stack1 = (int *)malloc(sizeof(int) * get_length(queue));
	int top1 = -1;

	int * stack2 = (int *)malloc(sizeof(int) * get_length(queue));
	int top2 = -1;



}




int main(int argc, const char *argv[])
{
//创建
	queue_t * queue = creat_queue();
	{
		if (queue == NULL)
		{
			printf("申请空间失败\n");
			return -1;
		}
	}

//入队数据
	int i;
	for (i = 1; i <= 10; i++)
	{
		in_queue(queue, 10 * i);
	}
	print_queue(queue);


	int out_data;
	for (i = 1; i <= 3; i++)
	{
		out_queue(queue, &out_data);
		printf("out_data:%d\n", out_data);
		print_queue(queue);
	}

	int ret = get_length(queue);
	printf("%d\n", ret);


	clean_queue(queue);
	print_queue(queue);

	dis_queue(queue);
	print_queue(queue);

	return 0;
}
