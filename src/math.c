/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:50:31 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/19 23:14:53 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	horizontal(double ra)
{
	if (ra > PI)
	{
		get_math()->ray_y = (((int)get_player()->pos_y >> BITSHIFT) << BITSHIFT)
		- PRECISION;
		get_math()->ray_x = (get_player()->pos_y - get_math()->ray_y)
		* get_math()->atan + get_player()->pos_x;
		get_math()->y_offset = -MAP_CUB;
		get_math()->x_offset = -get_math()->y_offset * get_math()->atan;
	}
	if (ra < PI)
	{
		get_math()->ray_y = (((int)get_player()->pos_y >> BITSHIFT) << BITSHIFT)
		+ MAP_CUB;
		get_math()->ray_x = (get_player()->pos_y - get_math()->ray_y)
		* get_math()->atan + get_player()->pos_x;
		get_math()->y_offset = MAP_CUB;
		get_math()->x_offset = -get_math()->y_offset * get_math()->atan;
	}
	if (ra == TWO_PI || ra == PI)
	{
		get_math()->ray_x = get_player()->pos_x + TRUE;
		get_math()->ray_y = get_player()->pos_y + TRUE;
		get_math()->dof = 8;
	}
}

static void	vertical(double ra)
{
	if (ra > PI_OVER_TWO && ra < THREE_PI_OVER_TWO)
	{
		get_math()->ray_x = (((int)get_player()->pos_x >> BITSHIFT) << BITSHIFT)
		- PRECISION;
		get_math()->ray_y = (get_player()->pos_x - get_math()->ray_x)
		* get_math()->ntan + get_player()->pos_y;
		get_math()->x_offset = -MAP_CUB;
		get_math()->y_offset = -get_math()->x_offset * get_math()->ntan;
	}
	if (ra < PI_OVER_TWO || ra > THREE_PI_OVER_TWO)
	{
		get_math()->ray_x = (((int)get_player()->pos_x >> BITSHIFT) << BITSHIFT)
		+ MAP_CUB;
		get_math()->ray_y = (get_player()->pos_x - get_math()->ray_x)
		* get_math()->ntan + get_player()->pos_y;
		get_math()->x_offset = MAP_CUB;
		get_math()->y_offset = -get_math()->x_offset * get_math()->ntan;
	}
	if (ra == TWO_PI || ra == PI)
	{
		get_math()->ray_x = get_player()->pos_x + TRUE;
		get_math()->ray_y = get_player()->pos_y + TRUE;
		get_math()->dof = 8;
	}
}

static double	pythagorean(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx + ax) + (by - ay) * (by + ay)));
}

static void	check_collision(t_axis axis)
{
	t_math		*math;
	t_player	*player;

	math = get_math();
	player = get_player();
	math->dof = 8;
	if (axis == HORIZONTAL)
	{
		math->horz_x = math->ray_x;
		math->horz_y = math->ray_y;
		math->horz_dist = pythagorean(player->pos_x, player->pos_y, \
			math->horz_x, math->horz_y);
	}
	else if (axis == VERTICAL)
	{
		math->vert_x = math->ray_x;
		math->vert_y = math->ray_y;
		math->vert_dist = pythagorean(player->pos_x, player->pos_y, \
			math->vert_x, math->vert_y);
	}
}

static void	trace_ray(t_math *math, t_map *map, t_axis axis)
{
	int			map_x;
	int			map_y;
	int			map_p;

	while (math->dof < 8)
	{
		map_x = (int)(math->ray_x) >> BITSHIFT;
		map_y = (int)(math->ray_y) >> BITSHIFT;
		map_p = map_y * map->max_x + map_x;
		if (map_x > map->max_x || \
			map_y > map->max_y || \
			map_x < 0 || map_y < 0)
			break ;
		if (map_p < map->max_x * map->max_y && \
			map->map_str[map_y][map_x] == '1')
			check_collision(axis);
		else
		{
			math->ray_x += math->x_offset;
			math->ray_y += math->y_offset;
			math->dof += 1;
		}
	}
}

void	cat(void)
{
	t_math	*math;
	t_map	*map;

	math = get_math();
	map = get_map();
	math->dof = 0;
	math->ray_ang = get_player()->angle;
	// if (math->ray_ang < 0)
	// 	math->ray_ang += TWO_PI;
	// if (math->ray_ang > TWO_PI)
	// 	math->ray_ang -= TWO_PI;
	math->atan = -1 / tan(get_player()->angle);
	math->horz_dist = INT_MAX;
	math->horz_x = get_player()->pos_x;
	math->horz_y = get_player()->pos_y;
	// init_math(get_player());
	horizontal(math->ray_ang);
	trace_ray(math, map, HORIZONTAL);
}


void	cat2(void)
{
	t_math	*math;
	t_map	*map;

	math = get_math();
	map = get_map();
	math->dof = 0;
	math->ray_ang = get_player()->angle;
	// if (math->ray_ang < 0)
	// 	math->ray_ang += 2 * PI;
	// if (math->ray_ang > 2 * PI)
	// 	math->ray_ang -= 2 * PI;
	math->ntan = -tan(get_player()->angle);
	math->vert_dist = INT_MAX;
	math->vert_x = get_player()->pos_x;
	math->vert_y = get_player()->pos_y;
	// init_math(get_player());
	vertical(math->ray_ang);
	trace_ray(math, map, VERTICAL);
}
