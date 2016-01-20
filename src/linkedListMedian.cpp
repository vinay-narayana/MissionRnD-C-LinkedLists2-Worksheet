/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	
	if (head == NULL)
		return -1;
	int list_len,i=0,median;
	struct node * temp = head;
	for (list_len = 0; temp != NULL; temp = temp->next, list_len++);

	if (list_len == 1)
		median = head->num;
	else
	{

		temp = head;
		while (i != (list_len / 2) - 1)
		{
			temp = temp->next;
			i++;
		}

		if (list_len % 2 == 1)
		{
			median = (temp->next)->num;
		}

		else
			median = (temp->num + (temp->next)->num) / 2;
	}
	return median;
}
