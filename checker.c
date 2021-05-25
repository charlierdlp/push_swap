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

int check_instruction(char *line, t_stack *a)
{
    if (!ft_strcmp(line, "sa"))
    {
        printf("entro\n");
        swap(a);
    } 
    else 
        return (-1);
    printf("HOLA\n");
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int *num;
    int one;
    char *line;
    t_list *node;
    t_stack a;
    t_stack b;

    i = 1;
    a.head = NULL;
    b.head = NULL;
    if (argc > 1)
    {
        while (argv[i]) // lo de las comillas de alvrodri
        {
            num = malloc(sizeof(int));
            num[0] = ft_atoi(argv[i]);
            node = ft_lstnew(num);
            ft_lstadd_back(&a.head, node);
            i++;
        }
    printf("hola\n");
    t_list *lst = a.head;
    while (lst)
    {
        printf("%d\n", *((int *)lst->content));
        lst = lst->next;
    }
    ft_lstclear(&a.head, &rm_lst);
    }
        printf("hola2\n");
    one = 1;
    while (get_next_line(0, &line) >= 0 && one)
    {
        check_instruction(line, &a);
        one = 0;
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