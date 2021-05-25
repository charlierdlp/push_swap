/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:52:37 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/05/24 17:16:15 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
    void *tmp;

    if (stack->head->next != NULL)
    {
        printf("works\n");
        tmp = stack->head->content;
        stack->head->content = stack->head->next->content;
        stack->head->next->content = tmp;
    }
}