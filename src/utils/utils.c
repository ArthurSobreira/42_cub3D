/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:07 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/20 16:30:34 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	core->draw_rays = FALSE;
	core->draw_map = TRUE;
	core->map_flag = TRUE;
	core->bad_flag = FALSE;
}

void	ft_error(char *msg)
{
	t_cub3d	*core;

	core = get_core();
	if (!core->bad_flag)
		ft_putstr_fd(msg, STDERR_FILENO);
	clear_all();
	exit(EXIT_FAILURE);
}
