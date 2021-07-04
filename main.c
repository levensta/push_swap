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

t_blst	*lst_mediana(t_blst *list_sort)
{
	int	i;

	if (list_sort)
	{
		i = (bd_lstsize(list_sort) / 2) - 1;
		while (i--)
			list_sort = list_sort->next;
	}
	return (list_sort);
}

// void	minimal_rotation_b(t_blst **list_a, t_blst **list_b, t_blst *current)
// {
// 	int		i;
// 	t_arg	*element;

// 	element = (t_arg *)current->data;
// 	if (element->i > element->rr)
// 	{
// 		i = element->rr;
// 		while (i--)
// 			implement_instruction("rrb", list_a, list_b);
// 	}
// 	else if (element->i <= element->rr)
// 	{
// 		i = element->i;
// 		while (i--)
// 			implement_instruction("rb", list_a, list_b);
// 	}
// }


// void	minimal_rotation_a(t_blst **list_a, t_blst **list_b, t_blst *current)
// {
// 	int		i;
// 	t_arg	*element;

// 	element = (t_arg *)current->data;
// 	if (element->i > element->rr)
// 	{
// 		i = element->rr;
// 		while (i--)
// 			implement_instruction("rra", list_a, list_b);
// 	}
// 	else if (element->i <= element->rr)
// 	{
// 		i = element->i;
// 		while (i--)
// 			implement_instruction("ra", list_a, list_b);
// 	}
// }

void	sorting_three(t_blst **list_a, t_blst **list_b)
{
	while (!lst_is_sorted(*list_a))
	{
		if ((*list_a)->next && bd_lstcmp(*list_a, (*list_a)->next, cmp_elements) > 0)
			implement_instruction("sa", list_a, list_b);
		else if ((*list_a)->next && bd_lstcmp(*list_a, bd_lstlast(*list_a), cmp_elements) > 0)
			implement_instruction("rra", list_a, list_b);
	}
}

int	is_mmm(t_blst *lst, t_blst *max, t_blst *mid, t_blst *min)
{
	if	(!bd_lstcmp(lst, max, cmp_elements) \
		|| !bd_lstcmp(lst, mid, cmp_elements) \
		|| !bd_lstcmp(lst, min, cmp_elements))
		return (1);
	else
		return (0);
}

void	push_all_b(t_blst **list_a, t_blst **list_b, t_blst **list_sort)
{
	int		i;
	t_blst	*max;
	t_blst	*min;
	t_blst	*mid;

	max = bd_lstmax(*list_sort, cmp_elements);
	min = bd_lstmin(*list_sort, cmp_elements);
	mid = lst_mediana(*list_sort);
	i = (bd_lstsize(*list_sort) / 2) - 2;
	while (i)
	{
		if	(is_mmm(*list_a, max, mid, min) || bd_lstcmp(*list_a, mid, cmp_elements) > 0)
			implement_instruction("ra", list_a, list_b);
		else if (bd_lstcmp(*list_a, mid, cmp_elements) < 0)
		{
			implement_instruction("pb", list_a, list_b);
			i--;
		}
	}
	while (bd_lstsize(*list_a) > 3)
	{
		if	(is_mmm(*list_a, max, mid, min))
			implement_instruction("ra", list_a, list_b);
		else
			implement_instruction("pb", list_a, list_b);
	}
}

int	min_rotations(t_arg *element)
{
	if (element->i > element->rr)
		return (element->rr);
	else if (element->i <= element->rr)
		return (element->i);
}

int	main(int argc, char **argv)
{
	t_blst	*list_a;
	t_blst	*list_b;
	t_blst	*list_sort;

	initialize(&list_a, &list_sort, argc, &(argv[1]));
	if (argc == 4)
		sorting_three(&list_a, &list_b);
	push_all_b(&list_a, &list_b, &list_sort);
	sorting_three(&list_a, &list_b);

	t_blst	*b;
	b = list_b;
	while (b)
	{
		t_blst	*a;
		int n = INT32_MAX;

		a = list_a;
		while (a->next)
		{
			a = a->next;
			if (bd_lstcmp(b, a->prev, cmp_elements) > 0 && bd_lstcmp(b, a, cmp_elements) < 0)
			{
				if (n > min_rotations(a->data))
					n = min_rotations(a->data);
				break;
			}
		}
		if (bd_lstcmp(b, a, cmp_elements) < 0 && bd_lstcmp(b, list_a, cmp_elements) > 0) // элемент b меньше последнего a и больше первого а
		{
			if (n > min_rotations(a->data))
				n = min_rotations(a->data);
		}
		// else if (bd_lstcmp(list_b, a, cmp_elements) > 0 && bd_lstcmp(list_b, list_a, cmp_elements) < 0) // элемент b больше последнего и меньше первого
		// {
		// 	// implement_instruction("pa", list_a, list_b);
		// 	// break;
		// 	n = 0;
		// }
	printf("---------\nlist_a\n");
	bd_lstprint(list_a, print_element);
	printf("---------\nlist_b\n");
	bd_lstprint(list_b, print_element);
	exit(0);
}

// 3 4 2

// 3 7 4 8 5 2 9 6 10 1
// 7 4 8 5 2 9 6 10 1
// 4 8 5 2 9 6 10 1 7
// 8 5 2 9 6 10 1 7
// 5 2 9 6 10 1 7 8
// 2 9 6 10 1 7 8 5
// 9 6 10 1 7 8 5

// while (b != NULL)
// {
// 	a = tmp;
// 	while (a->next != NULL)
// 	{
// 		a = a->next;
// 		if (b->content > a->prev->content && b->content < a->content)
// 			count sumofrrrrr();
// 		break;
// 	}
// 	if (b->content < a->сontent && b->content > tmp->content)
// 			count sumofrrrrr();
// }