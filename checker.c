/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:20:57 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/05/24 19:30:07 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rm_lst(void *node)
{
    free(node);
}

void 	free_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int is_equal(t_stack *a)
{
    
}

int    is_sorted(t_stack *a)
{
    t_list  *lst;
    int     prev;

    if (a->head)
    {
        prev = (int)a->head->content;
        lst = a->head->next;
        while (lst)
        {
            if (prev > (int)lst->content)
            {
                write(1, "KO\n", 3);
                return (1);
            }
            prev = (int)lst->content;
            lst = lst->next;
        }
        write(1, "OK\n", 3);
    }
    return (0);
}

int check_instruction(char *line, t_stack *a, t_stack *b)
{
    if (!ft_strcmp(line, "sa"))
        swap(a);
    else if (!ft_strcmp(line, "pa"))
        push(a, b);
    else if (!ft_strcmp(line, "ra"))
        rotate(a);
    else if (!ft_strcmp(line, "rra"))
        rev_rotate(a);
    else
        return (-1);
    return (0);
}

int myisdigit(char c)
{
	printf("%c", c);
	return (c == '-' || ft_isdigit(c));
}

int	fill_stack(char *args, t_stack *a)
{
	int *num;
	t_list *node;

	num = malloc(sizeof(int));
	num[0] = ft_atoi(args);
	node = ft_lstnew(num);
	ft_lstadd_back(&a->head, node);
}

int parse_args(char *argv, t_stack *a)
{
    int i;
	int j;
	int k;
	char **args;

		j = 0;
		args = ft_split(argv, ' ');
		while (args[j])
		{
			k = 0;
			if ((args[j][k] == '-' && ft_isdigit(args[j][k + 1])) || ft_isdigit(args[j][k]))
			{
				fill_stack(args[j], a);
				i++;
				k++;
			}
			else
			{
				printf("Error\n");
				free_args(args);
				return (1);
			}
			free_args(args);
			j++;
		}
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int r;
    int *num;
    int one;
    char *line;
    t_list *node;
    t_stack a;
    t_stack b;

    i = 1;
    r = 1;
    a.head = NULL;
    b.head = NULL;
    if (argc > 1)
    {
		while (argv[i])
		{
            if (parse_args(argv[i], &a))
                return (1);
			/*
            num = malloc(sizeof(int));
            num[0] = ft_atoi(argv[i]);
            node = ft_lstnew(num);
            ft_lstadd_back(&a.head, node);
			*/
            i++;
		}
    }
    while (get_next_line(0, &line) > 0 && r)
    {
       r = check_instruction(line, &a, &b);
       free(line);
    }
	is_sorted(&a);
    /*
   t_list *lst = a.head;
    while (lst)
    {
        printf("%d\n", *((int *)lst->content));
        lst = lst->next;
    }
    */
    ft_lstclear(&a.head, &rm_lst);
//	system("leaks checker");
    return (0);
}