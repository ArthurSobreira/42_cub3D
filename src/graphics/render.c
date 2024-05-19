/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/19 20:08:07 by arsobrei         ###   ########.fr       */
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
	cat();
	cat2();
	if (get_math()->vert_dist < get_math()->horz_dist)
	{
		printf("VERTICAL\n");
		get_math()->ray_x = get_math()->vert_x;
		get_math()->ray_y = get_math()->vert_y;
	}
	if (get_math()->horz_dist < get_math()->vert_dist)
	{
		printf("HORIZONTAL\n");
		get_math()->ray_x = get_math()->horz_x;
		get_math()->ray_y = get_math()->horz_y;
	}
	bresenham((t_point){(get_player()->pos_x + DIRECTION_OFFSET), \
				(get_player()->pos_y + DIRECTION_OFFSET), COLOR_PLAYER}, \
			(t_point){get_math()->ray_x, get_math()->ray_y, COLOR_PLAYER}, 2);
	draw_direction(get_player());
	draw_player(get_player()->pos_x, \
		get_player()->pos_y, COLOR_PLAYER);
	// bresenham((t_point){(get_player()->pos_x + DIRECTION_OFFSET), 
	// 			(get_player()->pos_y + DIRECTION_OFFSET), 0x00ff00ff}, 
	// 		(t_point){get_math()->ray_x, get_math()->ray_y, 0x00ff00ff}, 3);
}
