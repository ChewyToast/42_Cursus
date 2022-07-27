/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:07:46 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/27 02:07:55 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

int	input_read(int keypress, t_mlx *game)
{
	if (keypress == 65307)
		mlx_destroy_window(game->ptr, game->win);
	else
		printf("Key: -%c-\n", keypress);
	return (0);
}

											