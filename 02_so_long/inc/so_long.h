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
}				t_mlx;

// THIS STRUCT GONNA BE THE DATTA OF AN IMAGE
typedef struct	s_img
 {
	void	*ptr;
	char	*pixls;
	int		sizex;
	int		sizey;
}				t_img;

// UTILITY STRUCT FOR THE CHECK MAP PROCESS
typedef struct	s_mapdata
{
	size_t	len;
	int8_t	indx;
	uint8_t	e;
	uint8_t	p;
	size_t  c;
	size_t	empty;
	size_t	walls;
}				t_mapdata;

// 						~ MACROS ~


// 						~ FUNCTIONS ~

#endif