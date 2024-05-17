/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:31:13 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/17 11:54:31 by arsobrei         ###   ########.fr       */
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
	mlx->cursor_texture = mlx_load_png(CURSOR_PATH);
	mlx->cursor = mlx_create_cursor(mlx->cursor_texture);
	get_color(mlx, CEIL);
	get_color(mlx, FLOOR);
	return (mlx);
}

void	init_player(void)
{
	set_player_direction();
	if (get_player()->direction == 'N')
		get_player()->angle = THREE_PI_OVER_TWO;
	else if (get_player()->direction == 'S')
		get_player()->angle = PI_OVER_TWO;
	else if (get_player()->direction == 'W')
		get_player()->angle = PI;
	else if (get_player()->direction == 'E')
		get_player()->angle = TWO_PI;
	get_player()->delta_x = cos(get_player()->angle);
	get_player()->delta_y = sin(get_player()->angle);
}

void	init_bres(t_bres *bres_info, t_point initial_point, t_point end_point)
{
	bres_info->delta_x = end_point.x - initial_point.x;
	bres_info->delta_y = end_point.y - initial_point.y;
	bres_info->initial_x = initial_point.x;
	bres_info->initial_y = initial_point.y;
	bres_info->x_increment = 1;
	bres_info->y_increment = 1;
	bres_info->decision = 0;
	if (bres_info->delta_y < 0)
	{
		bres_info->y_increment = -1;
		bres_info->delta_y = fabs(bres_info->delta_y);
	}
	if (bres_info->delta_x < 0)
	{
		bres_info->x_increment = -1;
		bres_info->delta_x = fabs(bres_info->delta_x);
	}
}
