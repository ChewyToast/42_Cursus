/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:57:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/24 09:57:44 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"
/*
					~INPUT_CHECKER.C~

*	2_READ AND CHECK THE CONTNENT OF THE FILE PASSED ASS MAP:
**			- Surrounded by walls (1)
**			- At least one exit (E)
**			- At least one collectible (C)
**			- At least one starting position (P)
**			- Empty space (0)

*/

// 2_ MAP READER AND CHECKER
// There we fill the map string and check if is sorrounded by walls
char	*map_reader(char *input, t_mapdata	*data)
{
	char		*map;

	if (!map_size(input, data))
		return (0);
	if ((data->len < 15) || (data->nl < 3) || (data->exit < 1)
		|| (data->start < 1) || (data->collect < 1))
		return (0);
	map = malloc(sizeof(char) * data->len);
	if (!map)
		return (0);
	map[data->len - 1] = '\0';
	data->fd = open(input, O_RDONLY);
	if (data->fd < 0)
		return (0);
	data->indx = 1;
	while (read(data->fd, &data->buff, 1))
		*(map++) = data->buff;
	map -= (data->len - 1);
	if (!check_surrounded(map, data, 0))
	{
		free (map);
		return (0);
	}
	close(data->fd);
	return (map);
}

// 3_ FUNCTION READS AND TAKES ALL THE INFO FOR THE CHECK,
// There we check what chars we have in the map and how many
int	map_size(char *input, t_mapdata *data)
{
	*data = data_initialize();
	data->fd = open(input, O_RDONLY);
	if (data->fd < 0)
		return (0);
	while (data->indx > 0)
	{
		data->indx = read(data->fd, &data->buff, 1);
		if (!conditioner(data))
			return (0);
		data->len++;
	}
	close(data->fd);
	if (data->indx < 0)
		return (0);
	return (1);
}

// JUST A FUNCTION UTILITY FOR THE MAP_SIZE()
int8_t	conditioner(t_mapdata *data)
{
	if (data->buff == '0')
		data->empty++;
	else if (data->buff == '1')
		data->walls++;
	else if (data->buff == 'E')
		data->exit++;
	else if (data->buff == 'C')
		data->collect++;
	else if (data->buff == 'P')
		data->start++;
	else if (data->buff == '\n')
		data->nl++;
	else
		return (0);
	return (1);
}

// FUNCTION TO CHECK IF ITS WALL SURROUNDED, HELPS THE MAP_READER()
int8_t	check_surrounded(char *map, t_mapdata *data, size_t	width_counter)
{
	size_t	nl_count;

	nl_count = 0;
	while (*map != '\0')
	{
		if (*map == '\n')
		{
			if (*(map - 1) == '1' && *(map + 1) == '1')
				nl_count++;
			else
				return (0);
			if (nl_count == 1)
				data->width = width_counter;
			else if (data->width != (width_counter - 1))
				return (0);
			width_counter = 0;
		}
		else if ((nl_count == 0 || nl_count == data->nl) && *map != '1')
			return (0);
		map++;
		width_counter++;
	}
	if (data->width != (width_counter - 1))
		return (0);
	return (1);
}
