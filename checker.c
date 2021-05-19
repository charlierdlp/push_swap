/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:20:57 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/05/19 13:28:58 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int *num;
    t_list *node;
    t_stack a;
    t_stack b;

    i = 0;
    a.head = NULL;
    if (argc > 1)
    {
        while (argv[i])
        {
            *num = ft_atoi(argv[i]);
            node = ft_lstnew(num);
            ft_lstadd_back(&a.head, num);
            i++;
        }
        t_list *lst = a.head;
    }
    return (0);
}