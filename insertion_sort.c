/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:04:57 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/07/05 20:07:43 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	front(t_stack *a, t_stack *b, int pos)
{
	while (pos--)
		write_rotate(a, NULL, "ra");
	write_push(a, b, "pb");
}

void	back(t_stack *a, t_stack *b, int pos)
{
	pos = a->size - pos;
	while (pos--)
		write_revrot(a, NULL, "rra");
	write_push(a, b, "pb");
}

void	insertion_sort(t_stack *a, t_stack *b)
	{
	int		small;
	int		i;
	int		pos;
	t_list	*tmp;

	while (a->head)
	{
		i = 0;
		pos = 0;
		tmp = a->head;
		small = *((int *)tmp->content);
		while (tmp->next)
		{
			tmp = tmp->next;
			++i;
			if (*((int *)tmp->content) < small && (pos = i))
				small = *((int *)tmp->content);
		}
		if (pos <= a->size / 2)
			front(a, b, pos);
		else
			back(a, b, pos);
	}
	while (b->head)
		write_push(a, b, "pa");
}
