#include "push_swap.h"

int	abs(int	num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	min_rotations(t_arg *element)
{
	if (element->i > element->rr)
		return (element->rr * -1);
	else
		return (element->i);
}

int	count_rotations(t_blst *a, t_blst *b)
{
	int	min_a;
	int	min_b;
	int	rr;

	rr = 0;
	min_a = min_rotations(a->data);
	min_b = min_rotations(b->data);
	if (min_a < 0 && min_b < 0)
	{
		while (min_a && min_b)
		{
			min_a++;
			min_b++;
			rr++;
		}
	}
	else if (min_a > 0 && min_b > 0)
	{
		while (min_a && min_b)
		{
			min_a--;
			min_b--;
			rr++;
		}
	}
	return (abs(min_a) + abs(min_b) + rr);
}

void	double_rotation(int *min_a, int *min_b, t_blst **list_a, t_blst **list_b)
{
	if (*min_a < 0 && *min_b < 0)
	{
		while (*min_a && *min_b)
		{
			(*min_a)++;
			(*min_b)++;
			implement_instruction("rrr", list_a, list_b);
		}
	}
	else if (*min_a > 0 && *min_b > 0)
	{
		while (*min_a && *min_b)
		{
			(*min_a)--;
			(*min_b)--;
			implement_instruction("rr", list_a, list_b);
		}
	}
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
			implement_instruction("rrb", list_a, list_b);
	}
	else if (min_b > 0)
	{
		while (min_b--)
			implement_instruction("rb", list_a, list_b);
	}
}
