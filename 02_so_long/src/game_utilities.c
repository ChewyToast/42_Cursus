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

int	assets_selector(t_mlx *game, t_ass *assets, int8_t mode)
{
	if (mode == 0)
	{
		if (!assets_init(assets->end, KING, game))
			return (0);
	}
	else if (mode == 1)
	{
		if (!assets_init(assets->player, QUEEN, game))
			return (0);
	}
	else if (mode == 2)
	{
		write(1, "\nAAAA\n", 6);
		if (!assets_init(assets->collect, COLLECT, game))
			return (0);
		write(1, "\nAAAA\n", 6);
	}
	else if (mode == 3)
	{
		if (!assets_init(assets->empty, BACKGROUND, game))
			return (0);
	}
	return (1);
}

int assets_init(t_img *ptr, char *str, t_mlx *game)
{
	t_img	*tmp;

	tmp = ptr;
	if (!*ptr)
	{
		ptr->ptr = mlx_xpm_file_to_image(game->ptr, str, &ptr->width, &ptr->height);
		if (!ptr->ptr)
			return (0);
		ptr->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->ptr = mlx_xpm_file_to_image(game->ptr, str, &tmp->width, &tmp->height);
		if (!tmp->ptr)
			return (0);
		tmp->next = NULL;
	}
	return (1);
}

int	put_ass(t_mlx *game, t_ass *assets)
{
	if (!mlx_put_image_to_window(game->ptr, game->win, assets->empty->ptr, 128, 128))
		return (0);
	return (1);
}
