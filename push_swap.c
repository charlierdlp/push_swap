/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:17:06 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/09/07 14:26:00 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *a, t_stack *b, t_stack *copy)
{
	a->head = NULL;
	b->head = NULL;
	copy->head = NULL;
	a->size = 0;
	b->size = 0;
	copy->size = 0;
}

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

void	sort_five(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		while (a->size > 3)
			write_push(a, b, "pb");
		if (!is_sorted(a))
			sort_three(a);
		write_push(a, b, "pa");
		write_push(a, b, "pa");
		insertion_sort(a, b);
	}		
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
			insertion_sort(a, b);
		else if (a->size >= 6 && a->size <= 500)
			sort_hundred(a, b, copy);
		else if (a->size == 1 || a->size > 500)
			exit_msg(a, b, copy);
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
	}
	else if (argc != 1)
		exit_msg(NULL, NULL, NULL);
	return (0);
}
