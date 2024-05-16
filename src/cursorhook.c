/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:55:12 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 18:28:53 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left_cursor(void)
{
	t_player	*player;

	player = get_player();
	player->degree -= 0.01;
	if (player->degree < 0)
		player->degree += TWO_PI;
	player->dx = cos(player->degree);
	player->dy = sin(player->degree);
}

static void	move_right_cursor(void)
{
	t_player	*player;

	player = get_player();
	player->degree += 0.01;
	if (player->degree > TWO_PI)
		player->degree -= TWO_PI;
	player->dx = cos(player->degree);
	player->dy = sin(player->degree);
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
