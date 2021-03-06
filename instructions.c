#include "push_swap.h"

void	implement_instruction(char *command, t_blst **list_a, t_blst **list_b)
{
	if (!ft_strcmp(command, "pa"))
		push(list_a, list_b);
	else if (!ft_strcmp(command, "pb"))
		push(list_b, list_a);
	else if (!ft_strcmp(command, "sa"))
		swap(list_a);
	else if (!ft_strcmp(command, "sb"))
		swap(list_b);
	else if (!ft_strcmp(command, "ra"))
		rotate(list_a);
	else if (!ft_strcmp(command, "rb"))
		rotate(list_b);
	else if (!ft_strcmp(command, "rra"))
		rrotate(list_a);
	else if (!ft_strcmp(command, "rrb"))
		rrotate(list_b);
	else if (!ft_strcmp(command, "rrr"))
	{
		rrotate(list_a);
		rrotate(list_b);
	}
	else if (!ft_strcmp(command, "rr"))
	{
		rotate(list_a);
		rotate(list_b);
	}
	else if (!ft_strcmp(command, "ss"))
	{
		swap(list_a);
		swap(list_b);
	}
	lst_indexing(*list_a);
	lst_indexing(*list_b);
	ft_putendl_fd(command, STDOUT_FILENO);
}

// куда и откуда пушить элемент
void	push(t_blst **dst, t_blst **src)
{
	t_blst *new;

	if (src && *src)
	{
		new = bd_lstdup(*src, sizeof(t_arg));
		bd_lstremove(src, *src, free);
		if (dst && *dst)
		{
			new->next = *dst;
			bd_lstadd_front(dst, new);
		}
		else
		{
			*dst = new;
			new->next = NULL;
		}
	}
}

void	swap(t_blst **lst)
{
	t_arg	*tmp;

	if (lst && *lst && (*lst)->next)
	{
		tmp = (*lst)->data;
		(*lst)->data = (*lst)->next->data;
		(*lst)->next->data = tmp;
	}
}

// rotate up (left)
void	rotate(t_blst **lst)
{
	t_blst	*first;

	if (lst && *lst && (*lst)->next)
	{
		first = bd_lstdup(*lst, sizeof(t_arg));
		first->next = NULL;
		bd_lstremove(lst, *lst, free);
		bd_lstadd_back(lst, first);
	}
}

// rotate down (right)
void	rrotate(t_blst **lst)
{
	t_blst	*last;

	if (lst && *lst && (*lst)->next)
	{
		last = bd_lstdup(bd_lstlast(*lst), sizeof(t_arg));
		last->next = *lst;
		bd_lstremove(lst, bd_lstlast(*lst), free);
		bd_lstadd_front(lst, last);
	}
}
