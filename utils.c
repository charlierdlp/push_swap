#include "push_swap.h"

void	rm_lst(void *node)
{
	free(node);
}

void	exit_msg(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	if (a || b)
	{
		ft_lstclear(&a->head, &rm_lst);
		ft_lstclear(&b->head, &rm_lst);
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	stack_biggest(t_stack *a)
{
	int		big;
	int		pos;
	int		i;
	t_list	*lst;

	i = 1;
	pos = 1;
	lst = a->head;
	big = -2147483648;
	while (lst)
	{
		if (*((int *)lst->content) > big)
		{
			big = *((int *)lst->content);
			pos = i;
		}
		i++;
		lst = lst->next;
	}
	return (pos);
}

int	stack_smallest(t_stack *a)
{
	int		small;
	int		pos;
	int		i;
	t_list	*lst;

	i = 1;
	pos = 1;
	lst = a->head;
	small = 2147483647;
	while (lst)
	{
		if (*((int *)lst->content) < small)
		{
			small = *((int *)lst->content);
			pos = i;
		}
		i++;
		lst = lst->next;
	}
	return (pos);
}
