/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:09:14 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/07/26 13:27:17 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack(char *args, t_stack *a)
{
	int		i;
	int		*num;
	t_list	*node;

	i = 0;
	if (args[i] == '-' || args[i] == '+')
		i++;
	while (args[i])
	{
		if (!ft_isdigit(args[i]))
			return (0);
		i++;
	}
	num = malloc(sizeof(int));
	if (ft_atol(args) > 2147483647 || ft_atol(args) < -2147483648)
		return (0);
	num[0] = ft_atoi(args);
	node = ft_lstnew(num);
	ft_lstadd_back(&a->head, node);
	a->size++;
	return (1);
}

int	parse_args(char *argv, t_stack *a, t_stack *copy)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	if (ft_strchr(argv, ' '))
	{	
		args = ft_split(argv, ' ');
		while (args[i])
		{
			j = 0;
			if ((args[i][j] == '-' && ft_isdigit(args[i][j + 1]))
				|| ft_isdigit(args[i][j]))
			{
				fill_stack(args[i], a);
				j++;
			}
			else
			{
				exit_msg(a, NULL);
				free_args(&args[i]);
				return (0);
			}
			free_args(args);
			i++;
		}
	}
	else if ((argv[i] == '-' && ft_isdigit(argv[i + 1])) || ft_isdigit(argv[i]))
	{
		if (!fill_stack(argv, a))
		{
			exit_msg(NULL, NULL);
			return (0);
		}
	}
	else
	{
		exit_msg(NULL, NULL);
		return (0);
	}
	return (1);
}

void	check_duplicate(t_stack *a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = a->head;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (*((int *)tmp1->content) == *((int *)tmp2->content))
			{
				exit_msg(NULL, NULL);
				exit(EXIT_FAILURE);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	is_sorted(t_stack *a)
{
	t_list	*lst;
	int		*prev;

	if (a->head)
	{
		prev = a->head->content;
		lst = a->head->next;
		while (lst)
		{
			if (*((int *)prev) > *((int *)lst->content))
				return (0);
			prev = lst->content;
			lst = lst->next;
		}
	}
	return (1);
}
