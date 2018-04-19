#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
} linkstack;

linkstack *creatlinkstack();
int push_linkstack(linkstack *stack, int data);
linkstack *pop_linkstack(linkstack *stack);




int main(int argc, char const *argv[])
{


	return 0;
}

linkstack *creatlinkstack()
{
	linkstack *head = (linkstack *)malloc(sizeof(linkstack));
	if (head == NULL)
	{
		return NULL;
	}
	head->next = NULL;
	return head;
}

int push_linkstack(linkstack *stack, int data)
{
	linkstack *newnode = (linkstack *)malloc(sizeof(linkstack));
	newnode->data = data;
	newnode->next = stack->next;
	stack->next = newnode;

	return 0;
}

linkstack *pop_linkstack(linkstack *stack, int *data)
{
	linkstack *temp = (linkstack *)malloc(sizeof(linkstack));
	temp = stack->next;
	stack->next = temp->next;
	*data = temp->data;
	free(temp);
}