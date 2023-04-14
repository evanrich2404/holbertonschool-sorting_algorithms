#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *locate, *node1, *node2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	locate = *list;
	while (locate->next)
	{
		if (locate->n > locate->next->n)
		{
			node1 = locate;
			node2 = locate->next;
			node2->prev = node1->prev;
			if (node1->prev)
				node1->prev->next = node2;
			else
				*list = node2;
			if (node2->next)
				node2->next->prev = node1;
			node1->prev = node2;
			node1->next = node2->next;
			node2->next = node1;
			locate = locate->prev;
			print_list(*list);
			if (locate->prev && locate->prev->n > locate->n)
			{
				locate = locate->prev;
				continue;
			}
		}
		locate = locate->next;
	}
}
