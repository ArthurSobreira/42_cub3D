/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:27 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 12:42:13 by arsobrei         ###   ########.fr       */
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
			if (i == 0 || i == 7 || j == 0 || j == 7)
				mlx_put_pixel(get_mlx()->img_ptr, x + i, y + j, COLOR_BORDER);
			else
				mlx_put_pixel(get_mlx()->img_ptr, x + i, y + j, color);
			++j;
		}
		++i;
	}
}

void	draw_direction(int x, int y, uint32_t color)
{
	t_player	*player;
	double	dist_x;
	double	dist_y;
	double	step;

	printf("DDELTA_X: %lf\nDELTA_Y: %lf\nANGULO: %lf\n\n",
		get_player()->delta_x, get_player()->delta_y, get_player()->angle);
	player = get_player();
	dist_x = player->delta_x * MAP_CUB;
	dist_y = player->delta_y * MAP_CUB;
	if (fabs(dist_x) > fabs(dist_y))
		step = fabs(dist_x);
	else
		step = fabs(dist_y);
	dist_x /= step;
	dist_y /= step;
	while ((int)step--)
	{
		if (x < 0 || y < 0)
			break ;
		mlx_put_pixel(get_mlx()->img_ptr, x, y, color);
		x += dist_x;
		y += dist_y;
	}
}

void	render(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	render_background(mlx);
	draw_minimap(mlx);
	// draw_direction(get_player()->pos_x + 4, get_player()->pos_y + 4, COLOR_PLAYER);
	draw_player(get_player()->pos_x, get_player()->pos_y, COLOR_PLAYER);
}
