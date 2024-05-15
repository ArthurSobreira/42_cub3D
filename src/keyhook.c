/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:55:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/15 19:31:25 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left(void)
{
	t_player	*player;

	player = get_player();
	player->degree -= 0.1;
	if (player->degree < 0)
		player->degree += TWO_PI;
	player->dx = cos(player->degree);
	player->dy = sin(player->degree);
}

static void	move_right(void)
{
	t_player	*player;

	player = get_player();
	player->degree += 0.1;
	if (player->degree > TWO_PI)
		player->degree -= TWO_PI;
	player->dx = cos(player->degree);
	player->dy = sin(player->degree);
}

static void	move_w(void)
{
	t_player	*player;

	player = get_player();
	if (player->x + player->dx * 4 < 0 || player->y + player->dy * 4 < 0)
		return ;
	if (player->x + player->dx * 4 >= WINDOW_WIDTH || player->y + player->dy
		* 4 >= WINDOW_HEIGHT)
		return ;
	player->x += player->dx * 4;
	player->y += player->dy * 4;
}

static void	move_s(void)
{
	t_player	*player;

	player = get_player();
	if (player->x - player->dx * 4 < 0 || player->y - player->dy * 4 < 0)
		return ;
	if (player->x - player->dx * 4 >= WINDOW_WIDTH || player->y - player->dy
		* 4 >= WINDOW_HEIGHT)
		return ;
	player->x -= player->dx * 4;
	player->y -= player->dy * 4;
}

void move_a(void)
{
	t_player	*player;

	player = get_player();
	if (player->x - player->dy * 4 < 0 || player->y + player->dx * 4 < 0)
		return ;
	if (player->x - player->dy * 4 >= WINDOW_WIDTH || player->y + player->dx
		* 4 >= WINDOW_HEIGHT)
		return ;
	player->x += player->dy * 4;
	player->y -= player->dx * 4;
}

void move_d(void)
{
	t_player	*player;

	player = get_player();
	if (player->x + player->dy * 4 < 0 || player->y - player->dx * 4 < 0)
		return ;
	if (player->x + player->dy * 4 >= WINDOW_WIDTH || player->y - player->dx
		* 4 >= WINDOW_HEIGHT)
		return ;
	player->x -= player->dy * 4;
	player->y += player->dx * 4;
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
		move_w(); //-4
	if (mlx_is_key_down(mlx->win_ptr, S) || mlx_is_key_down(mlx->win_ptr, DOWN))
		move_s();
	if (mlx_is_key_down(mlx->win_ptr, RIGHT))
		move_right();
	if (mlx_is_key_down(mlx->win_ptr, LEFT))
		move_left(); //-4
	if (mlx_is_key_down(mlx->win_ptr, A))
		move_a();
	if (mlx_is_key_down(mlx->win_ptr, D))
		move_d();
}
