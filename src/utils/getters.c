/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:14:17 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/15 13:58:34 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*get_map(void)
{
	static t_map	core;

	return (&core);
}

t_cub3d	*get_core(void)
{
	static t_cub3d	core;

	return (&core);
}

t_mlx	*get_mlx(void)
{
	static t_mlx	core;

	return (&core);
}

t_player	*get_player(void)
{
	static t_player	core;

	return (&core);
}
