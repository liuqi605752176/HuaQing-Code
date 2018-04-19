#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int *data;
	int size;
	int head;
	int tail;
} cir_queue;

cir_queue *creat_cir_queue(int size);
int is_empty(cir_queue *queue);
int is_full(cir_queue *queue);
int en_queue(cir_queue *queue, int data);
int de_queue(cir_queue *queue, int *data);
int print_cir_queue(cir_queue *queue);
int get_len_cir_queue(cir_queue *queue);
int clean_queue(cir_queue *queue);
int dis_queue(cir_queue *queue);

int main(int argc, char const *argv[])
{
	int temp;
	cir_queue *queue = creat_cir_queue(6);
	en_queue(queue, 1);
	en_queue(queue, 2);
	en_queue(queue, 3);
	en_queue(queue, 4);
	print_cir_queue(queue);
	de_queue(queue, &temp);
	print_cir_queue(queue);

	en_queue(queue, 5);
	print_cir_queue(queue);
	en_queue(queue, 6);
	print_cir_queue(queue);
	en_queue(queue, 7);
	print_cir_queue(queue);

	clean_queue(queue);
	dis_queue(queue);
	return 0;
}
/**
 * [creat_cir_queue 创建循环队列]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     size       [队列长度]
 * @return               [队列地址]
 */
cir_queue *creat_cir_queue(int size)
{
	cir_queue *queue = (cir_queue *)malloc(sizeof(cir_queue));
	if (queue == NULL)
	{
		return NULL;
	}
	queue->data = (int *)malloc(sizeof(int));
	queue->size = size;
	queue->head = 0;
	queue->tail = 0;
	return queue;
}
/**
 * [is_empty 判空]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [队列地址]
 * @return               [0]
 */
int is_empty(cir_queue *queue)
{
	return queue->head == queue->tail;
}
/**
 * [is_full 判满]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [队列地址]
 * @return               [0]
 */
int is_full(cir_queue *queue)
{
	return (queue->tail + 1) % queue->size == queue->head;
}
/**
 * [en_queue 入队]
 * @Author:   liuqi
 * @DateTime: 2018-03-26
 * @param     queue      [队列地址]
 * @param     data       [入队数据]
 * @return               [0]
 */
int en_queue(cir_queue *queue, int data)
{
	if (is_full(queue))
	{
		return -1;
	}
	queue->data[queue->tail] = data;

	queue->tail = (queue->tail + 1) % queue->size;

	return 0;
}

int de_queue(cir_queue *queue, int *data)
{
	if (is_empty(queue))
	{
		return -1;
	}
	*data = queue->data[queue->head];
	queue->head = (queue->head + 1) % queue->size;

	return 0;
}

int print_cir_queue(cir_queue *queue)
{
	if (is_empty(queue))
	{
		return -1;
	}
	int i;
	for (i = queue->head ; i != queue->tail; i = (i + 1) % queue->size)
	{
		printf("%d ", queue->data[i]);
	}
	printf("\n");
	return 0;
}

int get_len_cir_queue(cir_queue *queue)
{
	return (queue->tail + queue->size - queue->head) % queue->size;
}

int clean_queue(cir_queue *queue)
{
	queue->head = 0;
	queue->tail = 0;
	return 0;
}

int dis_queue(cir_queue *queue)
{
	free(queue->data);
	free(queue);

	return 0;
}