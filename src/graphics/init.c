/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:31:13 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 12:26:16 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
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
	init_player();
	return (mlx);
}

void	init_player(void)
{
	set_player_direction();
	get_player()->delta_x = cos(get_player()->angle);
	get_player()->delta_y = sin(get_player()->angle);
	if (get_player()->direction == 'N')
		get_player()->angle = PI_270;
	else if (get_player()->direction == 'S')
		get_player()->angle = HALF_PI;
	else if (get_player()->direction == 'W')
		get_player()->angle = TWO_PI;
	else if (get_player()->direction == 'E')
		get_player()->angle = 0;
}
