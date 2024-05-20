/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:50:31 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/20 15:27:46 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	horizontal(double ra)
{
	printf("ray_ang: %lf\n", ra);
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
	if (ra == 0 || ra == PI)
	{
		get_math()->ray_x = get_player()->pos_x;
		get_math()->ray_y = get_player()->pos_y;
		get_math()->collision = TRUE;
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
	if (ra == 0 || ra == PI)
	{
		get_math()->ray_x = get_player()->pos_x;
		get_math()->ray_y = get_player()->pos_y;
		get_math()->collision = TRUE;
	}
}

void	cat(double i)
{
	t_math	*math;
	t_map	*map;

	(void)i;
	math = get_math();
	map = get_map();
	math->collision = FALSE;
	printf("angle: %lf\n", get_player()->angle);
	math->ray_ang = get_player()->angle;
	printf("ray_ang: %lf\n", math->ray_ang);
	if (get_math()->ray_ang < 0)
		get_math()->ray_ang += TWO_PI;
	if (get_math()->ray_ang > TWO_PI)
		get_math()->ray_ang -= TWO_PI;
	math->atan = -1 / tan(get_player()->angle);
	math->horz_dist = DBL_MAX;
	math->horz_x = get_player()->pos_x;
	math->horz_y = get_player()->pos_y;
	// init_math(get_player());
	horizontal(math->ray_ang);
	trace_ray(math, map, HORIZONTAL);
}


void	cat2(double i)
{
	t_math	*math;
	t_map	*map;

	(void)i;
	math = get_math();
	map = get_map();
	math->collision = FALSE;
	math->ray_ang = get_player()->angle;
	if (get_math()->ray_ang < 0)
		get_math()->ray_ang += TWO_PI;
	if (get_math()->ray_ang > TWO_PI)
		get_math()->ray_ang -= TWO_PI;
	math->ntan = -tan(get_player()->angle);
	math->vert_dist = DBL_MAX;
	math->vert_x = get_player()->pos_x;
	math->vert_y = get_player()->pos_y;
	// init_math(get_player());
	vertical(math->ray_ang);
	trace_ray(math, map, VERTICAL);
}
