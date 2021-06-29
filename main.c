#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_blst	*list_a;
	t_blst	*list_b;
	t_blst	*list_sort;

	initialize(&list_a, &list_sort, argc, &(argv[1]));
	int i;

	t_blst	*finded;
	t_arg	*element;
	while (list_a)
	{
		finded = bd_lstfind2(list_a, list_sort->data, &compare_elements);
		element = (t_arg *)finded->data;
		if (element->index == 1)
			implement_instruction("sa", &list_a, &list_b);
		else if (element->index > (bd_lstsize(list_a) / 2))
		{
			i = bd_lstsize(list_a) - element->index;
			while (i--)
				implement_instruction("rra", &list_a, &list_b);
		}
		else if (element->index <= (bd_lstsize(list_a) / 2))
		{
			i = element->index;
			while (i--)
				implement_instruction("ra", &list_a, &list_b);
		}
		implement_instruction("pb", &list_a, &list_b);
		list_sort = list_sort->next;
	}
	while (list_b)
		implement_instruction("pa", &list_a, &list_b);
	// printf("-----------------\nlist_a\t size: %d\n", bd_lstsize(list_a));
	// bd_lstprint(list_a, print_element);
	// printf("-----------------\nlist_b\t size: %d\n", bd_lstsize(list_b));
	// bd_lstprint(list_b, print_element);
	// printf("-----------------\n");
	exit(0);
}