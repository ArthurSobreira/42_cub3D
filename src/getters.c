/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:14:17 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/30 16:44:10 by phenriq2         ###   ########.fr       */
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
