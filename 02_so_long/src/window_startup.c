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
    mlx_hook(program->mlx_win, 2, 1L<<0, input_read, program);
	mlx_loop(program->mlx_ptr);
    return (0);
}

int	input_read(int keypress, t_program *program)
{
    if (keypress == 65307)
        mlx_destroy_window(program->mlx_ptr, program->mlx_win);
    else
        printf("Key: -%c-\n", keypress);
    return (0);
}

t_image window_image(t_program *program)
{
	t_image	image;
	int		width;
	int		height;

    mlx_new_image(program->mlx_ptr, 150, 150);
    image.ptr = mlx_xpm_file_to_image(program->mlx_ptr, "../ass/right.xpm", &width, &height);
    if (!image.ptr)
        printf("\nERROR CREATING IMAGE\n");
    else
    {
        image.size_x = width;
        image.size_y = height;
    }
    // mlx_put_image_to_window(program->mlx_ptr, program->mlx_win, image.ptr, 0 ,0);
    return (image); 

}
