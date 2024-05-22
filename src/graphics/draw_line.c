/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:28:08 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/21 07:06:33 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	plot_pixel(t_point point)
{
	if (get_core()->draw_map)
	{
		if (!is_map_pixel((t_point){point.coord_x, point.coord_y, 0}))
			mlx_put_pixel(get_mlx()->img_ptr, point.coord_x,
				point.coord_y, point.color);
	}
	else
		mlx_put_pixel(get_mlx()->img_ptr, point.coord_x,
			point.coord_y, point.color);
}

void	plot_thick_pixel(t_point point, int thickness)
{
	short	i;
	short	j;

	i = -thickness / 2;
	while (i <= thickness / 2)
	{
		j = -thickness / 2;
		while (j <= thickness / 2)
		{
			if ((point.coord_x + i >= 0) && (point.coord_y + j >= 0) && \
				(point.coord_x + i < WINDOW_WIDTH) && \
				(point.coord_y + j < WINDOW_HEIGHT))
				plot_pixel((t_point){point.coord_x + i, point.coord_y + j,
					point.color});
			j++;
		}
		i++;
	}
}

void	bresenham(t_point inital_point, t_point end_point, int thickness)
{
	float	temp_delta_x;
	float	temp_delta_y;

	temp_delta_x = end_point.coord_x - inital_point.coord_x;
	temp_delta_y = end_point.coord_y - inital_point.coord_y;
	if (fabs(temp_delta_x) > fabs(temp_delta_y))
	{
		if (inital_point.coord_x > end_point.coord_x)
			bresenham_high(end_point, inital_point, thickness);
		else
			bresenham_high(inital_point, end_point, thickness);
	}
	else
	{
		if (inital_point.coord_y > end_point.coord_y)
			bresenham_low(end_point, inital_point, thickness);
		else
			bresenham_low(inital_point, end_point, thickness);
	}
}

void	bresenham_high(t_point initial_point, t_point end_point, int thickness)
{
	t_bres	bres;

	init_bres(&bres, initial_point, end_point);
	bres.decision = (2 * bres.delta_y) - bres.delta_x;
	while (bres.initial_x <= end_point.coord_x)
	{
		plot_thick_pixel((t_point){bres.initial_x, bres.initial_y,
			initial_point.color}, thickness);
		if (bres.decision > 0)
		{
			bres.initial_y += bres.y_increment;
			bres.decision += (2 * (bres.delta_y - bres.delta_x));
		}
		else
			bres.decision += (2 * bres.delta_y);
		bres.initial_x++;
	}
}

void	bresenham_low(t_point initial_point, t_point end_point, int thickness)
{
	t_bres	bres;

	init_bres(&bres, initial_point, end_point);
	bres.decision = (2 * bres.delta_x) - bres.delta_y;
	while (bres.initial_y <= end_point.coord_y)
	{
		plot_thick_pixel((t_point){bres.initial_x, bres.initial_y,
			initial_point.color}, thickness);
		if (bres.decision > 0)
		{
			bres.initial_x += bres.x_increment;
			bres.decision += (2 * (bres.delta_x - bres.delta_y));
		}
		else
			bres.decision += (2 * bres.delta_x);
		bres.initial_y++;
	}
}
