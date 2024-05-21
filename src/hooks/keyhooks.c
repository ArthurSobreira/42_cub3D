/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:55:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/20 19:10:50 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player(t_mlx *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx->win_ptr, W) || \
		mlx_is_key_down(mlx->win_ptr, UP))
		player->move_w();
	if (mlx_is_key_down(mlx->win_ptr, S) || \
		mlx_is_key_down(mlx->win_ptr, DOWN))
		player->move_s();
	if (mlx_is_key_down(mlx->win_ptr, A))
		player->move_a();
	if (mlx_is_key_down(mlx->win_ptr, D))
		player->move_d();
	if (mlx_is_key_down(mlx->win_ptr, RIGHT))
		player->move_right();
	if (mlx_is_key_down(mlx->win_ptr, LEFT))
		player->move_left();
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == ESC && (keydata.action == P || \
		keydata.action == RE))
	{
		clear_all();
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(mlx->win_ptr, TAB))
		get_core()->draw_map = !get_core()->draw_map;
	if (mlx_is_key_down(mlx->win_ptr, R))
		get_core()->draw_rays = !get_core()->draw_rays;
	move_player(mlx, get_player());
}
