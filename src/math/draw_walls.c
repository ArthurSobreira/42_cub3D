/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:08:43 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/22 19:25:00 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_wall_colors(t_math *math, uint32_t *color)
{
	if (is_nouth_wall(math))
		*color = 0xff0000ff;
	else if (is_south_wall(math))
		*color = 0x00ff00ff;
	else if (is_west_wall(math))
		*color = 0x0000ffff;
	else if (is_east_wall(math))
		*color = 0xffffffff;
}

void	draw_walls(t_math *math, int current_ray)
{
	t_point		initial_point;
	t_point		final_point;
	double		wall_height;

	get_core()->wall_flag = TRUE;
	wall_height = (MAP_CUB * (WINDOW_WIDTH * WIDTH_INCREMENT)) / math->dist;
	if (wall_height > (WINDOW_WIDTH * WIDTH_INCREMENT))
		wall_height = (WINDOW_WIDTH * WIDTH_INCREMENT);
	initial_point.coord_x = current_ray ;
	initial_point.coord_y = (WINDOW_HEIGHT * HEIGHT_INCREMENT) - \
		(wall_height * HEIGHT_INCREMENT);
	final_point.coord_x = initial_point.coord_x;
	final_point.coord_y = initial_point.coord_y + wall_height;
	handle_wall_colors(math, &initial_point.color);
	bresenham(initial_point, final_point, 1);
}
