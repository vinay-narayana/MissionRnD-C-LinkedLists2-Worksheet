/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
typedef struct node *lptr;
lptr insert(lptr head, int x)
{
	lptr p, t;
	p = (lptr)malloc(sizeof(struct node));
	p->next = NULL;
	p->num = x;
	if (head == NULL)
		return p;
	t = head;
	while (t->next != NULL)
		t = t->next;
	t->next = p;
	return head;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	struct node * merged_list=NULL;
	struct node * t1 = head1;
	struct node * t2 = head2;
	while (t1 != NULL && t2 != NULL)
	{
		if (t1->num <= t2->num)
		{
			merged_list = insert(merged_list, t1->num);
			t1 = t1->next;
		}
		else
		{
			merged_list = insert(merged_list, t2->num);
			t2 = t2->next;
		}
	}
	while (t1 != NULL)
	{
		merged_list = insert(merged_list, t1->num);
		t1 = t1->next;
	}
	while (t2 != NULL)
	{
		merged_list = insert(merged_list, t2->num);
		t2 = t2->next;
	}
	return merged_list;
}
