#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "bidirectional_list.h"
#include "libft.h"

typedef struct			s_arg
{
	int					value;
	int					i;
	int					rr;
}						t_arg;

void	initialize(t_blst **list_a, t_blst **list_sort, int argc, char **argv);
void	push_all(t_blst **list_a, t_blst **list_b, t_blst **list_sort);
int		min_rotations(t_arg *element);
int		count_rotations(t_blst *a, t_blst *b);
void	double_rotation(int *min_a, int *min_b, t_blst **list_a, t_blst **list_b);
void	circular_rotation_a(int min_a, t_blst **list_a, t_blst **list_b);
void	circular_rotation_b(int min_b, t_blst **list_a, t_blst **list_b);

void	push(t_blst **dst, t_blst **src);
void	swap(t_blst **lst);
void	rotate(t_blst **lst);
void	rrotate(t_blst **lst);
void	implement_instruction(char *command, t_blst **list_a, t_blst **list_b);
void	error_print(char *error_message);

int		is_valid_num(char *str);
t_arg	*alloc_element(void);
void	*copy_element(void *elem);
void	print_element(void *data);
void	lst_indexing(t_blst *lst);
int		cmp_elements(void *a, void *b);
#endif