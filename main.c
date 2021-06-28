#include "push_swap.h"

void	bd_lstriter(t_blst *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->data);
			lst = lst->prev;
		}
	}
}

void	bd_lstrprint(t_blst *lst, void (*print)(void *))
{
	bd_lstriter(bd_lstlast(lst), print);
}

int	main(int argc, char **argv)
{
	t_blst	*list_a;
	t_blst	*list_b;
	t_blst	*list_sort;

	initialize(&list_a, &list_sort, argc, &(argv[1]));
	printf("-----------------\nlist_a\t size: %d\n", bd_lstsize(list_a));
	bd_lstprint(list_a, print_element);
	printf("-----------------\nlist_sort size: %d\n", bd_lstsize(list_sort));
	bd_lstprint(list_sort, print_element);
	int i;

	t_blst	*finded;
	t_arg	*element;
	while (list_a)
	{
		finded = bd_lstfind2(list_a, list_sort->data, &compare_elements);
		if (!finded)
			error_print("lol");
		element = get_data(finded->data);
		// swap
		if (element->index >= (bd_lstsize(list_a) / 2))
		{
			i = bd_lstsize(list_a) - element->index;
			while (i--)
				implement_instruction("rra", &list_a, &list_b);
		}
		else
		{
			i = element->index;
			while (i--)
				implement_instruction("ra", &list_a, &list_b);
		}
		implement_instruction("pb", &list_a, &list_b);
		list_sort = list_sort->next;
	}
	printf("=========================================================");
	printf("-----------------\nlist_a\t size: %d\n", bd_lstsize(list_a));
	bd_lstprint(list_a, print_element);
	printf("-----------------\nlist_b\t size: %d\n", bd_lstsize(list_b));
	bd_lstprint(list_b, print_element);
	exit(0);
}