/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/27 14:47:54 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_process(void)
{
	t_mlx	*mlx;

	mlx = init_mlx();
	mlx_loop_hook(mlx->win_ptr, render, mlx);
	mlx_loop_hook(mlx->win_ptr, left_click, mlx);
	mlx_image_to_window(mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_set_cursor(mlx->win_ptr, mlx->cursor);
	mlx_cursor_hook(mlx->win_ptr, my_cursor, mlx);
	mlx_key_hook(mlx->win_ptr, my_keyhook, mlx);
	mlx_set_mouse_pos(mlx->win_ptr, WIDTH_2, HEIGHT_2);
	mlx_loop(mlx->win_ptr);
}

void	draw_gun(t_mlx *mlx)
{
	int	index;

	index = 0;
	mlx->gun_imgs[index]->enabled = true;
	mlx_image_to_window(mlx->win_ptr, mlx->gun_imgs[index], \
		WIDTH_2 - 250, WINDOW_HEIGHT - 500);
	if (get_core()->reload)
	{
		// if (mlx->gun_imgs[index])
		// 	mlx_delete_image(mlx->win_ptr, mlx->gun_imgs[index]);
		// if (mlx->gun_imgs[index + 1])
		// 	mlx_delete_image(mlx->win_ptr, mlx->gun_imgs[index + 1]);
		while (++index < 4)
		{
			mlx_image_to_window(mlx->win_ptr, mlx->gun_imgs[index + 1], \
					WIDTH_2 - 250, WINDOW_HEIGHT - 500);
			usleep(10000000);
		}

		// while (++index < 4)
		// {
		// 	mlx_delete_image(mlx->win_ptr, mlx->gun_imgs[index]);
		// 	mlx_image_to_window(mlx->win_ptr, mlx->gun_imgs[index + 1], \
		// 		WIDTH_2 - 250, WINDOW_HEIGHT - 500);
		// 	// sleep(1);
		// }
		
		// mlx->gun_imgs[index]->enabled = false;
		// mlx_image_to_window(mlx->win_ptr, mlx->gun_imgs[index + 1], \
		// 	WIDTH_2 - 250, WINDOW_HEIGHT - 500);
		// mlx->gun_imgs[index]->enabled = false;
		// usleep(100000);
		// mlx_delete_texture(mlx->gun_textures[index]);
		// mlx_delete_image(mlx->win_ptr, mlx->gun_imgs[index]);
	}
	get_core()->reload = FALSE;
}

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
	draw_player(player->pos_x, \
		player->pos_y, COLOR_PLAYER);
	draw_gun(mlx);
}
