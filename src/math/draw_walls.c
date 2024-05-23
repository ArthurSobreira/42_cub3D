/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:08:43 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/23 07:35:51 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	uint32_t	texture_to_rgb(mlx_texture_t *texture, int x, int y)
{
	uint8_t	*rgb;

	rgb = &texture->pixels[(y * texture->width + x) * \
		texture->bytes_per_pixel];
	return (rgb[RED] << 24 | rgb[GREEN] << 16 | rgb[BLUE] << 8 | rgb[ALPHA]);
}

void	draw_textured_wall(t_mlx *mlx, t_wall wall, mlx_texture_t *texture)
{
	int		y_min;
	int		y_max;
	double	tex_y;
	double	inc_tex;
	double	tex_off;

	if (texture == mlx->textures[SOUTH] || \
		texture == mlx->textures[WEST])
		wall.ray_x = texture->width - 1 - wall.ray_x;
	inc_tex = (double)texture->height / wall.height;
	tex_off = 0;
	if (wall.height > WINDOW_HEIGHT)
    {
        tex_off = (wall.height - WINDOW_HEIGHT) / 2.0;
        wall.height = WINDOW_HEIGHT;
    }
	y_min = (WINDOW_HEIGHT - wall.height) / 2.0;
    y_max = (WINDOW_HEIGHT + wall.height) / 2.0;
    tex_y = tex_off * inc_tex;
	while (y_max > y_min)
	{
		if (get_core()->draw_map)
		{
			if (!is_map_pixel((t_point){wall.init, y_min, 0}))
				mlx_put_pixel(mlx->img_ptr, wall.init, y_min, \
					texture_to_rgb(texture, wall.ray_x, (int)tex_y));
		}
		else
			mlx_put_pixel(mlx->img_ptr, wall.init, y_min, \
				texture_to_rgb(texture, wall.ray_x, (int)tex_y));
		tex_y += inc_tex;
		y_min++;
	}
}

void	draw_walls(t_math *math, int current_ray)
{
	t_point		initial_point;
	t_point		final_point;
	t_wall		wall;
	double		wall_height;

	get_core()->wall_flag = TRUE;
	wall_height = (MAP_CUB * (WINDOW_WIDTH * WIDTH_INCREMENT)) / math->dist;
	if (wall_height > (WINDOW_WIDTH * WIDTH_INCREMENT))
		wall_height = (WINDOW_WIDTH * WIDTH_INCREMENT);
	initial_point.coord_x = current_ray;
	initial_point.coord_y = (WINDOW_HEIGHT * HEIGHT_INCREMENT) - \
		(wall_height * HEIGHT_INCREMENT);
	final_point.coord_x = initial_point.coord_x;
	final_point.coord_y = initial_point.coord_y + wall_height;

	wall.height = wall_height;
	wall.init = initial_point.coord_x;
	wall.ray_x = (int)((int)(math->ray_x) % MAP_CUB);
	if (is_nouth_wall(math))
		draw_textured_wall(get_mlx(), wall, get_mlx()->textures[NORTH]);
	else if (is_south_wall(math))
		draw_textured_wall(get_mlx(), wall, get_mlx()->textures[SOUTH]);
	else if (is_west_wall(math))
		draw_textured_wall(get_mlx(), wall, get_mlx()->textures[WEST]);
	else if (is_east_wall(math))
		draw_textured_wall(get_mlx(), wall, get_mlx()->textures[EAST]);
}
