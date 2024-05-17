/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:28:08 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/17 11:23:45 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	plot_thick_pixel(t_point point, int thickness)
{
	short	i;
	short	j;

	i = -thickness / 2;
	while (i <= thickness / 2)
	{
		j = -thickness / 2;
		while (j <= thickness / 2)
		{
			if ((point.x + i >= 0) && (point.y + j >= 0) && \
				(point.x + i < WINDOW_WIDTH) && \
				(point.y + j < WINDOW_HEIGHT))
			{
				mlx_put_pixel(get_mlx()->img_ptr, point.x + i, \
					point.y + j, point.color);
			}
			j++;
		}
		i++;
	}
}

void	bresenham(t_point inital_point, t_point end_point, int thickness)
{
	float	temp_delta_x;
	float	temp_delta_y;

	temp_delta_x = end_point.x - inital_point.x;
	temp_delta_y = end_point.y - inital_point.y;
	if (fabs(temp_delta_x) > fabs(temp_delta_y))
	{
		if (inital_point.x > end_point.x)
			bresenham_high(end_point, inital_point, thickness);
		else
			bresenham_high(inital_point, end_point, thickness);
	}
	else
	{
		if (inital_point.y > end_point.y)
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
	while (bres.initial_x <= end_point.x)
	{
		plot_thick_pixel((t_point){bres.initial_x, bres.initial_y, \
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
	while (bres.initial_y <= end_point.y)
	{
		plot_thick_pixel((t_point){bres.initial_x, bres.initial_y, \
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