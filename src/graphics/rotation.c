/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:54:54 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 18:59:21 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(void)
{
	t_player	*player;

	player = get_player();
	player->angle -= 0.1;
	if (player->angle < 0)
		player->angle += TWO_PI;
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}

void	move_right(void)
{
	t_player	*player;

	player = get_player();
	player->angle += 0.1;
	if (player->angle > TWO_PI)
		player->angle -= TWO_PI;
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}
 