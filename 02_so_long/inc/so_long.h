/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:41:34 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/21 11:50:06 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// 						~ LIBRARYS ~

// LIBRARY FOR THE MLX FUNCTIONS
# include "../inc/mlx/mlx.h"

// LIBFT LIBRARY
# include "../inc/libft/libft.h"

// LIBRARY FOR THE PRINTF
# include <stdio.h>

// LIBRARY FOR READ AND WRITE FILES
#include <unistd.h>

// LIBRARY FOR OPEN AND CLOSE FILES
#include <fcntl.h>

// 						~ STRUCTS ~

// THERE WE SAVE THE PROGRAM AND WINDOW POINTERS
typedef struct	s_mlx
 {
	void	*ptr;
	void	*win;
	void	*img_ptr;
}				t_mlx;

// THIS GONNA BE A LIST OF ALL THE IMG OF EVERY TYPE OF ASSET
typedef struct	s_img
{
	void	*ptr;
	int		width;
	int		height;
	void	*next;
}				t_img;

// THIS STRUCT GONNA BE THE DATTA OF AN IMAGE
typedef struct	s_ass
 {
	t_img	*player;
	t_img	*wall;
	t_img	*empty;
	t_img	*collect;
	t_img	*start;
	t_img	*end;
}				t_ass;

// UTILITY STRUCT FOR THE CHECK MAP PROCESS
typedef struct	s_mapdata
{
	int16_t	fd;
	char	buff;
	size_t	ln;
	size_t	nl;
	int8_t	indx;
	size_t	walls;
	int16_t	e;
	size_t  c;
	int16_t	p;
	size_t	empty;
	size_t	width;
}				t_mapdata;

// 						~ MACROS ~

# define BACKGROUND "ass/white_background.xpm"
# define KING "ass/king.xpm"

// 						~ FUNCTIONS ~

//		main.c
int		main(int argc, char **argv);

//		input_checker.c
char	*map_reader(char *input, t_mapdata	*data);
int		map_size(char *input, t_mapdata *data);
int8_t	conditioner(t_mapdata *data);
int8_t	check_surrounded(char *map, t_mapdata *data, size_t	width_counter);

// 		game.c
int	game(char *map, t_mapdata *data);

//		initializer.c
t_mapdata   data_initialize(void);

#endif