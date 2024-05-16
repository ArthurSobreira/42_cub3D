/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 18:15:04 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_process(void)
{
	t_mlx	*mlx;

	mlx = init_mlx();
	mlx_loop_hook(mlx->win_ptr, render, mlx);
	mlx_image_to_window(mlx->win_ptr, mlx->img_ptr, 0, 0);
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
