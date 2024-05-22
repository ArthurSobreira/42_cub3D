/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:08:43 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/22 18:30:06 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_wall_colors(t_math *math, uint32_t *color)
{
	if (math->horz_dist < math->vert_dist)
	{
		if (get_math()->ray_ang > PI && get_math()->ray_ang < TWO_PI)
			*color = 0xff0000ff;
		else if (get_player()->angle > 0 && get_math()->ray_ang < PI)
			*color = 0x00ff00ff;
	}
	else if (math->vert_dist < math->horz_dist)
	{
		if (get_math()->ray_ang > PI_OVER_TWO && \
			get_math()->ray_ang < THREE_PI_OVER_TWO)
			*color = 0x0000ffff;
		else if (get_math()->ray_ang > THREE_PI_OVER_TWO || \
			get_math()->ray_ang < PI_OVER_TWO)
			*color = 0xffffffff;
	}
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
