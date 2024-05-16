/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:55:12 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 19:02:18 by phenriq2         ###   ########.fr       */
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
	printf("x: %f\n", x);
	if (x < WINDOW_WIDTH / 2)
		move_left_cursor();
	else
		move_right_cursor();
}
