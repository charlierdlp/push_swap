#include "push_swap.h"

void    rm_lst(void *node)
{
    free(node);
}

void exit_msg(t_stack *a, t_stack *b)
{
    write(2, "Error\n", 6);
    if (a)
        ft_lstclear(&a->head, &rm_lst);
    else
        ft_lstclear(&b->head, &rm_lst);   
}

void bubble_sort(char *args, int size)
{
    int i;
    int swapped;
    int swap;

    swap = 0;
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        i = 0;
        while (i < size)
        {
            if (args[i] > args[i + 1])
            {
                swap = args[i];
                args[i] = args[i + 1];
                args[i + 1] = swap;
                swapped = 1;
            }
            i++;
        }
    }
}

void sort_num(t_stack *a)
{
    t_list *lst;
    t_list *tmp;
    t_list *max;
    int     swapped;

    max = NULL;
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        lst = a->head;
        while (lst->next != max)
        {
            if (*((int *)lst->content) > *((int *)(lst->next)->content))
            {
                tmp = lst->content;
                lst->content = (lst->next)->content;
                (lst->next)->content = tmp;
                swapped = 1;
            }
            lst = lst->next;
        }
        max = lst;
    }
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

int     stack_biggest(t_stack *a)
{
    int big;
    int pos;
    t_list *lst;

    pos = 1;
    lst = a->head;
    big = *((int *)lst->content);
    while (lst)
    {
        if (*((int *)lst->content) > big)
        {
            big = *((int *)lst->content);
            pos++;
        }
        lst = lst->next;
    }
    return (pos);
}

int     stack_smallest(t_stack *a)
{
    int small;
    int pos;
    t_list *lst;

    pos = 1;
    lst = a->head;
    small = *((int *)lst->content);
    while (lst)
    {
        if (*((int *)lst->content) < small)
        {
            small = *((int *)lst->content);
            pos++;
        }
        lst = lst->next;
    }
    return (pos);
}

int    is_sorted(t_stack *a)
{
    t_list  *lst;
    int     *prev;

    if (a->head)
    {
        prev = a->head->content;
        lst = a->head->next;
        while (lst)
        {
            if (*((int *)prev) > *((int *)lst->content))
            {
                //write(1, "KO\n", 3);
                return (0);
            }
            prev = lst->content;
            lst = lst->next;
        }
       // write(1, "OK\n", 3);
    }
    return (1);
}
