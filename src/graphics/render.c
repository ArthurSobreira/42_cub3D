/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/25 05:23:46 by arsobrei         ###   ########.fr       */
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
	mlx_cursor_hook(mlx->win_ptr, my_cursor, mlx);
	mlx_key_hook(mlx->win_ptr, &my_keyhook, mlx);
	mlx_set_mouse_pos(mlx->win_ptr, WIDTH_2, HEIGHT_2);
	mlx_loop(mlx->win_ptr);
}

// void	draw_gun(t_mlx *mlx)
// {
// 	int	index;

// 	index = 0;
// 	mlx->gun_img[0]->enabled = true;
// 	mlx_image_to_window(mlx->win_ptr, mlx->gun_img[0], WIDTH_2, \
// 		WINDOW_HEIGHT - mlx->gun_texture[0]->height);
// 	// while (index < 5)
// 	// {
// 	// 	if (mlx->gun_img[index]->enabled)
// 	// 		mlx_image_to_window(mlx->win_ptr, mlx->gun_img[index], WIDTH_2, \
// 	// 			WINDOW_HEIGHT - mlx->gun_texture[0]->height);
// 	// 	index++;
// 	// }
// }

void	render(void *param)
{
	t_math		*math;
	t_map		*map;
	t_player	*player;
	t_mlx		*mlx;

	math = get_math();
	map = get_map();
	player = get_player();
	mlx = (t_mlx *)param;
	draw_background(mlx);
	draw_minimap(mlx);
	casting_rays(math, map, player);
	draw_direction(player);
	// draw_gun(mlx);
	draw_player(player->pos_x, \
		player->pos_y, COLOR_PLAYER);
}
