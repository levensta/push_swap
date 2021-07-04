#include "push_swap.h"
#include <limits.h>
int	is_valid_num(char *str)
{
	int	i;
	int is_minus;

	i = 0;
	is_minus = 0;
	while (is_whitespaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_minus = 1;
		i++;
	}
	if (ft_strlen(&str[i]) >= 10 && ((!is_minus && ft_atoi(str) < INT32_MAX) || (is_minus && ft_atoi(str) >= 0)))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_dublicate(t_blst *lst, t_blst *new)
{
	while (lst)
	{
		if (!bd_lstcmp(lst, new, cmp_elements))
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	lst_indexing(t_blst *lst)
{
	int		i;
	t_blst	*tmp;
	t_arg	*element;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		element = (t_arg *)tmp->data;
		element->i = i;
		element->rr = bd_lstsize(lst) - i;
		tmp = tmp->next;
		i++;
	}
}

void	initialize(t_blst **list_a, t_blst **list_sort, int argc, char **argv)
{
	int		i;
	t_blst	*new;
	t_blst	*new_sort;
	t_arg	*element;
	t_arg	*element_sort;

	i = 0;
	if (argc < 2)
		error_print("Please enter more than one argument");
	while (argv[i])
	{
		element = alloc_element();
		element_sort = alloc_element();
		if (!is_valid_num(argv[i]))
			error_print("Invalid argument");
		element->value = ft_atoi(argv[i]);
		element_sort->value = element->value;
		new = bd_lstnew(element);
		new_sort = bd_lstnew(element_sort);
		if (!new || !new_sort)
			error_print("Bad alloc");
		if (is_dublicate(*list_a, new))
			error_print("List contains numbers without any duplicates");
		bd_lstadd_back(list_a, new);
		bd_lstpush_sort(list_sort, new_sort, cmp_elements);
		i++;
	}
	lst_indexing(*list_a);
	lst_indexing(*list_sort);
}