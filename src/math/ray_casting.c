/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:50:31 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/21 03:10:17 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_ray_angle_collision(t_math *math, t_player *player)
{
	if (math->ray_ang == 0 || math->ray_ang == PI)
	{
		math->ray_x = player->pos_x;
		math->ray_y = player->pos_y;
		math->collision = TRUE;
	}
}

void	cat_horizontal_rays(t_math *math, t_map *map, t_player *player)
{
	init_axis(math, player, HORIZONTAL);
	if (math->ray_ang > PI)
	{
		math->ray_y = (((int)player->pos_y >> BITSHIFT) << BITSHIFT)
			- PRECISION;
		math->ray_x = (player->pos_y - math->ray_y)
			* math->atan + player->pos_x;
		math->y_offset = -MAP_CUB;
		math->x_offset = -math->y_offset * math->atan;
	}
	if (math->ray_ang < PI)
	{
		math->ray_y = (((int)player->pos_y >> BITSHIFT) << BITSHIFT)
			+ MAP_CUB;
		math->ray_x = (player->pos_y - math->ray_y)
			* math->atan + player->pos_x;
		math->y_offset = MAP_CUB;
		math->x_offset = -math->y_offset * math->atan;
	}
	handle_ray_angle_collision(math, player);
	trace_ray(math, map, HORIZONTAL);
}

void	cat_vertical_rays(t_math *math, t_map *map, t_player *player)
{
	init_axis(math, player, VERTICAL);
	if (math->ray_ang > PI_OVER_TWO && math->ray_ang < THREE_PI_OVER_TWO)
	{
		math->ray_x = (((int)player->pos_x >> BITSHIFT) << BITSHIFT)
			- PRECISION;
		math->ray_y = (player->pos_x - math->ray_x)
			* math->ntan + player->pos_y;
		math->x_offset = -MAP_CUB;
		math->y_offset = -math->x_offset * math->ntan;
	}
	if (math->ray_ang < PI_OVER_TWO || math->ray_ang > THREE_PI_OVER_TWO)
	{
		math->ray_x = (((int)player->pos_x >> BITSHIFT) << BITSHIFT)
			+ MAP_CUB;
		math->ray_y = (player->pos_x - math->ray_x)
			* math->ntan + player->pos_y;
		math->x_offset = MAP_CUB;
		math->y_offset = -math->x_offset * math->ntan;
	}
	handle_ray_angle_collision(math, player);
	trace_ray(math, map, VERTICAL);
}

void	casting_rays(t_math *math, t_map *map, t_player *player)
{
	int		angle;

	if (!get_core()->draw_map)
		return ;
	angle = 0;
	math->ray_ang = player->angle - ANG_1 * 30;
	normalize_angle(&math->ray_ang);
	while (angle++ < PLAYER_FOV)
	{
		cat_horizontal_rays(math, map, player);
		cat_vertical_rays(math, map, player);
		if (math->vert_dist < math->horz_dist)
		{
			math->ray_x = math->vert_x;
			math->ray_y = math->vert_y;
		}
		else if (math->horz_dist < math->vert_dist)
		{
			math->ray_x = math->horz_x;
			math->ray_y = math->horz_y;
		}
		draw_rays(math, player);
		math->ray_ang += ANG_1;
		normalize_angle(&math->ray_ang);
	}
}
