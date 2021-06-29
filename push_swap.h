/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:16:21 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/06/03 20:33:10 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_stack
{
    t_list *head;
    int     size;
}              t_stack;

void sort_num(t_stack *a);
void sort_hundred(t_stack *a, t_stack *b, t_stack *copy);
void bubble_sort(char *args, int size);
int     stack_biggest(t_stack *a);
int     stack_smallest(t_stack *a);
void write_swap(t_stack *a, t_stack *b, char *str);
void write_push(t_stack *a, t_stack *b, char *str);
void write_rotate(t_stack *a, t_stack *b, char *str);
void write_revrot(t_stack *a, t_stack *b, char *str);
void rm_lst(void *node);
void free_args(char **args);
void swap(t_stack *stack);
void push(t_stack *a, t_stack *b);
void rotate(t_stack *a);
void rev_rotate(t_stack *a);
int is_sorted(t_stack *a);
void check_duplicate(t_stack *a);
void exit_msg(t_stack *a, t_stack *b);

#endif