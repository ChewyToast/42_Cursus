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
# include "../inc/so_long.h"

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
