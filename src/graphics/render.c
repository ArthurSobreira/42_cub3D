/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/15 14:30:20 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_mlx *mlx)
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
			mlx_put_pixel(get_mlx()->img_ptr, x + i, y + j, color);
			++j;
		}
		++i;
	}
}

void	render(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	render_background(mlx);
	draw_minimap(mlx);
	draw_player(get_player()->x, get_player()->y, 0xFF0000FF);
}
