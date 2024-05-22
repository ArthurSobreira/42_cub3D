/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:32:47 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/22 19:33:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	wall_collision(float x, float y)
{
	int	map_x;
	int	map_y;
	int	map_p;

	map_x = ((int)(x)) >> BITSHIFT;
	map_y = (int)(y) >> BITSHIFT;
	map_p = map_y * get_map()->max_x + map_x;
	if (map_x > get_map()->max_x || \
		map_y > get_map()->max_y || \
		map_x < 0 || map_y < 0)
		return (FALSE);
	if (map_p < get_map()->max_x * get_map()->max_y && \
		get_map()->map_str[map_y][map_x] == '1')
		return (TRUE);
	return (FALSE);
}

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
	if (wall_collision(player->pos_x + player->delta_x * MOVE_SPEED, \
		player->pos_y + player->delta_y * MOVE_SPEED - 3.5))
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
	if (wall_collision(player->pos_x + player->delta_y * MOVE_SPEED - 2.5, \
		player->pos_y - player->delta_x * MOVE_SPEED))
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
	if (wall_collision(player->pos_x - player->delta_x * MOVE_SPEED + 3.5, \
		player->pos_y - player->delta_y * MOVE_SPEED + 3.5))
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
	if (wall_collision(player->pos_x - player->delta_y * MOVE_SPEED + 3.5, \
		player->pos_y + player->delta_x * MOVE_SPEED))
		return ;
	player->pos_x -= player->delta_y * MOVE_SPEED;
	player->pos_y += player->delta_x * MOVE_SPEED;
}
