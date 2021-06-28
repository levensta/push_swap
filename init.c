#include "push_swap.h"

int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	while (is_whitespaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error_print("Invalid argument");
		i++;
	}
	return (1);
}

void	lst_indexing(t_blst **lst)
{
	int		i;
	t_blst	*tmp;
	t_arg	*element;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		element = (t_arg *)tmp->data;
		element->index = i;
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
	if (argc < 3)
		error_print("Please enter more than one argument");
	while (argv[i])
	{
		element = alloc_element();
		element_sort = alloc_element();
		if (is_valid_num(argv[i]))
		{
			element->value = ft_atoi(argv[i]);
			element_sort->value = element->value;
		}
		new = bd_lstnew(element);
		new_sort = bd_lstnew(element_sort);
		if (!new || !new_sort)
			error_print("Bad alloc");
		bd_lstadd_back(list_a, new);
		bd_lstpush_sort(list_sort, new_sort, &compare_lst);
		i++;
	}
	lst_indexing(list_a);
	lst_indexing(list_sort);
}