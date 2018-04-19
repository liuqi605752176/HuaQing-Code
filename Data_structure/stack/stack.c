#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
	int *data;
	int size;
	int top;

} stack_tt;


stack_tt *creat_stack(int size);				//创建栈
int is_full(stack_tt *stack);					//判满
int is_empty(stack_tt *stack);					//判空
int push_stack(stack_tt *stack, int data);		//压入数据
int pop_stack(stack_tt *stack);					//压出数据
int get_top_stack(stack_tt *stack, int *data);	//获取栈顶数据
int print_stack(stack_tt *stack);				//打印栈数据
int clean_stack(stack_tt *stack);				//清空栈
int dis_stack(stack_tt *stack);					//销毁栈


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
/**
 * [creat_stack description]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    size       [栈空间大小]
 * @return              [栈地址]
 */
stack_tt *creat_stack(int size)
{
	stack_tt *stack = (stack_tt *)malloc(sizeof(stack_tt));
	stack->data = (int *)malloc(sizeof(int) * size);
	stack->size = size;
	stack->top = -1;

	return stack;
}
/**
 * [is_full description]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    stack      [栈地址]
 * @return              [0]
 */
int is_full(stack_tt *stack)
{
	return stack->top == (stack->size - 1);
}
/**
 * [is_empty description]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    stack      [栈地址]
 * @return              [0]
 */
int is_empty(stack_tt *stack)
{
	return stack->top == 0;
}
/**
 * [push_stack description]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    stack      [栈地址]
 * @param    data       [数据]
 * @return              [0]
 */
int push_stack(stack_tt *stack, int data)
{
	if (is_full(stack))
	{
		printf("栈已满！\n");
		return -1;
	}
	stack->data[stack->top + 1] = data;
	stack->top++;
}
/**
 * [pop_stack description]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    stack      [栈地址]
 * @return              [0]
 */
int pop_stack(stack_tt *stack, int *data)
{
	if (is_empty(stack))
	{
		printf("栈空，无法pop!\n");
		return -1;
	}
	*data = stack->data[stack->top];

	stack->top--;

	return 0;
}
/**
 * [get_top_stack description]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    stack      [栈地址]
 * @param    data       [栈顶数据的地址]
 * @return              [0]
 */
int get_top_stack(stack_tt *stack, int *data)
{
	if (is_empty(stack))
	{
		printf("栈空，无法pop!\n");
		return -1;
	}
	*data = stack->data[stack->top];
	return 0;
}
/**
 * [print_stack 打印栈数据]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    stack      [栈地址]
 * @return              [0]
 */
int print_stack(stack_tt *stack)
{
	if (is_empty(stack))
	{
		printf("栈空，无法pop!\n");
		return -1;
	}
	printf("栈顶！\n");
	int i;
	for (i = stack->top; i >= 0; i--)
	{
		printf("%3d\n", stack->data[i]);
	}
	printf("栈底！\n");
	return 0;
}
/**
 * [clean_stack 清空栈]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    stack      [栈地址]
 * @return              [0]
 */
int clean_stack(stack_tt *stack)
{
	stack->top = -1;
	return 0;
}
/**
 * [dis_stack 销毁栈]
 * @Author   liuqi
 * @DateTime 2018-03-23
 * @param    stack      [栈地址]
 * @return              [0]
 */
int dis_stack(stack_tt *stack)
{
	free(stack->data);
	free(stack);

	return 0;
}