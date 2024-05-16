/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:14:17 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:58 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*get_map(void)
{
	static t_map	map;

	return (&map);
}

t_cub3d	*get_core(void)
{
	static t_cub3d	core;

	return (&core);
}

t_mlx	*get_mlx(void)
{
	static t_mlx	mlx;

	return (&mlx);
}

t_player	*get_player(void)
{
	static t_player	player;

	return (&player);
}
