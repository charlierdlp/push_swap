/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:45:14 by cruiz-de          #+#    #+#             */
/*   Updated: 2022/01/07 18:54:55 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rm_lst(void *node)
{
	free(node);
}

void	exit_msg(t_stack *a, t_stack *b, t_stack *copy, int error)
{
	if (error)
		write(2, "Error\n", 6);
	if (a)
		ft_lstclear(&a->head, &rm_lst);
	if (b)
		ft_lstclear(&b->head, &rm_lst);
	if (copy)
		ft_lstclear(&copy->head, &rm_lst);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	if (args)
		free(args);
}

int	stack_biggest(t_stack *a)
{
	int		big;
	int		pos;
	int		i;
	t_list	*lst;

	i = 1;
	pos = 1;
	lst = a->head;
	big = -2147483648;
	while (lst)
	{
		if (*((int *)lst->content) > big)
		{
			big = *((int *)lst->content);
			pos = i;
		}
		i++;
		lst = lst->next;
	}
	return (pos);
}

int	stack_smallest(t_stack *a)
{
	int		small;
	int		pos;
	int		i;
	t_list	*lst;

	i = 1;
	pos = 1;
	lst = a->head;
	small = 2147483647;
	while (lst)
	{
		if (*((int *)lst->content) < small)
		{
			small = *((int *)lst->content);
			pos = i;
		}
		i++;
		lst = lst->next;
	}
	return (pos);
}
