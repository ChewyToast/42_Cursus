#include "push_swap.h"

//printf("\nX: %ld, Y: %ld, input[x][y]: %c\n", x, y, input[x][y]);
//printf("\nX: %ld, input[x]: %s\n", x, input[x]);
//printf("\ninput: %c -- %c :min_value\n", input[x][y],  min_value[y]);

static size_t	extra_function(char *input, char *max_value, char *min_value)
{
	size_t	y;

	y = 0;
	while (input[y])
	{
		if (((input[0] != '-') && (input[y] > max_value[y]))
			|| ((input[0] == '-') && (input[y] > min_value[y])))
			return (0);
		y++;
	}
	return (1);
}

//THRD STEP, CHECK IF THERE ARE NUMBERS HI
static size_t	check_size(char **input)
{
	size_t	x;
	size_t	y;

	x = 1;
	while (input[x])
	{
		y = 0;
		while (input[x][y])
			y++;
		if ((y > 10 && input[x][0] != '-') || (y > 11 && input[x][0] == '-'))
			return (0);
		else if ((y < 10 && input[x][0] != '-')
				|| (y < 11 && input[x][0] == '-'))
			;
		else
			if (!extra_function(input[x], "2147483647", "-2147483647"))
				return (0);
		x++;
	}
	return (1);
}

// SECOND STEP, CHECK IF THERE ARE DOBLES
static size_t	check_dobles(char **input)
{
	size_t	x;
	size_t	x2;

	x = 1;
	while (input[x])
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
	return (check_size(input));
}

// FIRST STEP, SEE THE CHARS OF THE INPUT
size_t	check_input(char **input)
{
	size_t	x;
	size_t	y;

	x = 1;
	y = 0;
	while (input[x])
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
