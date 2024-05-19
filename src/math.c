/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:50:31 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/19 17:05:22 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	horizontal(double ra)
{
	// get_math()->atan = -1 / tan(ra);
	if (ra > PI)
	{
		get_math()->ry = (((int)get_player()->pos_y >> BITSHIFT) << BITSHIFT)
		- PRECISION;
		get_math()->rx = (get_player()->pos_y - get_math()->ry)
		* get_math()->atan + get_player()->pos_x;
		get_math()->yo = -MAP_CUB;
		get_math()->xo = -get_math()->yo * get_math()->atan;
	}
	if (ra < PI)
	{
		get_math()->ry = (((int)get_player()->pos_y >> BITSHIFT) << BITSHIFT)
		+ MAP_CUB;
		get_math()->rx = (get_player()->pos_y - get_math()->ry)
		* get_math()->atan + get_player()->pos_x;
		get_math()->yo = MAP_CUB;
		get_math()->xo = -get_math()->yo * get_math()->atan;
	}
	if (ra == TWO_PI || ra == PI)
	{
		get_math()->rx = get_player()->pos_x + TRUE;
		get_math()->ry = get_player()->pos_y + TRUE;
		get_math()->dof = 8;
	}
}

static void	vertical(double ra)
{
	// t_math	*math;

	// math = get_math();
	// math->ntan = -tan(ra);
	if (ra > PI_OVER_TWO && ra < THREE_PI_OVER_TWO)
	{
		get_math()->rx = (((int)get_player()->pos_x >> BITSHIFT) << BITSHIFT)
		- PRECISION;
		get_math()->ry = (get_player()->pos_x - get_math()->rx)
		* get_math()->ntan + get_player()->pos_y;
		get_math()->xo = -MAP_CUB;
		get_math()->yo = -get_math()->xo * get_math()->ntan;
	}
	if (ra < PI_OVER_TWO || ra > THREE_PI_OVER_TWO)
	{
		get_math()->rx = (((int)get_player()->pos_x >> BITSHIFT) << BITSHIFT)
		+ MAP_CUB;
		get_math()->ry = (get_player()->pos_x - get_math()->rx)
		* get_math()->ntan + get_player()->pos_y;
		get_math()->xo = MAP_CUB;
		get_math()->yo = -get_math()->xo * get_math()->ntan;
	}
	if (ra == TWO_PI || ra == PI)
	{
		get_math()->rx = get_player()->pos_x + TRUE;
		get_math()->ry = get_player()->pos_y + TRUE;
		get_math()->dof = 8;
	}
}

static void	trace_ray(t_math *math)
{
	t_map	*map;
	int		map_x;
	int		map_y;
	int		map_p;

	map = get_map();
	while (math->dof < 8)
	{
		map_x = (int)(math->rx) >> BITSHIFT;
		map_y = (int)(math->ry) >> BITSHIFT;
		map_p = map_y * map->max_x + map_x;
		if (map_x > map->max_x || \
			map_y > map->max_y|| \
			map_x < 0 || map_y < 0)
			break ;
		if (map_p < map->max_x * map->max_y && \
			map->map_str[map_y][map_x] == '1')
			math->dof = 8;
		else
		{
			math->rx += math->xo;
			math->ry += math->yo;
			math->dof += 1;
		}
	}
}

void	cat(void)
{
	t_math	*math;

	math = get_math();
	init_math(get_player()->angle);
	horizontal(get_player()->angle);
	trace_ray(math);
}


void	cat2(void)
{
	t_math	*math;

	math = get_math();
	init_math(get_player()->angle);
	vertical(get_player()->angle);
	trace_ray(math);
}
