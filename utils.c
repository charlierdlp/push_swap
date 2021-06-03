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
