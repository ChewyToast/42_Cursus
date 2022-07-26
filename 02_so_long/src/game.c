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

static int	init_game(t_mlx *game, t_mapdata *data);
static int	init_assets(t_mlx *game, t_ass *assets, t_mapdata *data);
static int	put_ass(t_mlx *game, t_ass *assets);
static int	start_game(t_mlx *game);
static int	input_read(int keypress, t_mlx *game);


int	game(char *map, t_mapdata *data)
{
	(void)map;
	t_mlx	game;
	t_ass	assets;

	if (!init_game(&game, data))
	{
		printf("ERROR INITING GAME\n");
		return (0);
	}
	if (!init_assets(&game, &assets, data))
	{
		printf("ERROR CREATING IMAGE\n");
		return (0);
	}
	if (!put_ass(&game, &assets))
	{
		printf("ERROR PUTING IMAGES TO WINDOW\n");
		return (0);
	}
	start_game(&game);
	return (1);
}

static int	init_game(t_mlx *game, t_mapdata *data)
{
	game->ptr = mlx_init();
	if (!game->ptr)
		return (0);
	game->win = mlx_new_window(game->ptr, data->width * 128, (data->nl + 1) * 128, "game");
	if (!game->ptr)
		return (0);
	return (1);
}

static int	init_assets(t_mlx *game, t_ass *assets, t_mapdata *data)
{
	t_img	tmp;
	(void)data;

	tmp.ptr = mlx_xpm_file_to_image(game->ptr, KING, &tmp.width, &tmp.height);
	if (!tmp.ptr)
		return (0);
	assets->empty = &tmp;
	return (1);
}

static int	put_ass(t_mlx *game, t_ass *assets)
{
	if (!mlx_put_image_to_window(game->ptr, game->win, assets->empty->ptr, 128, 128))
		return (0);
	return (1);
}

static int start_game(t_mlx *game)
{
    mlx_hook(game->win, 2, 1L<<0, input_read, game);
	mlx_loop(game->ptr);
    return (0);
}

static int	input_read(int keypress, t_mlx *game)
{
    if (keypress == 65307)
        mlx_destroy_window(game->ptr, game->win);
    else
        printf("Key: -%c-\n", keypress);
    return (0);
}
