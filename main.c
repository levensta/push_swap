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

void	sorting_three(t_blst **list_a, t_blst **list_b)
{
	while (!lst_is_sorted(*list_a))
	{
		if ((*list_a)->next && bd_lstcmp(*list_a, (*list_a)->next, cmp_elements) > 0)
			implement_instruction("sa", list_a, list_b);
		else
			implement_instruction("rra", list_a, list_b);
	}
}

int	main(int argc, char **argv)
{
	t_blst	*list_a;
	t_blst	*list_b;
	t_blst	*list_sort;

	initialize(&list_a, &list_sort, argc, &(argv[1]));
	if (argc > 4)
		push_all(&list_a, &list_b, &list_sort);
	sorting_three(&list_a, &list_b);
	while (list_b)
	{
		t_blst	*a;
		t_blst	*b;
		int		min_a;
		int		min_b;
		int		count;

		b = list_b;
		min_a = 0;
		min_b = 0;
		count = INT32_MAX;
		while (b)
		{
			a = list_a;
			while (a->next)
			{
				a = a->next;
				if (bd_lstcmp(b, a->prev, cmp_elements) > 0 && bd_lstcmp(b, a, cmp_elements) < 0)
				{
					if (count > count_rotations(a, b))
					{
						count = count_rotations(a, b);
						min_a = min_rotations(a->data);
						min_b = min_rotations(b->data);
					}
					break ;
				}
			}
			if (bd_lstcmp(b, a, cmp_elements) < 0 && bd_lstcmp(b, list_a, cmp_elements) > 0)
			{
				if (count > count_rotations(a, b))
				{
					count = count_rotations(a, b);
					min_a = min_rotations(a->data);
					min_b = min_rotations(b->data);
				}
			}
			b = b->next;
		}
		double_rotation(&min_a, &min_b, &list_a, &list_b);
		circular_rotation_a(min_a, &list_a, &list_b);
		circular_rotation_b(min_b, &list_a, &list_b);
		implement_instruction("pa", &list_a, &list_b);
	}
	circular_rotation_a(min_rotations(bd_lstmin(list_a, cmp_elements)->data), &list_a, &list_b);
	exit(0);
}
