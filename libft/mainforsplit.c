#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**str_split;

	str_split = ft_split(av[1], av[2][0]);
	printf("\n\n---RESULTADO--\n\n");
	if (!str_split)
		printf("No hay resultado mejor dedicate al parchis...\n");
	else
	{
		while (str_split)
		{
			printf("\n-%s-", *str_split);
			str_split++;
		}
	}
}
