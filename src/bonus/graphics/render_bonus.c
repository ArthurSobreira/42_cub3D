/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/10/01 17:25:51 by arsobrei         ###   ########.fr       */
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
	mlx->img_ptr->instances[0].z = -1;
	mlx_set_cursor(mlx->win_ptr, mlx->cursor);
	mlx_cursor_hook(mlx->win_ptr, my_cursor, mlx);
	mlx_key_hook(mlx->win_ptr, my_keyhook, mlx);
	mlx_set_mouse_pos(mlx->win_ptr, WIDTH_2, HEIGHT_2);
	mlx_loop(mlx->win_ptr);
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
	mlx->img_ptr->instances[0].z = -1;
	draw_background(mlx);
	draw_minimap(mlx);
	casting_rays(math, map, player);
	draw_direction(player);
	draw_player(player->pos_x, player->pos_y, COLOR_PLAYER);
	draw_gun(mlx);
}

void	draw_gun(t_mlx *mlx)
{
	static int	index = 0;

	if (get_core()->reload)
	{
		if (index < 50)
		{
			mlx->gun_imgs[index / 10]->instances[0].enabled = FALSE;
			mlx->gun_imgs[index / 10 + 1]->instances[0].enabled = TRUE;
			++index;
		}
		else
		{
			mlx->gun_imgs[0]->instances[0].enabled = TRUE;
			mlx->gun_imgs[4]->instances[0].enabled = FALSE;
			get_core()->reload = FALSE;
			index = 0;
		}
	}
}
