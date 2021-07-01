#include "push_swap.h"

int	lst_is_sorted(t_blst *lst)
{
	while (lst && lst->next)
	{
		if (bd_lstcmp(lst, lst->next, cmp_elements) > 0)
			return (0);	
		lst = lst->next;
	}

	return (1);
}

void	minimal_rotation(t_blst **list_a, t_blst **list_b, t_blst **list_sort)
{
	int		i;
	t_blst	*finded;
	t_arg	*element;

	finded = bd_lstfind2(*list_a, (*list_sort)->data, cmp_elements);
	element = (t_arg *)finded->data;
	if (element->index > (bd_lstsize(*list_a) / 2))
	{
		i = bd_lstsize(*list_a) - element->index;
		while (i--)
			implement_instruction("rra", list_a, list_b);
	}
	else if (element->index <= (bd_lstsize(*list_a) / 2))
	{
		i = element->index;
		while (i--)
			implement_instruction("ra", list_a, list_b);
	}
}

int	main(int argc, char **argv)
{
	t_blst	*list_a;
	t_blst	*list_b;
	t_blst	*list_sort;

	initialize(&list_a, &list_sort, argc, &(argv[1]));

	while (!lst_is_sorted(list_a))
	{
		while (list_a)
		{
			if (argc <= 6)
			{
				while (argc == 6 && bd_lstsize(list_b) != 2)
				{
					if (bd_lstcmp(list_a, bd_lstmin(list_a, cmp_elements), cmp_elements))
						minimal_rotation(&list_a, &list_b, &list_sort);
					implement_instruction("pb", &list_a, &list_b);
					list_sort = list_sort->next;
				}
				if (list_a->next && bd_lstcmp(list_a, list_a->next, cmp_elements) > 0)
				{
					implement_instruction("sa", &list_a, &list_b);
					break ;
				}
				else if (list_a->next && bd_lstcmp(list_a, bd_lstlast(list_a), cmp_elements) > 0)
				{
					implement_instruction("rra", &list_a, &list_b);
					break ;
				}				
			}
			else
			{
				minimal_rotation(&list_a, &list_b, &list_sort);
				if (!list_b && lst_is_sorted(list_a))
					break;
				implement_instruction("pb", &list_a, &list_b);
				list_sort = list_sort->next;
			}
		}
		while (list_b)
			implement_instruction("pa", &list_a, &list_b);		
	}
	exit(0);
}