#include "push_swap.h"

void sort_hundred(t_stack *a, t_stack *b, t_stack *copy)
{
    t_list *input;
    t_list *duplicate;
    int i;
    int j;

    i = 0;
    j = 0;
    input = a->head;
    sort_num(copy);
    while (input)
    {
        duplicate = copy->head;
        j = 0;
        while (duplicate)
        {
            if (*((int *)input->content) == *((int *)duplicate->content))
            {
                *((int *)input->content) = j;
                break;
            }
            duplicate = duplicate->next;
            j++;
        }
        input = input->next;
    }
    ft_lstclear(&copy->head, &rm_lst);
}