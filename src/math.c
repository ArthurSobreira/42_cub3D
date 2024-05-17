/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:50:31 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/17 18:46:34 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	vertical(double ra);

static void	horizontal(double ra)
{
	get_math()->atan = -1 / tan(ra);
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
	get_math()->ntan = -tan(ra);
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

void	cat(void)
{
	int	mx;
	int	my;
	int	mp;

	get_math()->dof = 0;
	horizontal(get_player()->angle);
	while (get_math()->dof < 8)
	{
		mx = (int)(get_math()->rx) >> BITSHIFT;
		my = (int)(get_math()->ry) >> BITSHIFT;
		mp = my * get_map()->max_x + mx;
		if (mx > get_map()->max_x || my > get_map()->max_y || mx < 0 || my < 0)
			break ;
		if (mp < get_map()->max_x * get_map()->max_y
			&& get_map()->map_str[my][mx] == '1')
			get_math()->dof = 8;
		else
		{
			get_math()->rx += get_math()->xo;
			get_math()->ry += get_math()->yo;
			get_math()->dof += 1;
		}
	}
}


void	cat2(void)
{
	int	mx;
	int	my;
	int	mp;

	get_math()->dof = 0;
	vertical(get_player()->angle);
	while (get_math()->dof < 8)
	{
		mx = (int)(get_math()->rx) >> BITSHIFT;
		my = (int)(get_math()->ry) >> BITSHIFT;
		mp = my * get_map()->max_x + mx;
		if (mx > get_map()->max_x || my > get_map()->max_y || mx < 0 || my < 0)
			break ;
		if (mp < get_map()->max_x * get_map()->max_y
			&& get_map()->map_str[my][mx] == '1')
			get_math()->dof = 8;
		else
		{
			get_math()->rx += get_math()->xo;
			get_math()->ry += get_math()->yo;
			get_math()->dof += 1;
		}
	}
}
