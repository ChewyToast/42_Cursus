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

int	game(char *map, t_mapdata	*data)
{
	t_mlx	game;
	int		width;
	int		height;

	game.ptr = mlx_init();
	if (!game.ptr)
	{
		printf("\nERROR INIT\n");
		return (0);
	}
	game.window = mlx_new_window(game.ptr, data->width, data->nl + 1, "game");
	if (!game.ptr)
	{
		printf("\nERROR CREATING WINDOW\n");
		return (0);
	}
	game.img_ptr = mlx_xpm_file_to_image(game.ptr, PLAYER, &width, &height);
	if (!game.ptr)
	{
		printf("\nERROR CREATING IMAGE\n");
		return (0);
	}
	mlx_put_image_to_window(game.ptr, game.window, game.img_ptr, 0, 0);
	return (1);
}
