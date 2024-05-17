/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:55:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/17 11:30:50 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_w(void)
{
	t_player	*player;

	player = get_player();
	if (player->pos_x + player->delta_x * MOVE_SPEED < 0 || \
		player->pos_y + player->delta_y * MOVE_SPEED < 0)
		return ;
	if (player->pos_x + player->delta_x * MOVE_SPEED >= WINDOW_WIDTH || \
		player->pos_y + player->delta_y * MOVE_SPEED >= WINDOW_HEIGHT)
		return ;
	player->pos_x += player->delta_x * MOVE_SPEED;
	player->pos_y += player->delta_y * MOVE_SPEED;
}

static void	move_s(void)
{
	t_player	*player;

	player = get_player();
	if (player->pos_x - player->delta_x * MOVE_SPEED < 0 || \
		player->pos_y - player->delta_y * MOVE_SPEED < 0)
		return ;
	if (player->pos_x - player->delta_x * MOVE_SPEED >= WINDOW_WIDTH || \
		player->pos_y - player->delta_y * MOVE_SPEED >= WINDOW_HEIGHT)
		return ;
	player->pos_x -= player->delta_x * MOVE_SPEED;
	player->pos_y -= player->delta_y * MOVE_SPEED;
}

static void	move_a(void)
{
	t_player	*player;

	player = get_player();
	if (player->pos_x + player->delta_y * MOVE_SPEED < 0 || \
		player->pos_y - player->delta_x * MOVE_SPEED < 0)
		return ;
	if (player->pos_x + player->delta_y * MOVE_SPEED >= WINDOW_WIDTH || \
		player->pos_y - player->delta_x * MOVE_SPEED >= WINDOW_HEIGHT)
		return ;
	player->pos_x += player->delta_y * MOVE_SPEED;
	player->pos_y -= player->delta_x * MOVE_SPEED;
}

static void	move_d(void)
{
	t_player	*player;

	player = get_player();
	if (player->pos_x - player->delta_y * MOVE_SPEED < 0 || \
		player->pos_y + player->delta_x * MOVE_SPEED < 0)
		return ;
	if (player->pos_x - player->delta_y * MOVE_SPEED >= WINDOW_WIDTH || \
		player->pos_y + player->delta_x * MOVE_SPEED >= WINDOW_HEIGHT)
		return ;
	player->pos_x -= player->delta_y * MOVE_SPEED;
	player->pos_y += player->delta_x * MOVE_SPEED;
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
	if (mlx_is_key_down(mlx->win_ptr, W) || \
		mlx_is_key_down(mlx->win_ptr, UP))
		move_w();
	if (mlx_is_key_down(mlx->win_ptr, S) || \
		mlx_is_key_down(mlx->win_ptr, DOWN))
		move_s();
	if (mlx_is_key_down(mlx->win_ptr, A))
		move_a();
	if (mlx_is_key_down(mlx->win_ptr, D))
		move_d();
	if (mlx_is_key_down(mlx->win_ptr, RIGHT))
		move_right();
	if (mlx_is_key_down(mlx->win_ptr, LEFT))
		move_left();
}
