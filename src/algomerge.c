#include "../includes/push_swap.h"

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
   and return the two lists using the reference parameters.
   If the length is odd, the extra node should go in the front list.
   Uses the fast/slow pointer strategy. */
void	FrontBackSplit(t_node *source, t_node **frontRef, t_node **backRef)
{
	t_node	*fast;
	t_node	*slow;

	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	   at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

t_node	*SortedMerge(t_node *a, t_node *b)
{
	t_node *result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b==NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->nb <= b->nb)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}

/* sorts the linked list by changing next pointers (not data) */
void	MergeSort(t_node **headRef)
{
	t_node	*head = *headRef;
	t_node	*a;
	t_node	*b;

	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
}
