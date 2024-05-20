/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:54:54 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/20 14:50:37 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(void)
{
	t_player	*player;

	player = get_player();
	player->angle -= 0.05;
	if (player->angle < 0)
		player->angle += TWO_PI;
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}

void	move_right(void)
{
	t_player	*player;

	player = get_player();
	player->angle += 0.05;
	if (player->angle > TWO_PI)
		player->angle -= TWO_PI;
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}
