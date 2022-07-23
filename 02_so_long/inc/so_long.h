/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:41:34 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/07/21 11:50:06 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../inc/mlx/mlx.h"
# include <stdio.h>
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

# define PLAYER "ass/right.xpm"
# define BACKGRND "ass/right.xpm"

