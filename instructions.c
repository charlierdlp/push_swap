/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:52:37 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/05/20 19:53:17 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
    t_list *tmp;

    if (stack->head->next != NULL)
    {
        tmp = stack->head->content;
        stack = stack->head->next;
        stack->head->next = tmp;
    }
}