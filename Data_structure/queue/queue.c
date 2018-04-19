#include <stdio.h>
#include <stdlib.h>

//定义结点
typedef struct node
{
	int data;
	struct node *next;
} node_t, linkstack;

//定义头尾指针
typedef struct queue
{
	struct node *head;
	struct node *tail;
} queue_t;



queue_t *creatqueue();						//创建空的队列
int is_empty(queue_t *queue);				//判空
int enqueue(queue_t *queue, int data);		//入队
int dequeue(queue_t *queue, int *data);		//出队
int clean_queue(queue_t *queue);			//清空队列
int dis_queue(queue_t *queue);				//销毁队列
int print_queue(queue_t *queue);			//打印队列
int get_length_queue(queue_t *queue);		//获取队列的长度
int print_reverse_queue(queue_t *queue);	//逆向打印



int main(int argc, char const *argv[])
{
	queue_t *pQueue = creatqueue();
	if (pQueue == NULL)
	{
		return -1;
	}

	enqueue(pQueue, 10);
	enqueue(pQueue, 15);
	enqueue(pQueue, 5);
	print_queue(pQueue);		//10 15 5
	int ret;
	ret = get_length_queue(pQueue);
	printf("队列长度：%d\n", ret);

	int data;
	dequeue(pQueue, &data);
	printf("出队数据：%d\n", data);
	print_queue(pQueue);

	print_reverse_queue(pQueue);

	return 0;
}




/**
 * [creatqueue 创建队列]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @return    [queue_t指针]
 */
queue_t *creatqueue()
{
	node_t *headnode = (node_t *)malloc(sizeof(node_t));

	if (headnode == NULL)
	{
		return NULL;
	}

	headnode->next = NULL;

	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

	if (queue == NULL)
	{
		return NULL;
	}

	queue->head = headnode;
	queue->tail = headnode;
	return queue;
}
/**
 * [is_empty 判空]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [头尾指针地址]
 * @return               [0]
 */
int is_empty(queue_t *queue)
{
	return queue->head == queue->tail;
}

/**
 * [enqueue 入队]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [头尾指针结构体地址]
 * @param     data       [数据]
 * @return               [0]
 */
int enqueue(queue_t *queue, int data)
{
	node_t *newnode = (node_t *)malloc(sizeof(node_t));
	if (newnode == NULL)
	{
		return -1;
	}
	newnode->data = data;
	newnode->next = queue->tail->next;
	queue->tail->next = newnode;
	queue->tail = newnode;

	return 0;
}
/**
 * [dequeue 出队]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [头尾指针地址]
 * @param     data       [数据]
 * @return               [0]
 */
int dequeue(queue_t *queue, int *data)
{
	if (is_empty(queue))
	{
		return -1;
	}

	node_t *temp = queue->head->next;
	queue->head->next = temp->next;
	*data = temp->data;
	free(temp);

	if (is_empty(queue))
	{
		queue->tail = queue->head;
	}
	return 0;
}
/**
 * [clean_queue 清空队列]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [头尾指针地址]
 * @return               [0]
 */
int clean_queue(queue_t *queue)
{
	int temp;
	while (is_empty(queue) != 0)
	{
		dequeue(queue, &temp);
	}
	return 0;
}
/**
 * [dis_queue 销毁队列]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [头指针地址]
 * @return               []
 */
int dis_queue(queue_t *queue)
{
	clean_queue(queue);
	free(queue->head);
	free(queue);

}
/**
 * [print_queue 打印队列]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [头指针地址]
 * @return               [0]
 */
int print_queue(queue_t *queue)
{
	if (is_empty(queue))
	{
		return -1;
	}
	node_t *head = queue->head;
	head = head->next;
	printf("队头");
	while (head != NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
	printf("队尾\n");

}

/**
 * [get_length_queue 获取队列长度]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [头指针地址]
 * @return    count      [长度]
 */
int get_length_queue(queue_t *queue)
{
	if (is_empty(queue))
	{
		return -1;
	}
	int count = 0;
	node_t *p = queue->head;
	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

int print_reverse_queue(queue_t *queue)
{
	int temp;
	int *stack1 = (int *)malloc(sizeof(4 * get_length_queue(queue)));
	int *stack2 = (int *)malloc(sizeof(4 * get_length_queue(queue)));
	int top1 = -1;
	int top2 = -1;

	while (is_empty(queue) != 0)
	{
		dequeue(queue, &temp);
		stack1[++top1] = temp;
	}

	while (top1 != -1)
	{
		temp = stack1[top1--];
		stack2[++top2] = temp;
		printf("%d ", temp);

	}
	printf("\n");
	while (top2 != -1)
	{
		temp = stack2[top2--];
		enqueue(queue, temp);
	}

	free(stack1);
	free(stack2);
}

