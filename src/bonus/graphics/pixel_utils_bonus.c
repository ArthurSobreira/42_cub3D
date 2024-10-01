/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:09:18 by arsobrei          #+#    #+#             */
/*   Updated: 2024/10/01 17:25:48 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	plot_pixel(t_mlx *mlx, int x, int y, uint32_t color)
{
	if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))
		mlx_put_pixel(mlx->img_ptr, x, y, color);
}

void	plot_pixel_outside_map(t_point point)
{
	if (get_core()->draw_map)
	{
		if (!is_map_pixel((t_point){point.coord_x, point.coord_y, 0}))
			plot_pixel(get_mlx(), point.coord_x, point.coord_y, point.color);
	}
	else
		plot_pixel(get_mlx(), point.coord_x, point.coord_y, point.color);
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
				plot_pixel_outside_map((t_point){point.coord_x + i, \
					point.coord_y + j, point.color});
			j++;
		}
		i++;
	}
}
