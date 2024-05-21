/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:08:43 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/21 07:10:14 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_math *math, int current_ray)
{
	t_point		initial_point;
	t_point		final_point;
	double		wall_height;
	int			wall_width;

	get_core()->wall_flag = TRUE;
	wall_height = (MAP_CUB * (WINDOW_WIDTH / 1.5)) / math->dist;
	if (wall_height > (WINDOW_WIDTH / 1.5))
		wall_height = (WINDOW_WIDTH / 1.5);
	wall_width = MAP_CUB;
	initial_point.coord_x = current_ray * wall_width;
	initial_point.coord_y = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	final_point.coord_x = initial_point.coord_x;
	final_point.coord_y = initial_point.coord_y + wall_height;
	initial_point.color = COLOR_PLAYER;
	final_point.color = COLOR_PLAYER;
	bresenham(initial_point, final_point, wall_width);
}
