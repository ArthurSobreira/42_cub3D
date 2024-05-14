/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:31:13 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/14 13:22:06 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->win_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, 0);
	if (!mlx->win_ptr)
		ft_error(ERROR_MLX_INIT);
	mlx->textures[NORTH] = mlx_load_png(get_core()->parser_infos[NORTH]);
	mlx->textures[SOUTH] = mlx_load_png(get_core()->parser_infos[SOUTH]);
	mlx->textures[WEST] = mlx_load_png(get_core()->parser_infos[WEST]);
	mlx->textures[EAST] = mlx_load_png(get_core()->parser_infos[EAST]);
	if (!mlx->textures[NORTH] || !mlx->textures[SOUTH] || \
		!mlx->textures[WEST] || !mlx->textures[EAST])
		ft_error(ERROR_TEXTURE_INIT);
	mlx->img_ptr = mlx_new_image(mlx->win_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->img_ptr)
		ft_error(ERROR_MLX_INIT);
	get_color(mlx, CEIL);
	get_color(mlx, FLOOR);
	return (mlx);
}

void	get_color(t_mlx *mlx, t_colors identifier)
{
	char	**splited_color;
	char	*r;
	char	*g;
	char	*b;

	if (identifier == FLOOR)
		splited_color = ft_split(get_core()->parser_infos[FLOOR], ',');
	else
		splited_color = ft_split(get_core()->parser_infos[CEIL], ',');
	if (!splited_color[0] || !splited_color[1] || !splited_color[2])
		ft_error(ERROR_INVALID_COLOR);
	r = splited_color[0];
	g = splited_color[1];
	b = splited_color[2];
	if (identifier == FLOOR)
		mlx->floor_color = create_rgb(r, g, b);
	else
		mlx->ceil_color = create_rgb(r, g, b);
	ft_free_matrix(splited_color);
}

uint32_t	create_rgb(char *r, char *g, char *b)
{
	uint32_t	rgb;

	rgb = 0b0;
	rgb |= ft_atoi(r) << 24;
	rgb |= ft_atoi(g) << 16;
	rgb |= ft_atoi(b) << 8;
	rgb |= 0b11111111;
	return (rgb);
}
