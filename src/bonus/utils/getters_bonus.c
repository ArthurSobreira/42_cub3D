/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:14:17 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/28 12:54:43 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

t_math	*get_math(void)
{
	static t_math	math;

	return (&math);
}
