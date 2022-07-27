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

int	game(char *map, t_mapdata *data)
{
	t_mlx	game;
	t_ass	assets;

	write(1, "\nAAAA\n", 6);
	if (!init_game(&game, data))
	{
		printf("ERROR INITING GAME\n");
		return (0);
	}
	write(1, "\nAAAA\n", 6);
	if (!put_map(&game, map, &assets, data))
	{
		printf("ERROR INITING GAME\n");
		return (0);
	}
	write(1, "\nAAAA\n", 6);
	start_game(&game);
	return (1);
}

int	put_map(t_mlx *game, char *map, t_ass *assets, t_mapdata *data)
{
	int8_t	indx;

	data->nl = 0;
	data->width = 0;
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
			if (indx != 3)
			{
				if (!assets_selector(game, assets, indx))
					return (0);
			}
			if (!assets_selector(game, assets, indx))
				return (0);
		}
		data->width++;
		map++;
	}
	return (1);
}

int	start_game(t_mlx *game)
{
	mlx_hook(game->win, 2, 1L<<0, input_read, game);
	mlx_loop(game->ptr);
	return (0);
}

