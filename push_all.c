#include "push_swap.h"

static int	is_mmm(t_blst *lst, t_blst *max, t_blst *mid, t_blst *min)
{
	if (!bd_lstcmp(lst, max, cmp_elements) \
		|| !bd_lstcmp(lst, mid, cmp_elements) \
		|| !bd_lstcmp(lst, min, cmp_elements))
		return (1);
	else
		return (0);
}

static t_blst	*lst_mediana(t_blst *list_sort)
{
	int	i;

	if (list_sort)
	{
		i = (bd_lstsize(list_sort) / 2) - 1;
		if (bd_lstsize(list_sort) % 2)
			i++;
		while (i--)
			list_sort = list_sort->next;
	}
	return (list_sort);
}

void	push_all(t_blst **list_a, t_blst **list_b, t_blst **list_sort)
{
	int		i;
	t_blst	*max;
	t_blst	*min;
	t_blst	*mid;

	max = bd_lstmax(*list_sort, cmp_elements);
	min = bd_lstmin(*list_sort, cmp_elements);
	mid = lst_mediana(*list_sort);
	i = (bd_lstsize(*list_sort) - 3) / 2;
	while (i)
	{
		if (is_mmm(*list_a, max, mid, min) || bd_lstcmp(*list_a, mid, cmp_elements) > 0)
			implement_instruction("ra", list_a, list_b);
		else if (bd_lstcmp(*list_a, mid, cmp_elements) < 0)
		{
			implement_instruction("pb", list_a, list_b);
			i--;
		}
	}
	while (bd_lstsize(*list_a) > 3)
	{
		if (is_mmm(*list_a, max, mid, min))
			implement_instruction("ra", list_a, list_b);
		else
			implement_instruction("pb", list_a, list_b);
	}
}
