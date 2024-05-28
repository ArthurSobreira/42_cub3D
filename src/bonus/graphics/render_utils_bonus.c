/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:13:55 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/28 12:54:08 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_direction(t_player *player)
{
	t_point	initial_point;
	t_point	end_point;
	short	thickness;

	if (!get_core()->draw_map)
		return ;
	get_core()->wall_flag = FALSE;
	thickness = 2;
	initial_point.coord_x = player->pos_x + DIRECTION_OFFSET;
	initial_point.coord_y = player->pos_y + DIRECTION_OFFSET;
	end_point.coord_x = initial_point.coord_x + \
		player->delta_x * DIRECTION_LEN;
	end_point.coord_y = initial_point.coord_y + \
		player->delta_y * DIRECTION_LEN;
	initial_point.color = COLOR_DIRECTION;
	end_point.color = COLOR_DIRECTION;
	bresenham(initial_point, end_point, thickness);
}

void	draw_background(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				plot_pixel(mlx, x, y, mlx->ceil_color);
			else
				plot_pixel(mlx, x, y, mlx->floor_color);
			++x;
		}
		++y;
	}
}

void	draw_minimap(t_mlx *mlx)
{
	char	**map;
	int		x;
	int		y;

	if (!get_core()->draw_map)
		return ;
	map = get_map()->map_str;
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(mlx, x * MAP_CUB, y * MAP_CUB, COLOR_WALL);
			else
				draw_square(mlx, x * MAP_CUB, y * MAP_CUB, COLOR_FLOOR);
			++x;
		}
		++y;
	}
	get_map()->limit_x = x * MAP_CUB;
	get_map()->limit_y = y * MAP_CUB;
}

void	draw_player(int x, int y, uint32_t color)
{
	int	i;
	int	j;

	if (!get_core()->draw_map)
		return ;
	i = 0;
	while (i <= 7)
	{
		j = 0;
		while (j <= 7)
		{
			if (i == 0 || i == 7 || j == 0 || j == 7)
				plot_pixel(get_mlx(), x + i, y + j, COLOR_BORDER);
			else
				plot_pixel(get_mlx(), x + i, y + j, color);
			++j;
		}
		++i;
	}
}

void	draw_square(t_mlx *mlx, int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= MAP_CUB)
	{
		j = 0;
		while (j <= MAP_CUB)
		{
			if ((color == COLOR_WALL) && \
				(i == 0 || i == MAP_CUB || j == 0 || j == MAP_CUB))
				plot_pixel(mlx, x + i, y + j, COLOR_BORDER);
			else
				plot_pixel(mlx, x + i, y + j, color);
			++j;
		}
		++i;
	}
}
