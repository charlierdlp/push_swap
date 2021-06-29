#include "push_swap.h"

void simplify_negative(t_stack *a, t_stack *copy)
{
    int j;
    t_list *input;
    t_list *duplicate;

    input = a->head;
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

void sort_hundred(t_stack *a, t_stack *b, t_stack *copy)
{
    t_list *lsta;
    t_list *lstb;
    int i;
    int j;
    int max_num;
    int max_bits;
    int num;
    int size;

    i = 0;
    j = 0;
    size = a->size;
    max_bits = 0;
    max_num = size - 1;

    while ((max_num >> max_bits) != 0)
        ++max_bits;
    sort_num(copy);
    simplify_negative(a, copy);

    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = *((int *)(a->head)->content);
            if (((num >> i) & 1) == 1)
                write_rotate(a, NULL, "ra");
            else
                write_push(a, b, "pb");
            j++;
        }
        while (b->head)
            write_push(a, b, "pa");
        i++;
    }
}