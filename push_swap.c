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
	int option;

	option = stack_biggest(a);

	if (option == 1)
	{
		swap(a);
		rev_rotate(a);
		write(1, "sa\nrra\n", 8);
	}
	else if (option == 2)
	{
		swap(a);
		rotate(a);
		write(1, "sa\nra\n", 7);
	}
	else if (option == 3)
	{
		
	}
}

void check_case(t_stack *a)
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
    if (argc > 1)
    {
		while (argv[i])
		{
            if (parse_args(argv[i], &a))
                return (1);
			i++;
		}
		check_case(&a);
    }
	   t_list *lst = a.head;
    while (lst)
    {
        printf("%d\n", *((int *)lst->content));
        lst = lst->next;
    }
    ft_lstclear(&a.head, &rm_lst);
	return (0);
}