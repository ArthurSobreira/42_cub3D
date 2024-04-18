/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:57:59 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/18 11:23:47 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_max_x(size_t x)
{
	t_map	*map;

	map = get_map();
	map->max_x = x;
}

void	set_max_y(size_t y)
{
	t_map	*map;

	map = get_map();
	map->max_y = y;
}
