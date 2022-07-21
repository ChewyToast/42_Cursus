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

int window_startup(t_program *program)
{
    mlx_hook(program->mlx_win, 2, 1L<<0, end_prg, program);
	mlx_loop(program->mlx_ptr);
    return (0);
}

int	end_prg(int keycode, t_program *program)
{
    printf("KEYPRESSED: %c\n", keycode);
	mlx_destroy_window(program->mlx_ptr, program->mlx_win);
	return (0);
}