/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:31:13 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/25 05:23:30 by arsobrei         ###   ########.fr       */
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

void	load_gun_textures(t_mlx *mlx)
{
	int	index;

	mlx->gun_texture[0] = mlx_load_png(GUN_0_PATH);
	mlx->gun_texture[1] = mlx_load_png(GUN_1_PATH);
	mlx->gun_texture[2] = mlx_load_png(GUN_2_PATH);
	mlx->gun_texture[3] = mlx_load_png(GUN_3_PATH);
	if (!mlx->gun_img[0] || !mlx->gun_img[1] || \
		!mlx->gun_img[2] || !mlx->gun_img[3])
		ft_error(ERROR_TEXTURE_INIT);
	index = 0;
	while (index < 5)
	{
		mlx->gun_img[index] = mlx_texture_to_image(mlx->win_ptr, \
			mlx->gun_texture[index]);
		if (!mlx->gun_texture[index])
			ft_error(ERROR_TEXTURE_INIT);
		mlx->gun_img[index]->enabled = true;
		mlx_image_to_window(mlx->win_ptr, mlx->gun_img[index], WIDTH_2, \
			WINDOW_HEIGHT - mlx->gun_texture[index]->height);
		index++;
	}
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
	get_player()->move_w = move_w;
	get_player()->move_a = move_a;
	get_player()->move_s = move_s;
	get_player()->move_d = move_d;
	get_player()->move_left = move_left;
	get_player()->move_right = move_right;
}

void	init_bres(t_bres *bres_info, t_point initial_point, t_point end_point)
{
	bres_info->delta_x = end_point.coord_x - initial_point.coord_x;
	bres_info->delta_y = end_point.coord_y - initial_point.coord_y;
	bres_info->initial_x = initial_point.coord_x;
	bres_info->initial_y = initial_point.coord_y;
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
