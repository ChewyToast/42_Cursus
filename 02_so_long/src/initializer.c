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

// FUNCTION TO INICIALIZE STRUCT DATA
t_mapdata	data_initialize(void)
{
	t_mapdata	data;

	data.len = 0;
	data.nl = 0;
	data.indx = 1;
	data.exit = 0;
	data.start = 0;
	data.collect = 0;
	data.empty = 0;
	data.walls = 0;
	data.width = 0;
	return (data);
}

// FUNCTION TO INICIALIZE STRUCT ASSETS
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
}
