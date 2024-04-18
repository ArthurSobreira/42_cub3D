/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:34:24 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/18 16:05:46 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_with_spaces(void)
{
	t_map	*map;
	int		i;
	int		j;

	map = get_map();
	i = 0;
	while (i < map->max_y)
	{
		j = ft_strlen(map->map_str[i]);
		printf("maxcol: %d\n", j);
		while (j < map->max_x - 1)
		{
			map->map_str[i][j] = ' ';
			printf("i: %d, j: %d c:[%c]\n", i, j, map->map_str[i][j]);
			j++;
		}
		map->map_str[i][maxcol()] = '\0';
		i++;
	}
}
