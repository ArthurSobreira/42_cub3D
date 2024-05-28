/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:08:43 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/28 12:40:12 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static uint32_t	texture_to_rgb(mlx_texture_t *texture, int x, int y)
{
	uint8_t	*rgb;

	rgb = &texture->pixels[(y * texture->width + x) * \
						texture->bytes_per_pixel];
	return (rgb[RED] << 24 | rgb[GREEN] << 16 | rgb[BLUE] << 8 | rgb[ALPHA]);
}

void	apply_wall_texture(t_mlx *mlx, t_wall wall, mlx_texture_t *texture)
{
	double	inc_tex;
	double	tex_off;
	double	tex_y;
	int		y_min;
	int		y_max;

	if (texture == mlx->textures[SOUTH] || texture == mlx->textures[WEST])
		wall.ray_x = (texture->width - 1) - wall.ray_x;
	inc_tex = (texture->height / wall.height) * 0.5;
	tex_off = 0;
	if (wall.height > HEIGHT_2)
	{
		tex_off = wall.height - HEIGHT_2;
		wall.height = HEIGHT_2;
	}
	y_min = HEIGHT_2 - wall.height;
	y_max = HEIGHT_2 + wall.height;
	tex_y = tex_off * inc_tex;
	while (y_max > y_min)
	{
		plot_pixel_outside_map((t_point){wall.init, y_min, \
			texture_to_rgb(texture, wall.ray_x, (int)tex_y)});
		tex_y += inc_tex;
		y_min++;
	}
}

void	draw_walls(t_math *math, int current_ray)
{
	mlx_texture_t	*texture;
	t_wall			wall;
	double			wall_height;

	texture = NULL;
	get_core()->wall_flag = TRUE;
	wall_height = (MAP_CUB * (WINDOW_WIDTH * WIDTH_INCREMENT)) / math->dist;
	if (is_nouth_wall(math))
		texture = get_mlx()->textures[NORTH];
	else if (is_south_wall(math))
		texture = get_mlx()->textures[SOUTH];
	else if (is_west_wall(math))
		texture = get_mlx()->textures[WEST];
	else if (is_east_wall(math))
		texture = get_mlx()->textures[EAST];
	wall.height = wall_height;
	wall.init = current_ray;
	if (math->horz_dist < math->vert_dist)
		wall.ray_x = (int)(math->ray_x * MAP_CUB / 4) % texture->width;
	else if (math->vert_dist < math->horz_dist)
		wall.ray_x = (int)(math->ray_y * MAP_CUB / 4) % texture->width;
	apply_wall_texture(get_mlx(), wall, texture);
}
