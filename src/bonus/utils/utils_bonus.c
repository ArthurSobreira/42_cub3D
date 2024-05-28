/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:07 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/28 18:47:15 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_cub(t_cub3d *core, char *argv[])
{
	core->get_parser_infos = get_parser_infos;
	core->map_builder = map_builder;
	core->init_player = init_player;
	core->mlx_process = mlx_process;
	core->clear_all = clear_all;
	core->map_path = argv[1];
	core->texture_count = 0;
	core->color_count = 0;
	core->reload = FALSE;
	core->draw_rays = FALSE;
	core->draw_map = TRUE;
	core->map_flag = TRUE;
	core->wall_flag = FALSE;
	core->bad_flag = FALSE;
}

void	init_axis(t_math *math, t_player *player, t_axis axis)
{
	math->collision = FALSE;
	if (axis == HORIZONTAL)
	{
		math->horz_dist = DBL_MAX;
		math->atan = -1 / tan(math->ray_ang);
		math->horz_x = player->pos_x;
		math->horz_y = player->pos_y;
	}
	else if (axis == VERTICAL)
	{
		math->vert_dist = DBL_MAX;
		math->ntan = -tan(math->ray_ang);
		math->vert_x = player->pos_x;
		math->vert_y = player->pos_y;
	}
}

t_bool	is_map_pixel(t_point point)
{
	if (get_core()->wall_flag)
	{
		if (point.coord_x >= 0 && \
			point.coord_x <= get_map()->limit_x && \
			point.coord_y >= 0 && \
			point.coord_y <= get_map()->limit_y)
			return (TRUE);
	}
	return (FALSE);
}

void	ft_error(char *msg)
{
	t_cub3d	*core;

	core = get_core();
	if (!core->bad_flag)
		ft_putstr_fd(msg, STDERR_FILENO);
	core->bad_flag = TRUE;
	clear_all();
	exit(EXIT_FAILURE);
}
