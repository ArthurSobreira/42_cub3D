/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:55:12 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/22 21:31:49 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left_cursor(void)
{
	t_player	*player;

	player = get_player();
	player->angle -= ROTATE_SPEED;
	if (player->angle < 0)
		player->angle += TWO_PI;
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}

static void	move_right_cursor(void)
{
	t_player	*player;

	player = get_player();
	player->angle += ROTATE_SPEED;
	if (player->angle > TWO_PI)
		player->angle -= TWO_PI;
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}

void	my_cursor(double x, double y, void *param)
{
	static double	last_x;
	int				sens;

	(void)param;
	(void)y;
	sens = 2;
	if (last_x < x)
	{
		while (sens--)
			move_right_cursor();
		last_x = x;
	}
	else if (last_x > x)
	{
		while (sens--)
			move_left_cursor();
		last_x = x;
	}
}
