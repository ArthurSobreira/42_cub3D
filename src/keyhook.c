/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:55:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 11:43:55 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_w(void)
{
	t_player	*player;

	player = get_player();
	if (player->x + player->dx * MOVE_SPEED < 0 || player->y + player->dy
		* MOVE_SPEED < 0)
		return ;
	if (player->x + player->dx * MOVE_SPEED >= WINDOW_WIDTH || player->y
		+ player->dy * MOVE_SPEED >= WINDOW_HEIGHT)
		return ;
	player->x += player->dx * MOVE_SPEED;
	player->y += player->dy * MOVE_SPEED;
}

static void	move_s(void)
{
	t_player	*player;

	player = get_player();
	if (player->x - player->dx * MOVE_SPEED < 0 || player->y - player->dy
		* MOVE_SPEED < 0)
		return ;
	if (player->x - player->dx * MOVE_SPEED >= WINDOW_WIDTH || player->y
		- player->dy * MOVE_SPEED >= WINDOW_HEIGHT)
		return ;
	player->x -= player->dx * MOVE_SPEED;
	player->y -= player->dy * MOVE_SPEED;
}

void	move_a(void)
{
	t_player	*player;

	player = get_player();
	if (player->x + player->dy * MOVE_SPEED < 0 || player->y - player->dx
		* MOVE_SPEED < 0)
		return ;
	if (player->x + player->dy * MOVE_SPEED >= WINDOW_WIDTH || player->y
		- player->dx * MOVE_SPEED >= WINDOW_HEIGHT)
		return ;
	player->x += player->dy * MOVE_SPEED;
	player->y -= player->dx * MOVE_SPEED;
}

void	move_d(void)
{
	t_player	*player;

	player = get_player();
	if (player->x - player->dy * MOVE_SPEED < 0 || player->y + player->dx
		* MOVE_SPEED < 0)
		return ;
	if (player->x - player->dy * MOVE_SPEED >= WINDOW_WIDTH || player->y
		+ player->dx * MOVE_SPEED >= WINDOW_HEIGHT)
		return ;
	player->x -= player->dy * MOVE_SPEED;
	player->y += player->dx * MOVE_SPEED;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == ESC && (keydata.action == P || keydata.action == RE))
	{
		clear_all();
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(mlx->win_ptr, W) || mlx_is_key_down(mlx->win_ptr, UP))
		move_w();
	if (mlx_is_key_down(mlx->win_ptr, S) || mlx_is_key_down(mlx->win_ptr, DOWN))
		move_s();
	if (mlx_is_key_down(mlx->win_ptr, RIGHT))
		move_right();
	if (mlx_is_key_down(mlx->win_ptr, LEFT))
		move_left();
	if (mlx_is_key_down(mlx->win_ptr, A))
		move_a();
	if (mlx_is_key_down(mlx->win_ptr, D))
		move_d();
}
