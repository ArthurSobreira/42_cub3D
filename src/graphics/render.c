/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/17 18:58:22 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_process(void)
{
	t_mlx	*mlx;

	mlx = init_mlx();
	mlx_loop_hook(mlx->win_ptr, render, mlx);
	mlx_image_to_window(mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_set_cursor(mlx->win_ptr, mlx->cursor);
	mlx_cursor_hook(mlx->win_ptr, my_cursor, NULL);
	mlx_key_hook(mlx->win_ptr, &my_keyhook, mlx);
	mlx_set_mouse_pos(mlx->win_ptr, WIDTH_2, HEIGHT_2);
	mlx_loop(mlx->win_ptr);
}

void	render(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	draw_background(mlx);
	draw_minimap(mlx);
	draw_direction(get_player());
	draw_player(get_player()->pos_x, \
		get_player()->pos_y, COLOR_PLAYER);
	cat();
	bresenham((t_point){(get_player()->pos_x + DIRECTION_OFFSET), \
				(get_player()->pos_y + DIRECTION_OFFSET), COLOR_PLAYER}, \
			(t_point){get_math()->rx, get_math()->ry, COLOR_PLAYER}, 10);
	cat2();
	bresenham((t_point){(get_player()->pos_x + DIRECTION_OFFSET), \
				(get_player()->pos_y + DIRECTION_OFFSET), 0x00ff00ff}, \
			(t_point){get_math()->rx, get_math()->ry, 0x00ff00ff}, 3);
}
