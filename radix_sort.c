/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:52:36 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/09/07 18:28:35 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_num(t_stack *a)
{
	t_list	*lst;
	t_list	*tmp;
	t_list	*max;
	int		swapped;

	max = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		lst = a->head;
		while (lst->next != max)
		{
			if (*((int *)lst->content) > *((int *)(lst->next)->content))
			{
				tmp = lst->content;
				lst->content = (lst->next)->content;
				(lst->next)->content = tmp;
				swapped = 1;
			}
			lst = lst->next;
		}
		max = lst;
	}
}

void	simplify_negative(t_stack *a, t_stack *copy)
{
	int		j;
	t_list	*input;
	t_list	*duplicate;

	input = a->head;
	while (input)
	{
		duplicate = copy->head;
		j = 0;
		while (duplicate)
		{
			if (*((int *)input->content) == *((int *)duplicate->content))
			{
				*((int *)input->content) = j;
				break ;
			}
			duplicate = duplicate->next;
			j++;
		}
		input = input->next;
	}
	ft_lstclear(&copy->head, &rm_lst);
}

void	sort_hundred(t_stack *a, t_stack *b, t_stack *copy)
{
	t_sort	sort;

	sort.i = -1;
	sort.size = a->size;
	sort.max_bits = 0;
	sort.max_num = sort.size - 1;
	while ((sort.max_num >> sort.max_bits) != 0)
		++sort.max_bits;
	sort_num(copy);
	simplify_negative(a, copy);
	while (++sort.i < sort.max_bits)
	{
		sort.j = 0;
		while (sort.j < sort.size)
		{
			sort.num = *((int *)(a->head)->content);
			if (((sort.num >> sort.i) & 1) == 1)
				write_rotate(a, NULL, "ra");
			else
				write_push(a, b, "pb");
			sort.j++;
		}
		while (b->head)
			write_push(a, b, "pa");
	}
}
