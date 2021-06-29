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

int parse_args(char *argv, t_stack *a, t_stack *copy)
{
	int i;
	int j;
	char **args;

	i = 0;
	if (ft_strchr(argv, ' '))
	{	
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
				exit_msg(a, NULL);
				free_args(&args[i]);
				return (1);
			}
			free_args(args);
			i++;
		}
	}
	else
	{
		fill_stack(argv, a);
		fill_stack(argv, copy);
	}
    return (0);
}

void sort_three(t_stack *a)
{
	int big;
	int small;

	big = stack_biggest(a);
	small = stack_smallest(a);
//	printf("%d\n", big);
//	printf("%d\n", small);


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
	}
	else if (big == 2 && small == 3)
		write_revrot(a, NULL, "rra");
	else
		write_swap(a, NULL, "sa");
}

void sort_five(t_stack *a, t_stack *b)
{
	while (!is_sorted(a))
	{
		while (a->size > 3)
			write_push(a, b, "pb");
		if (!is_sorted(a))
			sort_three(a);
		if (stack_biggest(b) == 1)
		{
			write_push(a, b, "pa");
			write_rotate(a, b, "ra");
			write_push(a, b, "pa");
		}
		else
		{
			write_push(a, b, "pa");
			write_push(a, b, "pa");
			write_rotate(a, b, "ra");
		}
	}		
}

void check_case(t_stack *a, t_stack *b, t_stack *copy)
{
	if (!is_sorted(a))
	{
		if (a->size == 2)
			write_swap(a, NULL, "sa");
		else if (a->size == 3)
			sort_three(a);
		else if (a->size >= 4 && a->size <= 5)
			sort_five(a, b);
		else if (a->size >=6 && a->size <= 500)
			sort_hundred(a, b, copy);
		else if (a->size == 1 || a->size > 500)
			exit_msg(a, b);
	}
}

int main(int argc, char **argv)
{
    int i;
    t_stack a;
    t_stack b;
	t_stack copy;

    i = 1;
    a.head = NULL;
    b.head = NULL;
	copy.head = NULL;
	a.size = 0;
	b.size = 0;
	copy.size = 0;
    if (argc > 1)
    {
		while (argv[i])
		{
            if (parse_args(argv[i], &a, &copy))
                return (1);
			i++;
		}
		check_case(&a, &b, &copy);
	}/*
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
    }*/
    ft_lstclear(&a.head, &rm_lst);
    ft_lstclear(&b.head, &rm_lst);
	return (0);
}