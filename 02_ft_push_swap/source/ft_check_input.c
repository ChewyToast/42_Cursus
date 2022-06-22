#include "push_swap.h"

//printf("\nX: %ld, Y: %ld, input[x][y]: %c\n", x, y, input[x][y]);
//printf("\nX: %ld, input[x]: %s\n", x, input[x]);

static size_t	check_dobles(char **input)
{
	size_t	x;
	size_t	x2;

	x = 1;
	while (input[x] != NULL)
	{
		x2 = 1;
		while (x - x2 > 0)
		{
			if (x > 1 && (!ft_strncmp(input[x], input[x - x2], 0xffffffff)))
				return (0);
			x2++;
		}
		x++;
	}
	return (1);
}

size_t	check_input(char **input)
{
	size_t	x;
	size_t	y;

	x = 1;
	y = 0;
	while (input[x] != NULL)
	{
		y = 0;
		if ((input[x][y] >= '0' && input[x][y] <= '9')
			|| ((input[x][y] == '-')
			&& (input[x][y + 1] >= '0' && input[x][y + 1] <= '9')))
		{
			y++;
			while (input[x][y] >= '0' && input[x][y] <= '9')
				y++;
			if (input[x][y] != '\0')
				return (0);
		}
		else
			return (0);
		x++;
	}
	return (check_dobles(input));
}
