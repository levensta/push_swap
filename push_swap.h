#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "bidirectional_list.h"
#include "libft.h"

typedef struct			s_arg
{
	int					value;
	int					index;
}						t_arg;

void	error_print(char *error_message);
int		is_valid_num(char *str);
t_arg	*alloc_element(void);
void	clear_element(void *elem);
void	*copy_element(void *elem);
void	print_element(void *data);
void	lst_indexing(t_blst *lst);
// t_arg	*get_data(void *data);
int		compare_elements(void *a, void *b);
int		compare_lst(t_blst *a, t_blst *b);
void	push(t_blst **dst, t_blst **src);
void	swap(t_blst **lst);
void	rotate(t_blst **lst);
void	rrotate(t_blst **lst);
t_blst	*bd_lstfind2(t_blst *lst, void *data, int (*comp)());
void	implement_instruction(char *command, t_blst **list_a, t_blst **list_b);
void	initialize(t_blst **list_a, t_blst **list_sort, int argc, char **argv);
#endif