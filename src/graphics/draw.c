/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:13:55 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 18:32:28 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				mlx_put_pixel(mlx->img_ptr, x, y, mlx->ceil_color);
			else
				mlx_put_pixel(mlx->img_ptr, x, y, mlx->floor_color);
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

	map = get_map()->map_str;
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
}

void	draw_player(int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 7)
	{
		j = 0;
		while (j <= 7)
		{
			if (i == 0 || i == 7 || j == 0 || j == 7)
				mlx_put_pixel(get_mlx()->img_ptr, x + i, y + j, COLOR_BORDER);
			else
				mlx_put_pixel(get_mlx()->img_ptr, x + i, y + j, color);
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
				mlx_put_pixel(mlx->img_ptr, x + i, y + j, COLOR_BORDER);
			else
				mlx_put_pixel(mlx->img_ptr, x + i, y + j, color);
			++j;
		}
		++i;
	}
}

void	draw_direction(t_player *player)
{
	t_point	initial_point;
	t_point	end_point;
	short	thickness;

	thickness = 2;
	initial_point.x = player->pos_x + DIRECTION_OFFSET;
	initial_point.y = player->pos_y + DIRECTION_OFFSET;
	end_point.x = initial_point.x + player->delta_x * DIRECTION_LEN;
	end_point.y = initial_point.y + player->delta_y * DIRECTION_LEN;
	initial_point.color = COLOR_BORDER;
	end_point.color = COLOR_BORDER;
	bresenham(initial_point, end_point, thickness);
}
