/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:16:21 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/05/11 13:31:23 by cruiz-de         ###   ########.fr       */
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
}              t_stack;

void swap(t_stack *stack);
void push(t_stack *a, t_stack *b);
void rotate(t_stack *a);
void rev_rotate(t_stack *a);

#endif