/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:17:06 by cruiz-de          #+#    #+#             */
/*   Updated: 2022/01/07 18:55:19 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *a)
{
	int	big;
	int	small;

	big = stack_biggest(a);
	small = stack_smallest(a);
	if (big == 1 && small == 2)
		write_rotate(a, NULL, "ra");
	else if (big == 1 && small == 3)
	{
		write_swap(a, NULL, "sa");
		write_revrot(a, NULL, "rra");
	}
	else if (big == 2 && small == 1)
	{
		write_swap(a, NULL, "sa");
		write_rotate(a, NULL, "ra");
		if (!is_sorted(a))
			write_swap(a, NULL, "sa");
	}
	else if (big == 2 && small == 3)
		write_revrot(a, NULL, "rra");
	else
		write_swap(a, NULL, "sa");
}

void	move_smallest(t_stack *a, t_stack *b, int small)
{
	if (small == 1)
		write_push(a, b, "pb");
	else if (small == 2)
	{
		write_rotate(a, NULL, "ra");
		write_push(a, b, "pb");
	}
	else if (small == 3)
	{
		write_rotate(a, NULL, "ra");
		write_rotate(a, NULL, "ra");
		write_push(a, b, "pb");
	}
	else if (small == 4)
	{
		if (a->size == 5)
			write_revrot(a, NULL, "rra");
		write_revrot(a, NULL, "rra");
		write_push(a, b, "pb");
	}
	else
	{
		write_revrot(a, NULL, "rra");
		write_push(a, b, "pb");
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	small;

	small = stack_smallest(a);
	move_smallest(a, b, small);
	small = stack_smallest(a);
	move_smallest(a, b, small);
	if (!is_sorted(a))
		sort_three(a);
	write_push(a, b, "pa");
	write_push(a, b, "pa");
}

void	check_case(t_stack *a, t_stack *b, t_stack *copy)
{
	if (!is_sorted(a))
	{
		if (a->size == 2)
			write_swap(a, NULL, "sa");
		else if (a->size == 3)
			sort_three(a);
		else if (a->size == 4 || a->size == 5)
			sort_five(a, b);
		else if (a->size >= 6 && a->size <= 500)
			sort_hundred(a, b, copy);
		else if (a->size == 1 || a->size > 500)
			exit_msg(a, b, copy, 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;
	t_stack	copy;

	i = 1;
	if (argc >= 1)
	{
		init_stacks(&a, &b, &copy);
		while (argv[i])
		{
			if (!parse_args(argv[i], &a, &copy))
				return (1);
			i++;
		}
		check_duplicate(&a);
		check_case(&a, &b, &copy);
		exit_msg(&a, &b, &copy, 0);
	}
	else if (argc != 1)
		exit_msg(NULL, NULL, NULL, 1);
	return (0);
}
