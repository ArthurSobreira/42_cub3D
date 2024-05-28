/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/28 13:36:38 by arsobrei         ###   ########.fr       */
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
	casting_rays(math, map, player);
}

void	draw_background(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				plot_pixel(mlx, x, y, mlx->ceil_color);
			else
				plot_pixel(mlx, x, y, mlx->floor_color);
			++x;
		}
		++y;
	}
}
