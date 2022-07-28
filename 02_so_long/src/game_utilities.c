/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:17:53 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/27 02:18:08 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

//	STARTUP OF MLX, INITING THE WINDOW 
int	init_game(t_mlx *game, t_mapdata *data)
{
	game->ptr = mlx_init();
	if (!game->ptr)
		return (0);
	game->win = mlx_new_window(game->ptr, data->width * ASS_SIZE, (data->nl + 1) * ASS_SIZE, "game");
	if (!game->ptr)
		return (0);
	return (1);
}

// THIS FUNCTION WITH THE PARAM MODE, CHOSE THE ASSET TO INIT
int	assets_selector(t_mlx *game, t_ass *assets, int8_t mode, t_mapdata *data)
{
	if (mode == 0)
	{
		if (!assets_init(&assets->end, BACKGROUND, game, data))
		{
			printf("ERROR INITIN\n");
			return (0);
		}
	}
	else if (mode == 1)
	{
		if (!assets_init(&assets->player, COLLIDE, game, data))
		{
			printf("ERROR INITIN\n");
			return (0);
		}
	}
	else if (mode == 2)
	{
		if (!assets_init(&assets->collect, DOOR, game, data))
		{
			printf("ERROR INITIN\n");
			return (0);
		}
	}
	else if (mode == 3)
	{
		if (!assets_init(&assets->empty, KEY, game, data))
		{
			printf("ERROR INITIN\n");
			return (0);
		}
	}
	else if (mode == 4)
	{
		if (!assets_init(&assets->empty, PLAYER, game, data))
		{
			printf("ERROR INITIN\n");
			return (0);
		}
	}
	return (1);
}

//	FUNCTION THATINIT THE ASSET CALLED BY THE ASSETS_SELECTOR
int assets_init(t_img *ptr, char *str, t_mlx *game, t_mapdata *data)
{
	t_img	*tmp;

	tmp = ptr;
	if (tmp->ptr == NULL)
	{
		ptr->ptr = mlx_xpm_file_to_image(game->ptr, str, &ptr->width, &ptr->height);
		if (!ptr->ptr)
			return (0);
		ptr->next = NULL;
		if (!put_ass(game, ptr, data))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->ptr = mlx_xpm_file_to_image(game->ptr, str, &tmp->width, &tmp->height);
		if (!tmp->ptr)
			return (0);
		tmp->next = NULL;
		if (!put_ass(game, tmp, data))
			return (0);
	}
	return (1);
}

//	LAST STEP NECESSARY TO HAVE THE ASSETS ON MLX WINDOW
int	put_ass(t_mlx *game, t_img *img, t_mapdata *data)
{
	if (!mlx_put_image_to_window(game->ptr, game->win, img->ptr, ASS_SIZE * data->width, ASS_SIZE * data->nl))
		return (0);
	return (1);
}
