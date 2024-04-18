/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:15:44 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/18 11:39:17 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	constructor_map(void)
{
	get_map()->map_str = NULL;
	get_map()->max_x = 0;
	get_map()->max_y = 0;
	get_map()->set_max_x = &set_max_x;
	get_map()->set_max_y = &set_max_y;
}
