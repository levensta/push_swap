#include "push_swap.h"

void	error_print(char *error_message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit(-1);
}


t_arg 	*alloc_element(void)
{
	t_arg	*element;

	element = (t_arg *)malloc(sizeof(t_arg));
	if (element == NULL)
		error_print("Bad alloc");
	ft_memset(element, 0, sizeof(t_arg));
	return (element);
}

void	clear_element(void *elem)
{
	t_arg	*element;
	element = (t_arg*)elem;
	element->value = 0;
	element->index = 0;
}

void	*copy_element(void *elem)
{
	t_arg	*element;
	element = (t_arg*)elem;
	return (element);
}

void	print_element(void *data)
{
	t_arg *element;

	element = (t_arg *)data;
	if (element)
	{
		if (element->value)
			printf("%d\t|\t%d\n", element->value, element->index);
		else
			printf("<null>\n");
	}
}

int	compare_elements(void *a, void *b)
{
	t_arg	*element_a;
	t_arg	*element_b;

	element_a = (t_arg *)a;
	element_b = (t_arg *)b;
	return (element_a->value - element_b->value);
}

int	compare_lst(t_blst *a, t_blst *b)
{
	return (compare_elements(a->data, b->data));
}

t_arg	*get_data(void *data)
{
	t_arg	*element;

	element = (t_arg *)data;
	return (element);
}

t_blst	*bd_lstfind2(t_blst *lst, void *data, int (*comp)())
{
	while (lst)
	{
		if (comp(lst->data, data) == 0)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}