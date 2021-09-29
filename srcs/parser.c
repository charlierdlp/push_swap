/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:09:14 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/09/22 18:01:32 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && !ft_isdigit(str[i]))
			return (0);
		if ((ft_strlen(str) == 1 && str[i] == '-') || (i != 0 && str[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char *argv, t_stack *a, t_stack *copy)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(argv, ' ');
	while (args[i])
	{
		if (check_num(args[i]))
		{
			fill_stack(args[i], a);
			fill_stack(args[i], copy);
		}
		else
		{
			exit_msg(a, NULL, copy);
			return (0);
		}
		i++;
	}
	free_args(args);
	return (1);
}

int	parse_args(char *argv, t_stack *a, t_stack *copy)
{
	int		i;

	i = 0;
	if (ft_strchr(argv, ' '))
	{	
		if (!check_args(argv, a, copy))
			return (0);
	}
	else if (check_num(argv))
	{
		if (!fill_stack(argv, a))
		{
			exit_msg(NULL, NULL, NULL);
			return (0);
		}
		else
			fill_stack(argv, copy);
	}
	else
	{
		exit_msg(a, NULL, copy);
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
				exit_msg(NULL, NULL, NULL);
				exit(EXIT_FAILURE);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
