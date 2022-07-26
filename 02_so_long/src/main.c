/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:41:34 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/24 09:57:52 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../inc/so_long.h"
/*
					~MAIN.C~

*	1_CHECK THE INPUT
**			- Num of arguments (2)
**			- File path have to end with ".ber"

*/

static int	error_exit(int8_t mode);

// 1_ STARTUP OF THE PRGRAM
int	main(int argc, char **argv)
{
	char		*map;
	t_mapdata	data;

	if (argc != 2)
		return (error_exit(1));
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4))
			, ".ber", ft_strlen(argv[1])))
		return (error_exit(2));
	printf("Correct input\n");
	map = map_reader(argv[1], &data);
	if (!map)
		return (error_exit(3));
	if (!game(map, &data))
		return (error_exit(4));
	printf("Correct map composition\n");
	free(map);
}

// FUNCTION TO RETURN 0 AND PRINT THE ERROR
static int	error_exit(int8_t mode)
{
	if (mode == 1)
		printf("Error\nWrong input\n");
	if (mode == 2)
		printf("Error\nWrong file extension\n");
	if (mode == 3)
		printf("Error\nWrong map composition\n");
	if (mode == 4)
		printf("Error\nGame error\n");
	return (0);
}
