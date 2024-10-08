/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:14:58 by arsobrei          #+#    #+#             */
/*   Updated: 2024/10/01 17:26:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	trace_ray(t_math *math, t_map *map, t_axis axis)
{
	int		map_x;
	int		map_y;
	int		map_p;

	while (!math->collision)
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
			check_wall_collision(axis);
		else
		{
			math->ray_x += math->offset_x;
			math->ray_y += math->offset_y;
		}
	}
}

void	check_wall_collision(t_axis axis)
{
	t_math		*math;
	t_player	*player;

	math = get_math();
	player = get_player();
	math->collision = TRUE;
	if (axis == HORIZONTAL)
	{
		math->horz_x = math->ray_x;
		math->horz_y = math->ray_y;
		math->horz_dist = hypot(math->horz_x - player->pos_x, \
			math->horz_y - player->pos_y);
	}
	else if (axis == VERTICAL)
	{
		math->vert_x = math->ray_x;
		math->vert_y = math->ray_y;
		math->vert_dist = hypot(math->vert_x - player->pos_x, \
			math->vert_y - player->pos_y);
	}
}

void	update_distance(double horizontal_dist, double vertical_dist)
{
	t_math		*math;
	double		fisheye_fix;

	math = get_math();
	if (vertical_dist < horizontal_dist)
	{
		math->dist = vertical_dist;
		math->ray_x = math->vert_x;
		math->ray_y = math->vert_y;
	}
	else if (horizontal_dist < vertical_dist)
	{
		math->dist = horizontal_dist;
		math->ray_x = math->horz_x;
		math->ray_y = math->horz_y;
	}
	fisheye_fix = get_player()->angle - math->ray_ang;
	normalize_angle(&fisheye_fix);
	math->dist *= cos(fisheye_fix);
}

void	draw_rays(t_math *math, t_player *player)
{
	t_point	initial_point;
	t_point	final_point;
	short	thickness;

	if ((!get_core()->draw_map) || (!get_core()->draw_rays))
		return ;
	get_core()->wall_flag = FALSE;
	thickness = 1;
	initial_point.coord_x = player->pos_x + DIRECTION_OFFSET;
	initial_point.coord_y = player->pos_y + DIRECTION_OFFSET;
	final_point.coord_x = math->ray_x;
	final_point.coord_y = math->ray_y;
	initial_point.color = COLOR_RAY;
	final_point.color = COLOR_RAY;
	bresenham(initial_point, final_point, thickness);
}

void	normalize_angle(double *angle)
{
	if (*angle < 0)
		*angle += TWO_PI;
	if (*angle > TWO_PI)
		*angle -= TWO_PI;
}
