/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL)
		return NULL;
	struct node * temp_head = NULL;
	struct node * new_node;
	int i=0;
	for (temp_head = head; temp_head != NULL; temp_head = temp_head->next)
	{
		i++;
		if (i == K)
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->num = K;
			new_node->next = temp_head->next;
			
			temp_head->next = new_node;
			i = 0;
			temp_head = new_node;
		}
	}
	return head;
}
