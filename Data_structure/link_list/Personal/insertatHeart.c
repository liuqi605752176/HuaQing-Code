#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
} Node;

Node *CreatLinklist();
int insert_Head(Node *head, int d);

int PalindromeList(Node * list);
Node *reverseList(Node *list);
int print_list(Node *head);
int print_list1(Node *head);
Node *reverseList1(Node *head);



int main(int argc, char const *argv[])
{
	int i;
	Node *head = CreatLinklist();
	insert_Head(head, 10);
	insert_Head(head, 20);
	insert_Head(head, 30);
	/*	insert_Head(head, 30);
		insert_Head(head, 20);
		insert_Head(head, 10);*/

	print_list(head);

	//Node *pReverse = reverseList1(head);
	Node *pReverse = reverseList(head);
	print_list1(pReverse);
	return 0;
}

Node *CreatLinklist()
{
	Node *head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("创建空表失败！\n");
		return NULL;
	}
	head->next = NULL;

	return head;
}
int insert_Head(Node *head, int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));

	new_node->data = data;

	new_node->next = head->next;
	head->next = new_node;
}
#if 0
int PalindromeList(Node * list)
{
	Node *quick = (Node *)malloc(sizeof(Node));
	Node *slow = (Node *)malloc(sizeof(Node));
	quick = pHead->next;
	slow = pHead->next;
	while (quick->next != NULL && quick != NULL)
	{
		quick = quick->next->next;
		slow = slow->next;
	}

	Node *tail = reverseList(slow);
	Node *head = (Node *)malloc(sizeof(Node));
	head = pHead->next;

	while (tail && head)
	{
		if (tail->data == head->data)
		{
			tail = tail->next;
			head = head->next;
		}
		else
			return -1;
	}
	return 0;


}
#endif

#if 1
Node *reverseList(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node *p = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;

	return p;
}
#endif

#if 0
Node *reverseList1(Node *head)
{
	Node *new_node = CreatLinklist();

	while (head != NULL && head->next != NULL)
	{
		new_node->next = head;
		head->next = NULL;
		new_node = head;
		head = head->next;
	}

	head = new_node;
	return head;
}
#endif

int print_list1(Node *head)
{
	while (head != NULL)
	{
		if (head->next == NULL)
		{
			printf("\n");
			return -1;
		}
		printf("%3d", head->data);
		head = head->next;
	}
	printf("\n");
}
int print_list(Node *head)
{
	do
	{
		printf("%3d", head->next->data);
		head = head->next;
	} while (head->next != NULL);

	printf("\n");
}
