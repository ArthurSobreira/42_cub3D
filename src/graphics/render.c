/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/20 19:14:10 by arsobrei         ###   ########.fr       */
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

void	draw_rays(t_math *math, t_player *player)
{
	if (!get_core()->draw_map)
		return ;
	for (int i = 0; i < 1; i++)
	{
		cat(i * ANG_1);
		cat2(i * ANG_1);
		if (math->vert_dist < math->horz_dist)
		{
			math->ray_x = math->vert_x;
			math->ray_y = math->vert_y;
		}
		else if (math->horz_dist < math->vert_dist)
		{
			math->ray_x = math->horz_x;
			math->ray_y = math->horz_y;
		}
		if (get_core()->draw_rays)
			bresenham((t_point){(player->pos_x + DIRECTION_OFFSET), \
						(player->pos_y + DIRECTION_OFFSET), COLOR_PLAYER}, \
					(t_point){math->ray_x, math->ray_y, COLOR_PLAYER}, 1);
	}
}

void	render(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	draw_background(mlx);
	draw_minimap(mlx);
	draw_rays(get_math(), get_player());
	draw_direction(get_player());
	draw_player(get_player()->pos_x, \
		get_player()->pos_y, COLOR_PLAYER);
}
