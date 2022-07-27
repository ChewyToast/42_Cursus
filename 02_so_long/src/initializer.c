/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:41:34 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/24 09:58:46 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

t_mapdata	data_initialize(void)
{
	t_mapdata	data;

	data.ln = 0;
	data.nl = 0;
	data.indx = 1;
	data.e = 0;
	data.p = 0;
	data.c = 0;
	data.empty = 0;
	data.walls = 0;
	data.width = 0;
	return (data);
}

void	init_assets(t_ass *assets)
{
	t_img	imag;

	imag.ptr = NULL;
	imag.width = 0;
	imag.height = 0;
	imag.next = NULL;

	assets->player = imag;
	assets->wall = imag;
	assets->empty = imag;
	assets->collect = imag;
	assets->end = imag;

	/* assets->player->ptr = NULL;
	assets->player->width = 0;
	assets->player->height = 0;
	assets->player->next = NULL;
	assets->wall->ptr = NULL;
	assets->wall->width = 0;
	assets->wall->height = 0;
	assets->wall->next = NULL;
	assets->empty->ptr = NULL;
	assets->empty->width = 0;
	assets->empty->height = 0;
	assets->empty->next = NULL;
	assets->collect->ptr = NULL;
	assets->collect->width = 0;
	assets->collect->height = 0;
	assets->collect->next = NULL;
	assets->end->ptr = NULL;
	assets->end->width = 0;
	assets->end->height = 0;
	assets->end->next = NULL; */
}

