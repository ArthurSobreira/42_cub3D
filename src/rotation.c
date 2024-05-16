/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:54:54 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 10:59:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(void)
{
	t_player	*player;

	player = get_player();
	player->degree -= 0.1;
	if (player->degree < 0)
		player->degree += TWO_PI;
	player->dx = cos(player->degree);
	player->dy = sin(player->degree);
}

void	move_right(void)
{
	t_player	*player;

	player = get_player();
	player->degree += 0.1;
	if (player->degree > TWO_PI)
		player->degree -= TWO_PI;
	player->dx = cos(player->degree);
	player->dy = sin(player->degree);
}
