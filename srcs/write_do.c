/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:37:53 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/09/07 13:37:59 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	write_swap(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "sa"))
	{
		swap(a);
		printf("sa\n");
	}
	else if (!ft_strcmp(str, "sb"))
	{
		swap(b);
		printf("sb\n");
	}
	else if (!ft_strcmp(str, "ss"))
	{
		swap(a);
		swap(b);
		printf("ss\n");
	}
}

void	write_push(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "pa"))
	{
		push(b, a);
		printf("pa\n");
	}
	else if (!ft_strcmp(str, "pb"))
	{
		push(a, b);
		printf("pb\n");
	}
}

void	write_rotate(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "ra"))
	{
		rotate(a);
		printf("ra\n");
	}
	else if (!ft_strcmp(str, "rb"))
	{
		rotate(b);
		printf("rb\n");
	}
	else if (!ft_strcmp(str, "rr"))
	{
		rotate(a);
		rotate(b);
		printf("rr\n");
	}
}

void	write_revrot(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "rra"))
	{
		rev_rotate(a);
		printf("rra\n");
	}
	else if (!ft_strcmp(str, "rrb"))
	{
		rev_rotate(b);
		printf("rrb\n");
	}
	else if (!ft_strcmp(str, "rrr"))
	{
		rev_rotate(a);
		rev_rotate(b);
		printf("rrr\n");
	}
}
