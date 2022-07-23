/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:41:34 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/21 11:50:06 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../inc/so_long.h"

/*
					~MAIN.C~

*	1_CHECK THE INPUT
**			- Num of arguments (2)
**			- File path have to end with ".ber"

*	2_CHECK THE CONTNENT OF THE FILE PASSED ASS MAP:
**			- Surrounded by walls (1)
**			- At least one exit (E)
**			- At least one collectible (C)
**			- At least one starting position (P)
**			- Empty space (0)

*/

// STARTUP OF THE PRGRAM
int	main(int8_t argc, char **argv)
{
	char	*map;

	if (argc != 2)
		return (wrong_input(1));
	if (ft_strncmp((argv[1] + (ft_strlen(*argv) - 5))
			, ".ber", ft_strlen(*argv)))
		return (wrong_input(2));
	printf("Correct input\n");
	map = map_reader(argv[1]);
	if (!map)
		return (wrong_input(3));
}

// FUNCTION TO RETURN 0 AND PRINT THE ERROR
static int8_t	wrong_input(int8_t mode)
{
	if (mode == 1)
		printf("Error\nWrong input\n");
	if (mode == 2)
		printf("Error\nWrong file extension\n");
	if (mode == 2)
		printf("Error\nWrong map composition\n");
	return (NULL);
}

// MAP READER AND CHECKER
static char	*map_reader(char *input)
{
	char		*map;
	t_mapdata	data;

	data = map_size(input);
	if ((data.len < 15) || (data.e < 1) || (data.p < 1) || (data.c < 1))
		return (0);
	map = malloc(sizeof(char) * data.len + 1);
	if (!map)
		return (NULL);
	map[data.len] = '\0';

}

// FUNCTION READS AND TAKES ALL THE INFO FOR THE CHECK
static t_mapdata	map_size(char *input)
{
	t_mapdata	data;

	data.fd = open(*input, O_RDONLY);
	if (data.fd < 0)
		return (NULL);
	while (data.indx)
	{
		data.indx = read(data.fd, data.buff, 1);
		if (data.buff == '0')
			++data.empty;
		else if (data.buff == '1')
			++data.walls;
		else if (data.buff == 'E')
			++data.e;
		else if (data.buff == 'C')
			++data.c;
		else if (data.buff == 'P')
			++data.p;
		++data.len;
	}
	close(fd);
	if (data.indx < 0)
		return (0);
	return (data);
}
