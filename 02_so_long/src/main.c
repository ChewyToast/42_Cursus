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
# include "../inc/so_long.h"
/*
					~MAIN.C~

*	1_CHECK THE INPUT
**			- Num of arguments (2)
**			- File path have to end with ".ber"

*/

static int	wrong_input(int8_t mode);

// 1_ STARTUP OF THE PRGRAM
int	main(int argc, char **argv)
{
	char	*map;

	if (argc != 2)
		return (wrong_input(1));
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4))
			, ".ber", ft_strlen(argv[1])))
		return (wrong_input(2));
	printf("Correct input\n");
	map = map_reader(argv[1]);
	if (!map)
		return (wrong_input(3));
	printf("Correct map composition\n");
	free(map);
}

// FUNCTION TO RETURN 0 AND PRINT THE ERROR
static int	wrong_input(int8_t mode)
{
	if (mode == 1)
		printf("Error\nWrong input\n");
	if (mode == 2)
		printf("Error\nWrong file extension\n");
	if (mode == 3)
		printf("Error\nWrong map composition\n");
	return (0);
}
