/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:52:37 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/09/22 17:57:51 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack *a, t_stack *b, t_stack *copy)
{
	a->head = NULL;
	b->head = NULL;
	copy->head = NULL;
	a->size = 0;
	b->size = 0;
	copy->size = 0;
}

void	swap(t_stack *stack)
{
	void	*tmp;

	if (stack->head->next != NULL)
	{
		tmp = stack->head->content;
		stack->head->content = stack->head->next->content;
		stack->head->next->content = tmp;
	}
}

void	push(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (a->size > 0)
	{
		tmp = a->head;
		a->head = tmp->next;
		tmp->next = b->head;
		b->head = tmp;
		b->size++;
		a->size--;
	}
}

void	rotate(t_stack *a)
{
	t_list	*tmp;
	t_list	*aux;

	if (a->head)
	{
		tmp = a->head;
		a->head = tmp->next;
		aux = ft_lstlast(a->head);
		aux->next = tmp;
		tmp->next = NULL;
	}
}

void	rev_rotate(t_stack *a)
{
	t_list	*last;
	t_list	*previus;

	if (a->head)
	{
		last = a->head;
		previus = NULL;
		while (last->next != NULL)
		{
			previus = last;
			last = last->next;
		}
		previus->next = NULL;
		last->next = a->head;
		a->head = last;
	}
}
