/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:32:47 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/25 02:05:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_col	wall_collision(t_player	*player, float x, float y)
{
	t_map	*map;
	t_bool	collision_x;
	t_bool	collision_y;
	int		map_x;
	int		map_y;

	map = get_map();
	map_x = ((int)(x)) >> BITSHIFT;
	map_y = ((int)(y)) >> BITSHIFT;
	if (map_x >= map->max_x || map_y >= map->max_y || map_x < 0 || map_y < 0)
		return (NO_COLLISION);
	if (map->map_str[map_y][map_x] == '1')
	{
		collision_x = map->map_str[((int)player->pos_y) >> \
			BITSHIFT][map_x] == '1';
		collision_y = map->map_str[map_y][((int)player->pos_x) >> \
			BITSHIFT] == '1';
		if (collision_x && collision_y)
			return (COLLISION_XY);
		else if (collision_x)
			return (COLLISION_X);
		else if (collision_y)
			return (COLLISION_Y);
	}
	return (NO_COLLISION);
}

void	move_w(void)
{
	t_player	*player;
	t_col		collision;
	float		new_x;
	float		new_y;

	player = get_player();
	new_x = player->pos_x + player->delta_x * MOVE_SPEED;
	new_y = player->pos_y + player->delta_y * MOVE_SPEED;
	collision = wall_collision(player, new_x, new_y);
	if (collision == NO_COLLISION)
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
	else if (collision == COLLISION_X)
		player->pos_y = new_y;
	else if (collision == COLLISION_Y)
		player->pos_x = new_x;
}

void	move_a(void)
{
	t_player	*player;
	t_col		collision;
	float		new_x;
	float		new_y;

	player = get_player();
	new_x = player->pos_x + player->delta_y * MOVE_SPEED;
	new_y = player->pos_y - player->delta_x * MOVE_SPEED;
	collision = wall_collision(player, new_x, new_y);
	if (collision == NO_COLLISION)
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
	else if (collision == COLLISION_X)
		player->pos_y = new_y;
	else if (collision == COLLISION_Y)
		player->pos_x = new_x;
}

void	move_s(void)
{
	t_player	*player;
	t_col		collision;
	float		new_x;
	float		new_y;

	player = get_player();
	new_x = player->pos_x - player->delta_x * MOVE_SPEED;
	new_y = player->pos_y - player->delta_y * MOVE_SPEED;
	collision = wall_collision(player, new_x, new_y);
	if (collision == NO_COLLISION)
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
	else if (collision == COLLISION_X)
		player->pos_y = new_y;
	else if (collision == COLLISION_Y)
		player->pos_x = new_x;
}

void	move_d(void)
{
	t_player	*player;
	t_col		collision;
	float		new_x;
	float		new_y;

	player = get_player();
	new_x = player->pos_x - player->delta_y * MOVE_SPEED;
	new_y = player->pos_y + player->delta_x * MOVE_SPEED;
	collision = wall_collision(player, new_x, new_y);
	if (collision == NO_COLLISION)
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
	else if (collision == COLLISION_X)
		player->pos_y = new_y;
	else if (collision == COLLISION_Y)
		player->pos_x = new_x;
}
