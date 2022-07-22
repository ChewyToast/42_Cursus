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
# include "../inc/so_long.h"

int	main(void)
{
	t_program	program;
	t_image		image;

	(void)image;
	program.mlx_ptr = mlx_init();
	program.mlx_win = mlx_new_window(program.mlx_ptr, 1000, 700, "new_window");
	image = window_image(&program);
	window_startup(&program);	
}
