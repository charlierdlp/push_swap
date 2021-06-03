#include "push_swap.h"

int	fill_stack(char *args, t_stack *a)
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

int main(int argc, char **argv)
{
    int i;
    t_stack a;
    t_stack b;

    i = 1;
    a.head = NULL;
    b.head = NULL;
	a.size = 1;
    if (argc > 1)
    {
		if (argc == 2)
		while (argv[i])
		{
            if (parse_args(argv[i], &a))
                return (1);
			i++;
		}
    }
	return (0);
}