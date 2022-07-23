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
typedef struct	s_program
 {
	void	*mlx_ptr;
	void	*mlx_win;
}				t_program;

// THIS STRUCT GONNA BE THE DATTA OF AN IMAGE
typedef struct	s_image
 {
	void	*ptr;
	char	*pixls;
	int		size_x;
	int		size_y;
}				t_image;

# define PLAYER "ass/right.xpm"

// WINDOW_STARTUP FILE
int		input_read(int keypress, t_program *program);
int		window_startup(t_program *program);
t_image window_image(t_program *program);
