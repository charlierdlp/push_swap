/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:17:06 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/06/03 20:32:54 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(char *args, t_stack *a)
{
	int *num;
	t_list *node;

	num = malloc(sizeof(int));
	num[0] = ft_atoi(args);
	node = ft_lstnew(num);
	ft_lstadd_back(&a->head, node);
	a->size++;
}

int parse_args(char *argv, t_stack *a)
{
	int i;
	int j;
	char **args;

	i = 0;
	args = ft_split(argv, ' ');
	while (args[i])
	{
		j = 0;
		if ((args[i][j] == '-' && ft_isdigit(args[i][j + 1])) || ft_isdigit(args[i][j]))
		{
			fill_stack(args[i], a);
			j++;
		}
		else
		{
			printf("Error\n");
			free_args(args);
			return (1);
		}
		free_args(args);
		i++;
	}
    return (0);
}

void sort_three(t_stack *a)
{
	int big;
	int small;

	big = stack_biggest(a);
	small = stack_smallest(a);


	if (big == 1 && small == 2)
	{
		rotate(a);
		write(1, "ra\n", 4);
	}
	else if (big == 1 && small == 3)
	{
		swap(a);
		rev_rotate(a);
		write(1, "sa\nrra\n", 8);
	}
	else if (big == 2 && small == 1)
	{
		swap(a);
		rotate(a);
		write(1, "sa\nra\n", 7);
	}
	else if (big == 2 && small == 3)
	{
		rev_rotate(a);
		write(1, "rra\n", 5);
	}
	else
	{
		swap(a);
		write(1, "sa\n", 4);
	}
}

void sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		push(a, b);
		write(1, "pa\n", 4);
	}
	if (!is_sorted(a))
		sort_three(a);
}

void check_case(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (a->size == 2)
		{
			swap(a);
			write(1, "sa\n", 3);
		}
		else if (a->size == 3)
			sort_three(a);
		else if (a->size >= 4 && a->size <= 6)
			sort_five(a, b);
	}
}

int main(int argc, char **argv)
{
    int i;
    t_stack a;
    t_stack b;

    i = 1;
    a.head = NULL;
    b.head = NULL;
	a.size = 0;
	b.size = 0;
    if (argc > 1)
    {
		while (argv[i])
		{
            if (parse_args(argv[i], &a))
                return (1);
			i++;
		}
		check_case(&a, &b);
    }
	   t_list *lst = a.head;
    while (lst)
    {
        printf("a:%d\n", *((int *)lst->content));
        lst = lst->next;
    }
		   t_list *lst2 = b.head;
    while (lst2)
    {
        printf("b:%d\n", *((int *)lst2->content));
        lst2 = lst2->next;
    }
    ft_lstclear(&a.head, &rm_lst);
    ft_lstclear(&b.head, &rm_lst);

	return (0);
}