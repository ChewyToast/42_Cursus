/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:32:23 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/26 00:51:08 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../inc/so_long.h"
/*
					~GAME.C~

*	3_CHECK THE INPUT
**			- Init mlx and window
**			- Init background
**			- Init other objects

*/

//	MAIN FUNCTION OF THE GAME, THERE WE MANAGE ALL THE STARTUP PROCES 
int	game(char *map, t_mapdata *data)
{
	t_mlx	game;
	t_ass	assets;

	write(1, "\nGAME\n", 6);
	if (!init_game(&game, data))
	{
		printf("ERROR INITING GAME\n");
		return (0);
	}
	write(1, "\nGAME\n", 6);
	if (!put_map(&game, map, &assets, data))
	{
		printf("ERROR INITING GAME\n");
		return (0);
	}
	write(1, "\nGAME\n", 6);
	start_game(&game);
	return (1);
}

//	HERE WE ANALYZE THE MAP AND CALL TO INITIALIZE ALL THE ASSETS
int	put_map(t_mlx *game, char *map, t_ass *assets, t_mapdata *data)
{
	int8_t	indx;

	data->nl = 0;
	data->width = 0;
	init_assets(assets);
	write(1, "\naMAP\n", 6);
	while (*map)
	{
		if (*map == '0')
			indx = 3;
		else if (*map == '1')
			indx = 2;
		else if (*map == 'E')
			indx = 0;
		else if (*map == 'C')
			indx = 1;
		if (*map == '\n')
		{
			data->nl++;
			data->width = 0;
		}
		else
		{
			write(1, "\nbMAP\n", 6);
			if (!assets_selector(game, assets, indx, data))
				return (0);
			data->width++;
		}
		map++;
	}
	return (1);
}

//	FUNCTION IN CHARGE OF INITIALIZING THE POP-UP SCREEN
int	start_game(t_mlx *game)
{
	write(1, "\nHIHI\n", 6);
	mlx_hook(game->win, 2, 1L<<0, input_read, game);
	mlx_loop(game->ptr);
	return (0);
}

