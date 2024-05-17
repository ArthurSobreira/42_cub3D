/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:55:12 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/17 11:52:28 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left_cursor(void)
{
	t_player	*player;

	player = get_player();
	player->angle -= 0.01;
	if (player->angle < 0)
		player->angle += TWO_PI;
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}

static void	move_right_cursor(void)
{
	t_player	*player;

	player = get_player();
	player->angle += 0.01;
	if (player->angle > TWO_PI)
		player->angle -= TWO_PI;
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}

void	my_cursor(double x, double y, void *param)
{
	(void)param;
	(void)y;
	if (x < WINDOW_WIDTH / 2)
		move_left_cursor();
	else
		move_right_cursor();
}
