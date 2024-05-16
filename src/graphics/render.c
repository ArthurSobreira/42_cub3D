/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 19:14:02 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_cursor(void)
{
	mlx_texture_t		*texture;
	mlx_win_cursor_t	*cursor;
	t_mlx				*mlx;

	mlx = get_mlx();
	texture = mlx_load_png(CURSOR_PATH);
	get_mlx()->cursor = texture;
	cursor = mlx_create_cursor(texture);
	mlx_set_cursor(mlx->win_ptr, cursor);
	mlx_cursor_hook(mlx->win_ptr, my_cursor, NULL);
}

void	mlx_process(void)
{
	t_mlx	*mlx;

	mlx = init_mlx();
	mlx_loop_hook(mlx->win_ptr, render, mlx);
	mlx_image_to_window(mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_cursor();
	mlx_key_hook(mlx->win_ptr, &my_keyhook, mlx);
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
}
