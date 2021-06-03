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