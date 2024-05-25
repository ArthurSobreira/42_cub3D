/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:32:47 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/23 12:32:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	wall_collision(float x, float y)
{
	int		map_x;
	int		map_y;
	int		map_p;
	t_map	*map;

	map = get_map();
	map_x = ((int)(x)) >> BITSHIFT;
	map_y = (int)(y) >> BITSHIFT;
	map_p = map_y * map->max_x + map_x;
	if (map_x >= map->max_x || map_y >= map->max_y || map_x < 0 || map_y < 0)
		return (FALSE);
	if (map_p < map->max_x * map->max_y && map->map_str[map_y][map_x] == '1')
		return (TRUE);
	return (FALSE);
}

void	move_w(void)
{
	t_player	*player;
	float		new_x;
	float		new_y;

	player = get_player();
	new_x = player->pos_x + player->delta_x * MOVE_SPEED;
	new_y = player->pos_y + player->delta_y * MOVE_SPEED;
	if (new_x < 0 || new_y < 0 || new_x >= WINDOW_WIDTH
		|| new_y >= WINDOW_HEIGHT)
		return ;
	if (is_colliding(new_x, new_y))
		return ;
	player->pos_x = new_x;
	player->pos_y = new_y;
}

void	move_a(void)
{
	t_player	*player;
	float		new_x;
	float		new_y;

	player = get_player();
	new_x = player->pos_x + player->delta_y * MOVE_SPEED;
	new_y = player->pos_y - player->delta_x * MOVE_SPEED;
	if (new_x < 0 || new_y < 0 || new_x >= WINDOW_WIDTH
		|| new_y >= WINDOW_HEIGHT)
		return ;
	if (is_colliding(new_x, new_y))
		return ;
	player->pos_x = new_x;
	player->pos_y = new_y;
}

void	move_s(void)
{
	t_player	*player;
	float		new_x;
	float		new_y;

	player = get_player();
	new_x = player->pos_x - player->delta_x * MOVE_SPEED;
	new_y = player->pos_y - player->delta_y * MOVE_SPEED;
	if (new_x < 0 || new_y < 0 || new_x >= WINDOW_WIDTH
		|| new_y >= WINDOW_HEIGHT)
		return ;
	if (is_colliding(new_x, new_y))
		return ;
	player->pos_x = new_x;
	player->pos_y = new_y;
}

void	move_d(void)
{
	t_player	*player;
	float		new_x;
	float		new_y;

	player = get_player();
	new_x = player->pos_x - player->delta_y * MOVE_SPEED;
	new_y = player->pos_y + player->delta_x * MOVE_SPEED;
	if (new_x < 0 || new_y < 0 || new_x >= WINDOW_WIDTH
		|| new_y >= WINDOW_HEIGHT)
		return ;
	if (is_colliding(new_x, new_y))
		return ;
	player->pos_x = new_x;
	player->pos_y = new_y;
}
