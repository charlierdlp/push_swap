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
