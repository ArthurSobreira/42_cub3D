/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:32:47 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/20 16:35:42 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(void)
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

void	move_a(void)
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

void	move_s(void)
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

void	move_d(void)
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
