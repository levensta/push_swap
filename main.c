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

void	circular_rotation_a(int min_a, t_blst **list_a, t_blst **list_b)
{
	if (min_a < 0)
	{
		while (min_a++)
			implement_instruction("rra", list_a, list_b);
	}
	else if (min_a > 0)
	{
		while (min_a--)
			implement_instruction("ra", list_a, list_b);
	}
}

void	circular_rotation_b(int min_b, t_blst **list_a, t_blst **list_b)
{
	if (min_b < 0)
	{
		while (min_b++)
			implement_instruction("rra", list_a, list_b);
	}
	else if (min_b > 0)
	{
		while (min_b--)
			implement_instruction("ra", list_a, list_b);
	}
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

int	min_rotations(t_arg *element)
{
	if (element->i > element->rr)
		return (element->rr * -1);
	else
		return (element->i);
}

int	abs(int	num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	main(int argc, char **argv)
{
	t_blst	*list_a;
	t_blst	*list_b;
	t_blst	*list_sort;

	initialize(&list_a, &list_sort, argc, &(argv[1]));
	if (argc == 4)
		sorting_three(&list_a, &list_b);
	push_all(&list_a, &list_b, &list_sort);
	sorting_three(&list_a, &list_b);
	while (list_b)
	{
		t_blst	*b;
		int	min_b;
		int min_a;
		b = list_b;
		int		count = INT32_MAX;
		while (b)
		{
			t_blst	*a;

			a = list_a;
			while (a->next)
			{
				a = a->next;
				if (bd_lstcmp(b, a->prev, cmp_elements) > 0 && bd_lstcmp(b, a, cmp_elements) < 0)
				{
					if (count > abs(min_rotations(a->data)) + abs(min_rotations(b->data)))
					{
						count = abs(min_rotations(a->data)) + abs(min_rotations(b->data));
						min_a = min_rotations(a->data);
						min_b = min_rotations(b->data);
					}
					break;
				}
			}
			if (bd_lstcmp(b, a, cmp_elements) < 0 && bd_lstcmp(b, list_a, cmp_elements) > 0) // элемент b меньше последнего a и больше первого а
			{
				if (count > abs(min_rotations(a->data)) + abs(min_rotations(b->data)))
				{
					count = abs(min_rotations(a->data)) + abs(min_rotations(b->data));
					min_a = min_rotations(a->data);
					min_b = min_rotations(b->data);
				}
			}
			b = b->next;
		}
		if (min_a < 0)
		{
			while (min_a++)
				implement_instruction("rra", &list_a, &list_b);
		}
		else if (min_a > 0)
		{
			while (min_a--)
				implement_instruction("ra", &list_a, &list_b);
		}
		//
		if (min_b < 0)
		{
			while (min_b++)
				implement_instruction("rrb", &list_a, &list_b);
		}
		else if (min_b > 0)
		{
			while (min_b--)
				implement_instruction("rb", &list_a, &list_b);
		}
		implement_instruction("pa", &list_a, &list_b);
	}
	printf("---------\nlist_a\n");
	bd_lstprint(list_a, print_element);
	printf("---------\nlist_b\n");
	bd_lstprint(list_b, print_element);
	// !bd_lstcmp(bd_lstlast(list_a), bd_lstmax(list_a, cmp_elements), cmp_elements)
	if (!lst_is_sorted(list_a))
	{
		t_blst	*min_el;
		t_arg	*test;
		test = (t_arg *)list_a->data;
		min_el = bd_lstmin(list_a, cmp_elements);
		int n = min_rotations(min_el->data);
		if (n < 0)
		{
			while (n++)
				implement_instruction("rra", &list_a, &list_b);
		}
		else if (n > 0)
		{
			while (n--)
				implement_instruction("ra", &list_a, &list_b);
		}
	}
	// if (bd_lstcmp(list_a, list_a->next, cmp_elements) > 0)
	// 	implement_instruction("sa", &list_a, &list_b);
	// printf("---------\nlist_a\n");
	// bd_lstprint(list_a, print_element);
	// printf("---------\nlist_b\n");
	// bd_lstprint(list_b, print_element);
	
		// else if (bd_lstcmp(list_b, a, cmp_elements) > 0 && bd_lstcmp(list_b, list_a, cmp_elements) < 0) // элемент b больше последнего и меньше первого
		// {
		// 	// implement_instruction("pa", list_a, list_b);
		// 	// break;
		// 	n = 0;
		// }
	exit(0);
}
